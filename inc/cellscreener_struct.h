#ifndef CELLSCREENER_STRUCT_H
#define CELLSCREENER_STRUCT_H

///
/// \file cellscreener_struct.h
///
/// \brief AUTOGENERATED FILE! ONLY EDIT IF YOU ARE A MACHINE!
///
/// \core 9aef6d74b18c1c47d64bf9be2e1a769752e5ad8b
///
/// \build fb364600346136d1240bef7b18993a3ef541559a
///
/// \date 2020-10-14 16:43:39
///
/// \author Dephy, Inc.

#include "CellScreener_device_spec.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define CELLSCREENER_SYSTEM_TIME_POS 20
#define CELLSCREENER_STRUCT_DEVICE_FIELD_COUNT 21
#define CELLSCREENER_LABEL_MAX_CHAR_LENGTH 15

/// This is The Device fields * 10 + deviceField + 1. Ten is the max string length of 2^32 in
/// decimal separated from commas
#define CELLSCREENER_DATA_STRING_LENGTH 232

#ifdef __cplusplus
extern "C"
{
#endif

#pragma pack(1)

struct CellScreenerState
{
	int cellscreener;
	int id;
	int state_time;
	int current;
	int voltage;
	int fsm_state;
	int button;
	int leds;
	int genvar_0;
	int genvar_1;
	int genvar_2;
	int genvar_3;
	int status;
	int p_timestamp;
	int p_current;
	int p_open_voltage;
	int p_voltage;
	int p_dv;
	int p_esr;
	int p_bin;
	int systemTime; /// System time
};

#pragma pack()

///
/// \brief Assigns the data in the buffer to the correct struct parameters
///
/// \param CellScreener is the struct with the data to be set
///
/// \param _deviceStateBuffer is the buffer containing the data to be assigned to the struct
///
/// \param systemStartTime the time the system started. If unknown, use 0.
///
void CellScreenerSetData(struct CellScreenerState *cellscreener, uint32_t _deviceStateBuffer[], int systemStartTime);

///
/// \brief takes all data and places it into single, comma separated string
///
/// \param CellScreener is the struct with the data to be placed in the string
///
/// \param dataString is where the new string wll be placed
///
void CellScreenerDataToString(struct CellScreenerState *cellscreener, char dataString[CELLSCREENER_DATA_STRING_LENGTH]);

///
/// \brief retrieves the string equivalent of all parameter names
///
/// \param labels is the array of labels containing the parameter names
///
void CellScreenerGetLabels(char labels[CELLSCREENER_STRUCT_DEVICE_FIELD_COUNT][CELLSCREENER_LABEL_MAX_CHAR_LENGTH]);

///
/// \brief retrieves the string equivalent of parameter names starting with state time.
/// Parameters prior to state time, such as id, are not included.
///
/// \param labels is the array of labels containing the parameter names
///
int CellScreenerGetLabelsForLog(char labels[CELLSCREENER_STRUCT_DEVICE_FIELD_COUNT][CELLSCREENER_LABEL_MAX_CHAR_LENGTH]);

///
/// \brief Places data from struct into an array.
///
/// \param cellscreener the data to be converte to an array
///
/// \param cellscreenerDataArray the array in which to place the data
///
void CellScreenerStructToDataArray(struct CellScreenerState cellscreener, int32_t cellscreenerDataArray[CELLSCREENER_STRUCT_DEVICE_FIELD_COUNT]);

///
/// \brief Get data based on data position from device communication.
///
/// \param cellscreener the data to access
///
/// \param dataPosition the position of data to access
///
/// \param dataValid return false if requested data position is invalid
///
int GetCellScreenerDataByDataPosition( struct CellScreenerState cellscreener, int dataPosition);

#ifdef __cplusplus
} //extern "C"
#endif

#endif //CELLSCREENER_STRUCT_H
