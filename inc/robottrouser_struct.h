#ifndef ROBOTTROUSER_STRUCT_H
#define ROBOTTROUSER_STRUCT_H

/*
 * robottrouser_struct.h
 *
 * AUTOGENERATED FILE! ONLY EDIT IF YOU ARE A MACHINE!
 *
 * Created on: 2020-06-23 13:00:09.126583
 * Author: Dephy, Inc.
 *
 */

#include "RobotTrouser_device_spec.h"
#include <stdio.h> 
#include <time.h> 
#include <string.h> 
#include <stdint.h> 

#include <stdbool.h> 

#define ROBOTTROUSER_SYSTEM_TIME_POS 35
#define ROBOTTROUSER_STRUCT_DEVICE_FIELD_COUNT 36
#define ROBOTTROUSER_LABEL_MAX_CHAR_LENGTH 17

//This is The Device fields*10 + deviceField+1. Ten is the max string length of 2^32 in decimal separated from commas
#define ROBOTTROUSER_DATA_STRING_LENGTH 397

#ifdef __cplusplus
extern "C"
{
#endif

#pragma pack(1)

struct RobotTrouserState
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
	int shank_ang;
	int shank_vel;
	int global_shank_ang;

	//the system time
	int systemTime;
};

#pragma pack()

/// \brief Assigns the data in the buffer to the correct struct parameters
///
///@param RobotTrouser is the struct with the data to be set
///
///@param _deviceStateBuffer is the buffer containing the data to be assigned to the struct
///
///@param systemStartTime the time the system started. If unknown, use 0.
///
void RobotTrouserSetData(struct RobotTrouserState *robottrouser, uint32_t _deviceStateBuffer[], int systemStartTime);

/// \brief takes all data and places it into single, comma separated string
///
///@param RobotTrouser is the struct with the data to be placed in the string
///
///@param dataString is where the new string wll be placed 
///
void RobotTrouserDataToString(struct RobotTrouserState *robottrouser, char dataString[ROBOTTROUSER_DATA_STRING_LENGTH]);

/// \brief retrieves the string equivalent of all parameter names
///
///@param labels is the array of labels containing the parameter names
///
void RobotTrouserGetLabels(char labels[ROBOTTROUSER_STRUCT_DEVICE_FIELD_COUNT][ROBOTTROUSER_LABEL_MAX_CHAR_LENGTH]);

/// \brief retrieves the string equivalent of parameter names starting with state time.  Parameters 
/// prior to state time, such as id,  are not included. 
///
///@param labels is the array of labels containing the parameter names
///
int RobotTrouserGetLabelsForLog(char labels[ROBOTTROUSER_STRUCT_DEVICE_FIELD_COUNT][ROBOTTROUSER_LABEL_MAX_CHAR_LENGTH]);

/// \brief Places data from struct into an array.
///
///@param actpack the data to be converte to an array
///
///@param actpackDataArray the array in which to place the data
///
void RobotTrouserStructToDataArray(struct RobotTrouserState robottrouser, int32_t robottrouserDataArray[ROBOTTROUSER_STRUCT_DEVICE_FIELD_COUNT]);

/// \brief Get data based on data position from device communication.
///
///@param actpack the data to access
///
///@param dataPosition the position of data to access
///
///@param dataValid return false if requested data position is invalid
///
int GetRobotTrouserDataByDataPosition( struct RobotTrouserState robottrouser, int dataPosition);

#ifdef __cplusplus
}//extern "C"
#endif

#endif ////ACTPACK_STRUCT_H
