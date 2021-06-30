"""
		///
		/// \file BMSState.py
		///
		/// \brief AUTOGENERATED FILE! ONLY EDIT IF YOU ARE A MACHINE!
		///
		/// \core 700069e8da8284b565fc6f7fa52f563fd0d81fcf
		///
		/// \build dc0bdff105b62790206f5bbc9db0de68ea6fb403
		///
		/// \date 2020-08-19 10:28:50
		///
		/// \author Dephy, Inc.
		"""
from ctypes import Structure, c_int

class BMSState(Structure):
	_pack_ = 1
	_fields_ = [
		("bms_state_0", c_int),
		("id", c_int),
		("state_time", c_int),
		("cells_0_mv", c_int),
		("cells_1_mv", c_int),
		("cells_2_mv", c_int),
		("cells_3_mv", c_int),
		("cells_4_mv", c_int),
		("cells_5_mv", c_int),
		("cells_6_mv", c_int),
		("cells_7_mv", c_int),
		("cells_8_mv", c_int),
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
		("genvar_0_", c_int),
		("genvar_1_", c_int),
		("SystemTime", c_int)]
