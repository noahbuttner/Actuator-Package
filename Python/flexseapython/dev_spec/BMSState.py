"""
Please note that this file is generated by a script!
Please do not make any changes to this file!
"""
from ctypes import Structure, c_int

class BMSState(Structure):
	_pack_ = 1
	_fields_ = [
		("bms_state_0", c_int),
		("id", c_int),
		("state_time", c_int),
		("cells[0].mV", c_int),
		("cells[1].mV", c_int),
		("cells[2].mV", c_int),
		("cells[3].mV", c_int),
		("cells[4].mV", c_int),
		("cells[5].mV", c_int),
		("cells[6].mV", c_int),
		("cells[7].mV", c_int),
		("cells[8].mV", c_int),
		("bms_state", c_int),
		("error", c_int),
		("current", c_int),
		("stack_voltage", c_int),
		("temperature_0", c_int),
		("temperature_1", c_int),
		("temperature_2", c_int),
		("pack_imbalance", c_int),
		("balancing", c_int),
		("timer", c_int),
		("user_interface", c_int),
		("bq_sys_stat", c_int),
		("bq_sys_ctrl1", c_int),
		("bq_sys_ctrl2", c_int),
		("fw_version", c_int),
		("genVar[0]", c_int),
		("genVar[1]", c_int),
		("SystemTime", c_int)]