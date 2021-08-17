#!/usr/bin/env python3

"""
FlexSEA Bootloader check demo
"""
import sys
from time import sleep
from flexsea import fxEnums as fxe
from flexsea import flexsea as flex


def bootloader(fxs, port, baud_rate, target="Mn", timeout=60):
	"""Check bootloader in target"""
	debug_logging_level = 0  # 6 is least verbose, 0 is most verbose
	dev_id = fxs.open(port, baud_rate, debug_logging_level)
	app_type = fxs.get_app_type(dev_id)
	result = 1

	targets = {
		"Habs": {"id": 0, "name": "Habsolute"},
		"Reg": {"id": 1, "name": "Regulate"},
		"Exe": {"id": 2, "name": "Execute"},
		"Mn": {"id": 3, "name": "Manage"},
		"BT121": {"id": 4, "name": "Bluetooth"},
		"XBee": {"id": 5, "name": "XBee"},
	}

	if app_type.value == fxe.FX_ACT_PACK.value:
		app_name = "ActPack"
	elif app_type.value == fxe.FX_EB5X.value:
		app_name = "Exo or ActPack Plus"
	else:
		raise RuntimeError(f"Unsupported application type: {app_type.value}")

	print(f"Your device is an {app_name}", flush=True)

	try:
		print(f"Activating {targets[target]['name']} bootloader", flush=True)
		sleep(1)
		state = fxe.FX_FAILURE
		while timeout > 0 and state != fxe.FX_SUCCESS:
			if timeout % 5 == 0:
				print("Sending signal to target device", flush=True)
				fxs.activate_bootloader(dev_id, targets[target]["id"])
			print(f"Waiting for response from target ({timeout}s)", flush=True)
			sleep(1)
			timeout -= 1
			state = fxs.is_bootloader_activated(dev_id)

		if state == fxe.FX_SUCCESS:
			result = 0
			print(f"{targets[target]['name']} bootloader is activated", flush=True)
		else:
			print(f"Unable to activate {targets[target]['name']} bootloader", flush=True)

	except IOError:
		pass
	except ValueError as err:
		raise RuntimeError(f"Failed to communicate with device {target}:\n{err}") from err
	except KeyError as err:
		raise RuntimeError(f"Unsupported bootloader target: {target}") from err
	except Exception as err:
		raise RuntimeError(f"unexpected error of type {type(err).__name__}: {err}")

	fxs.close(dev_id)
	return result


def main():
	"""
	Standalone bootloader check execution
	"""
	# pylint: disable=import-outside-toplevel
	import argparse

	parser = argparse.ArgumentParser(description=__doc__)
	parser.add_argument(
		"port", metavar="Port", type=str, nargs=1, help="Your device serial port."
	)
	parser.add_argument(
		"-b",
		"--baud",
		metavar="B",
		dest="baud_rate",
		type=int,
		default=230400,
		help="Serial communication baud rate.",
	)

	parser.add_argument(
		"-t",
		"--target",
		metavar="T",
		dest="target",
		type=str,
		default="Mn",
		choices=["Habs", "Mn", "Reg", "Exe", "BT121", "XBee"],
		help="Target microcontroller",
	)

	parser.add_argument(
		"-d",
		"--delay",
		metavar="D",
		dest="delay",
		type=int,
		default=60,
		help="Timeout delay",
	)
	args = parser.parse_args()
	try:
		return bootloader(
			flex.FlexSEA(), args.port[0], args.baud_rate, args.target, timeout=args.delay
		)
	except RuntimeError as err:
		print(f"Problem encountered when bootloading: {err}")
		return 1


if __name__ == "__main__":
	sys.exit(main())
