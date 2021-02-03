"""/*
 * CellScreenerState.py
 *
 * AUTOGENERATED FILE! ONLY EDIT IF YOU ARE A MACHINE!
 * CORE:20640c2cc4ad040eed2aa76191f709854fc1595e
 * BUILD:afcc40f56e2a3c3254f831a89e0eab9db3660ba5
 *
 *
 * Specification File Created on: 2020-10-14 16:43:39
 * Author: Dephy, Inc.
 *
 */
"""
from ctypes import Structure, c_int

class CellScreenerState(Structure):
	_pack_ = 1
	_fields_ = [
		("cellscreener", c_int),
		("id", c_int),
		("state_time", c_int),
		("current", c_int),
		("voltage", c_int),
		("fsm_state", c_int),
		("button", c_int),
		("leds", c_int),
		("genvar_0", c_int),
		("genvar_1", c_int),
		("genvar_2", c_int),
		("genvar_3", c_int),
		("status", c_int),
		("p_timestamp", c_int),
		("p_current", c_int),
		("p_open_voltage", c_int),
		("p_voltage", c_int),
		("p_dv", c_int),
		("p_esr", c_int),
		("p_bin", c_int),
		("SystemTime", c_int)]