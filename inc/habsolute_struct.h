#ifndef HABSOLUTE_STRUCT_H
#define HABSOLUTE_STRUCT_H

///
/// \file habsolute_struct.h
///
/// \brief AUTOGENERATED FILE! ONLY EDIT IF YOU ARE A MACHINE!
///
/// \core 0bad34709094958919bfe30e6c0ca13c7682c49a
///
/// \build df4ac791e9dd25df235f8ed979101d1d2e75b19b
///
/// \date 2020-06-22 14:42:45
///
/// \author Dephy, Inc.

#include "Habsolute_device_spec.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define HABSOLUTE_SYSTEM_TIME_POS 18
#define HABSOLUTE_STRUCT_DEVICE_FIELD_COUNT 19
#define HABSOLUTE_LABEL_MAX_CHAR_LENGTH 11

/// This is The Device fields * 10 + deviceField + 1. Ten is the max string length of 2^32 in
/// decimal separated from commas
#define HABSOLUTE_DATA_STRING_LENGTH 210

#ifdef __cplusplus
extern "C"
{
#endif

#pragma pack(1)

struct HabsoluteState
{
	int habsolute;
	int id;
	int state_time;
	int ank_ang;
	int ank_vel;
	int adc_0;
	int adc_1;
	int adc_2;
	int adc_3;
	int adc_4;
	int adc_5;
	int adc_6;
	int adc_7;
	int genvar_0;
	int genvar_1;
	int genvar_2;
	int genvar_3;
	int status;
	int systemTime; /// System time
};

#pragma pack()

///
/// \brief Assigns the data in the buffer to the correct struct parameters
///
/// \param Habsolute is the struct with the data to be set
///
/// \param _deviceStateBuffer is the buffer containing the data to be assigned to the struct
///
/// \param systemStartTime the time the system started. If unknown, use 0.
///
void HabsoluteSetData(struct HabsoluteState *habsolute, const uint32_t _deviceStateBuffer[], int systemStartTime);

///
/// \brief takes all data and places it into single, comma separated string
///
/// \param Habsolute is the struct with the data to be placed in the string
///
/// \param dataString is where the new string wll be placed
///
void HabsoluteDataToString(struct HabsoluteState *habsolute, char dataString[HABSOLUTE_DATA_STRING_LENGTH]);

///
/// \brief retrieves the string equivalent of all parameter names
///
/// \param labels is the array of labels containing the parameter names
///
void HabsoluteGetLabels(char labels[HABSOLUTE_STRUCT_DEVICE_FIELD_COUNT][HABSOLUTE_LABEL_MAX_CHAR_LENGTH]);

///
/// \brief retrieves the string equivalent of parameter names starting with state time.
/// Parameters prior to state time, such as id, are not included.
///
/// \param labels is the array of labels containing the parameter names
///
int HabsoluteGetLabelsForLog(char labels[HABSOLUTE_STRUCT_DEVICE_FIELD_COUNT][HABSOLUTE_LABEL_MAX_CHAR_LENGTH]);

///
/// \brief Places data from struct into an array.
///
/// \param habsolute the data to be converted to an array
///
/// \param habsoluteDataArray the array in which to place the data
///
void HabsoluteStructToDataArray(struct HabsoluteState habsolute, int32_t habsoluteDataArray[HABSOLUTE_STRUCT_DEVICE_FIELD_COUNT]);

///
/// \brief Get data based on data position from device communication.
///
/// \param habsolute the data to access
///
/// \param dataPosition the position of data to access
///
/// \param dataValid return false if requested data position is invalid
///
int GetHabsoluteDataByDataPosition( struct HabsoluteState habsolute, int dataPosition);

#ifdef __cplusplus
} //extern "C"
#endif

#endif //HABSOLUTE_STRUCT_H
