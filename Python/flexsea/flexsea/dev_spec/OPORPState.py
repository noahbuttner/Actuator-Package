"""
///
/// @file OPORPState.py
///
/// @brief AUTOGENERATED FILE! ONLY EDIT IF YOU ARE A MACHINE!
///
/// @core 74241a4e7f529cbe716fbf2f07f38d764e834b79
///
/// @build af1ba76062f57493183dea14df2f96475968bc7b
///
/// @date 2021-05-10 10:03:07
///
/// @author Dephy, Inc.
"""
from ctypes import Structure, c_int

class OPORPState(Structure):
	_pack_ = 1
	_fields_ = [
		("rigid", c_int),
		("id", c_int),
		("state_time", c_int),
		("accelx", c_int),
		("accely", c_int),
		("accelz", c_int),
		("gyrox", c_int),
		("gyroy", c_int),
		("gyroz", c_int),
		("mot_ang", c_int),
		("mot_vel", c_int),
		("mot_acc", c_int),
		("mot_cur", c_int),
		("mot_volt", c_int),
		("batt_volt", c_int),
		("batt_curr", c_int),
		("temperature", c_int),
		("status_mn", c_int),
		("status_ex", c_int),
		("status_re", c_int),
		("genvar_0", c_int),
		("genvar_1", c_int),
		("genvar_2", c_int),
		("genvar_3", c_int),
		("genvar_4", c_int),
		("genvar_5", c_int),
		("genvar_6", c_int),
		("genvar_7", c_int),
		("genvar_8", c_int),
		("genvar_9", c_int),
		("ank_ang", c_int),
		("ank_vel", c_int),
		("SystemTime", c_int)]
