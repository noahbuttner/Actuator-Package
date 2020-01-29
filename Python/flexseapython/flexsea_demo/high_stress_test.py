import os, sys, math
from time import sleep, time, strftime
from enum import Enum
import numpy as np
import matplotlib.pyplot as plt
#Next two lines are used to plot in a browser:
import matplotlib
matplotlib.use('WebAgg')

pardir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
print(pardir)
sys.path.append(pardir)
from fxUtil import *

# Controller type to send to controller
class Controller(Enum):
	position = 1
	current = 2

# Signal type to send to controller
class signal(Enum):
	sine = 1
	line = 2

# Generate a sine wave of a specific amplitude and frequency
def sinGenerator(amplitude, frequency, commandFreq):
	num_samples = commandFreq / frequency
	print("number of samples is: ", num_samples)
	in_array = np.linspace(-np.pi, np.pi, num_samples)
	sin_vals = amplitude * np.sin(in_array)
	return sin_vals

# Set the device(s) for current control
def setCurrentCtrl(devId0, devId1, secondDevice):
	fxSetGains(devId0, 300, 50, 0, 0, 0)
	if (secondDevice):
		fxSetGains(devId1, 300, 50, 0, 0, 0)

# Set the device(s) for position control
def setPositionCtrl(devId0, devId1, secondDevice):
	fxSetGains(devId0, 300, 50, 0, 0, 0)
	if (secondDevice):
		fxSetGains(devId1, 300, 50, 0, 0, 0)

