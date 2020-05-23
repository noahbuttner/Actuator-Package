#ifndef ACTPACK_STRUCT_H
#define ACTPACK_STRUCT_H

/*
 * actpack_struct.h
 *
 * AUTOGENERATED FILE! ONLY EDIT IF YOU ARE A MACHINE!
 *
 * Created on: 2020-05-22 22:52:00.766471
 * Author: Dephy, Inc.
 *
 */

#include "ActPack_device_spec.h"
#include <stdio.h> 
#include <time.h> 
#include <string.h> 
#include <stdint.h> 

#define ACTPACK_SYSTEM_TIME_POS 32
#define ACTPACK_STRUCT_DEVICE_FIELD_COUNT 33
#define ACTPACK_LABEL_MAX_CHAR_LENGTH 12

//This is The Device fields*10 + deviceField+1. Ten is the max string length of 2^32 in decimal separated from commas
#define ACTPACK_DATA_STRING_LENGTH 364

#ifdef __cplusplus
extern "C"
{
#endif

struct ActPackState
{
	int rigid;
	int id;
	int state_time;
	int accelx;
	int accely;
	int accelz;
	int gyrox;
	int gyroy;
	int gyroz;
	int mot_ang;
	int mot_vel;
	int mot_acc;
	int mot_cur;
	int mot_volt;
	int batt_volt;
	int batt_curr;
	int temperature;
	int status_mn;
	int status_ex;
	int status_re;
	int genvar_0;
	int genvar_1;
	int genvar_2;
	int genvar_3;
	int genvar_4;
	int genvar_5;
	int genvar_6;
	int genvar_7;
	int genvar_8;
	int genvar_9;
	int ank_ang;
	int ank_vel;
	//the system time
	clock_t systemTime;
	uint32_t deviceData[ACTPACK_STRUCT_DEVICE_FIELD_COUNT];
};

/// \brief Assigns the data in the buffer to the correct struct parameters
///
///@param ActPack is the struct with the data to be set
///
///@param _deviceStateBuffer is the buffer containing the data to be assigned to the struct
///
///@param systemStartTime the time the system started. If unknown, use 0.
///
void ActPackSetData(struct ActPackState *actpack, uint32_t _deviceStateBuffer[], clock_t systemStartTime);

/// \brief takes all data and places it into single, comma separated string
///
///@param ActPack is the struct with the data to be placed in the string
///
///@param dataString is where the new string wll be placed 
///
void ActPackDataToString(struct ActPackState *actpack, char dataString[ACTPACK_DATA_STRING_LENGTH]);

/// \brief retrieves the string equivalent of all parameter names
///
///@param labels is the array of labels containing the parameter names
///
void ActPackGetLabels(char labels[ACTPACK_STRUCT_DEVICE_FIELD_COUNT][ACTPACK_LABEL_MAX_CHAR_LENGTH]);

/// \brief retrieves the string equivalent of parameter names starting with state time.  Parameters 
/// prior to state time, such as id,  are not included. 
///
///@param labels is the array of labels containing the parameter names
///
int ActPackGetLabelsForLog(char labels[ACTPACK_STRUCT_DEVICE_FIELD_COUNT][ACTPACK_LABEL_MAX_CHAR_LENGTH]);

#ifdef __cplusplus
}//extern "C"
#endif

#endif ////ACTPACK_STRUCT_H
