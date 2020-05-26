#ifndef EXO_STRUCT_H
#define EXO_STRUCT_H

/*
 * exo_struct.h
 *
 * AUTOGENERATED FILE! ONLY EDIT IF YOU ARE A MACHINE!
 *
 * Created on: 2020-05-22 22:52:04.783810
 * Author: Dephy, Inc.
 *
 */

#include "Exo_device_spec.h"
#include <stdio.h> 
#include <time.h> 
#include <string.h> 
#include <stdint.h> 

#define EXO_SYSTEM_TIME_POS 53
#define EXO_STRUCT_DEVICE_FIELD_COUNT 54
#define EXO_LABEL_MAX_CHAR_LENGTH 29

//This is The Device fields*10 + deviceField+1. Ten is the max string length of 2^32 in decimal separated from commas
#define EXO_DATA_STRING_LENGTH 595

#ifdef __cplusplus
extern "C"
{
#endif

struct ExoState
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
	int ank_from_mot;
	int ank_torque;
	int step_energy;
	int walking_state;
	int gait_state;
	int shk_ang_deg;
	int bilateral_active;
	int dge_state;
	int mot_from_ank_ang;
	int step_count;
	int training_data_current_status;
	int need_to_add_steps;
	int training_progress;
	int substatedpeb42;
	int bi_state;
	int bi_substate;
	int bi_power;
	int bi_training_progress;
	int bi_training_status;
	int bi_need_steps;
	int bi_step_count;
	//the system time
	clock_t systemTime;
	uint32_t deviceData[EXO_STRUCT_DEVICE_FIELD_COUNT];
};

/// \brief Assigns the data in the buffer to the correct struct parameters
///
///@param Exo is the struct with the data to be set
///
///@param _deviceStateBuffer is the buffer containing the data to be assigned to the struct
///
///@param systemStartTime the time the system started. If unknown, use 0.
///
void ExoSetData(struct ExoState *exo, uint32_t _deviceStateBuffer[], clock_t systemStartTime);

/// \brief takes all data and places it into single, comma separated string
///
///@param Exo is the struct with the data to be placed in the string
///
///@param dataString is where the new string wll be placed 
///
void ExoDataToString(struct ExoState *exo, char dataString[EXO_DATA_STRING_LENGTH]);

/// \brief retrieves the string equivalent of all parameter names
///
///@param labels is the array of labels containing the parameter names
///
void ExoGetLabels(char labels[EXO_STRUCT_DEVICE_FIELD_COUNT][EXO_LABEL_MAX_CHAR_LENGTH]);

/// \brief retrieves the string equivalent of parameter names starting with state time.  Parameters 
/// prior to state time, such as id,  are not included. 
///
///@param labels is the array of labels containing the parameter names
///
int ExoGetLabelsForLog(char labels[EXO_STRUCT_DEVICE_FIELD_COUNT][EXO_LABEL_MAX_CHAR_LENGTH]);

#ifdef __cplusplus
}//extern "C"
#endif

#endif ////ACTPACK_STRUCT_H