# Port: port with outgoing serial connection to ActPack
# Baud Rate : baud rate of outgoing serial connection to ActPack
# Command Freq: Desired frequency of issuing commands to controller, actual 
#	command frequency will be slower due to OS overhead.
# positionAmplitude: amplitude (in ticks), position controller
# currentAmplitude: amplitude (in mA), current controller
# positionFreq: frequency (Hz) of the sine wave, position controller
# currentFreq: frequency (Hz) of the sine wave, current controller
# Number of Loops: Number of times to send desired signal to controller
def fxHighStressTest(port0, baudRate, port1 = "", commandFreq = 1000, positionAmplitude = 10000, currentAmplitude = 1000, positionFreq = 1, currentFreq = 5, numberOfLoops = 5):

	########### One vs two devices ############
	secondDevice = False
	if (port1 != ""):
		secondDevice = True

	if (secondDevice):
		print("Running high stress test with two devices")
	else:
		print("Running high stress test with one device")

	########### Debug & Data Logging ############
	debugLoggingLevel = 0 # 6 is least verbose, 0 is most verbose
	dataLog = False # Data log logs device data

	delay_time = float(1/(float(commandFreq)))
	print(delay_time)

	########### Open the device(s) and start streaming ############
	devId0 = fxOpen(port0, baudRate, debugLoggingLevel) 
	fxStartStreaming(devId0, commandFreq, dataLog)
	print('Connected to device with ID ',devId0)

	devId1 = -1
	if (secondDevice):
		devId1 = fxOpen(port1, baudRate, debugLoggingLevel) 
		fxStartStreaming(devId1, commandFreq, dataLog)
		print('Connected to device with ID ',devId1)

	############# Main Code ############
	######## Make your changes here #########

	# Get initial position:
	print('Reading initial position...')
	
	# Give the device time to consume the startStreaming command and start streaming
	sleep(0.1)

	data = fxReadDevice(devId0)
	initialPos0 = data.encoderAngle

	initialPos1 = 0
	if (secondDevice):
		data = fxReadDevice(devId1)
		initialPos1 = data.encoderAngle
	
	# Generate control profiles
	print('Command table #1 - Position Sine:')
	positionSamples = sinGenerator(positionAmplitude, positionFreq, commandFreq)
	print(np.int64(positionSamples))
	print('Command table #2 - Current Sine:')
	currentSamples = sinGenerator(currentAmplitude, currentFreq, commandFreq)
	print(np.int64(currentSamples))
	
	# Initialize lists
	currentRequests = []
	positionRequests = []
	currentMeasurements0 = []
	positionMeasurements0 = []
	currentMeasurements1 = []
	positionMeasurements1 = []
	times = []
	cycleStopTimes = []
	i = 0
	t0 = 0

	# Record start time of experiment
	t0 = time()
	for reps in range(0, numberOfLoops):
		
		print("")
		print("Rep #",reps,"out of",numberOfLoops)
		print("-------------------")
		
		# Step 0: set position controller
		# -------------------------------
		print("Step 0: set position controller")
		setPositionCtrl(devId0, devId1, secondDevice)
		
		# Step 1: position sine wave
		# --------------------------
		print("Step 1: track position sine wave")
		for sample in positionSamples:

			sleep(delay_time)

			# set controller to the next sample
			# read ActPack data
			data0 = fxReadDevice(devId0)
			if (secondDevice):
				data1 = fxReadDevice(devId1)

			# Position setpoint:
			fxSendMotorCommand(devId0, FxPosition, sample + initialPos0)
			currentMeasurements0.append(data0.motorCurrent)
			positionMeasurements0.append(data0.encoderAngle - initialPos0)
			if (secondDevice):
				fxSendMotorCommand(devId1, FxPosition, sample + initialPos1)
				currentMeasurements1.append(data1.motorCurrent)
				positionMeasurements1.append(data1.encoderAngle - initialPos1)

			times.append(time() - t0)
			currentRequests.append(0)
			positionRequests.append(sample)
			i = i + 1

		# Step 2: set current controller
		# -------------------------------
		print("Step 2: set current controller")
		setPositionCtrl(devId0, devId1, secondDevice)
		
		# Step 3: current setpoint
		# --------------------------
		print("Step 3: track current sine wave")
		for sample in currentSamples:

			sleep(delay_time)

			# set controller to the next sample
			# read ActPack data
			data0 = fxReadDevice(devId0)
			if (secondDevice):
				data1 = fxReadDevice(devId1)

			# Position setpoint:
			fxSendMotorCommand(devId0, FxCurrent, sample)
			currentMeasurements0.append(data0.motorCurrent)
			positionMeasurements0.append(data0.encoderAngle - initialPos0)
			if (secondDevice):
				fxSendMotorCommand(devId1, FxCurrent, sample)
				currentMeasurements1.append(data1.motorCurrent)
				positionMeasurements1.append(data1.encoderAngle - initialPos1)

			times.append(time() - t0)
			currentRequests.append(sample)
			positionRequests.append(0)
			i = i + 1
			
		# We'll draw a line at the end of every period
		cycleStopTimes.append(time() - t0)
		elapsed_time = time() - t0

	fxClose(devId0)
	fxClose(devId1)

	######## Stats: #########
	
	print("")
	print("Final Stats:")
	print("------------")
	actual_period = cycleStopTimes[0]
	command_frequency = i / elapsed_time
	print("Number of commands sent: " + str(i))
	print("Total time (s): " + str(elapsed_time))
	print("Requested command frequency: "+"{:.2f}".format(commandFreq))
	print("Actual command frequency (Hz): "+"{:.2f}".format(command_frequency))
	print("")
	
	######## End of Main Code #########

	######## Plotting Code, you can edit this ##################

	# Current Plot:
	plt.figure(1)
	title = "Motor Current"
	plt.plot(times, currentRequests, color = 'b', label = 'desired current')
	plt.plot(times, currentMeasurements0, color = 'r', label = 'measured current')
	plt.xlabel("Time (s)")
	plt.ylabel("Motor current (mA)")
	plt.title(title)

	plt.legend(loc='upper right')

	# Draw a vertical line at the end of each cycle
	for endpoints in cycleStopTimes:
		plt.axvline(x=endpoints)

	# Position Plot:
	plt.figure(2)
	title = "Motor Position"
	plt.plot(times, positionRequests, color = 'b', label = 'desired position')
	plt.plot(times, positionMeasurements0, color = 'r', label = 'measured position')
	plt.xlabel("Time (s)")
	plt.ylabel("Encoder position")
	plt.title(title)

	plt.legend(loc='upper right')

	# Draw a vertical line at the end of each cycle
	for endpoints in cycleStopTimes:
		plt.axvline(x=endpoints)

	# #######
	# *** ToDo: add plotting for 2nd device here ***
	# #######
	
	plt.show()

if __name__ == '__main__':
	baudRate = sys.argv[1]
	ports = sys.argv[2:3]
	try:
		fxHighStressTest(ports, baudRate)
	except Exception as e:
		print("broke: " + str(e))
