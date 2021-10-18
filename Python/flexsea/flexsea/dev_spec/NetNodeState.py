"""
///
/// @file NetNodeState.py
///
/// @brief AUTOGENERATED FILE! ONLY EDIT IF YOU ARE A MACHINE!
///
/// @core 957ee33443de77e548df6927a8dab75747b12888
///
/// @build fb8c2409d776759b5191b6bacaabe51a49ade1cf
///
/// @date 2020-06-22 14:42:45
///
/// @author Dephy, Inc.
"""
from ctypes import Structure, c_int

class NetNodeState(Structure):
	_pack_ = 1
	_fields_ = [
		("netnode", c_int),
		("id", c_int),
		("state_time", c_int),
		("genvar_0", c_int),
		("genvar_1", c_int),
		("genvar_2", c_int),
		("genvar_3", c_int),
		("status", c_int),
		("SystemTime", c_int)]
