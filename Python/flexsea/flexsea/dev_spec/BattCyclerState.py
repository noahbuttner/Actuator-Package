"""/*
 * BattCyclerState.py
 *
 * AUTOGENERATED FILE! ONLY EDIT IF YOU ARE A MACHINE!
 * CORE:212025bb4b51c1128ab9b5abcafc41c674e5b9a1
 * BUILD:9a735def144090fd0dd624cf143864167b63ebcf
 *
 *
 * Specification File Created on: 2020-09-28 18:37:52
 * Author: Dephy, Inc.
 *
 */
"""
from ctypes import Structure, c_int

class BattCyclerState(Structure):
	_pack_ = 1
	_fields_ = [
		("battcycler", c_int),
		("id", c_int),
		("state_time", c_int),
		("current", c_int),
		("voltage", c_int),
		("esr", c_int),
		("fsm_state", c_int),
		("button", c_int),
		("leds", c_int),
		("genvar_0", c_int),
		("genvar_1", c_int),
		("genvar_2", c_int),
		("genvar_3", c_int),
		("status", c_int),
		("test_in_progress_now", c_int),
		("last_completed_test", c_int),
		("result_of_last_test", c_int),
		("time_elapsed_in_test", c_int),
		("error_codes", c_int),
		("charge_discharge_cycles_completed", c_int),
		("charge_discharge_total_cycles", c_int),
		("desired_battery_current", c_int),
		("SystemTime", c_int)]
