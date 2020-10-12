#ifndef NETNODE_STRUCT_H
#define NETNODE_STRUCT_H

/*
 * netnode_struct.h
 *
 * AUTOGENERATED FILE! ONLY EDIT IF YOU ARE A MACHINE!
 *
 * Created on: 2020-09-13 19:47:28.177157
 * Author: Dephy, Inc.
 *
 */

#include "NetNode_device_spec.h"
#include <stdio.h> 
#include <time.h> 
#include <string.h> 
#include <stdint.h> 

#include <stdbool.h> 

#define NETNODE_SYSTEM_TIME_POS 8
#define NETNODE_STRUCT_DEVICE_FIELD_COUNT 9
#define NETNODE_LABEL_MAX_CHAR_LENGTH 11

//This is The Device fields*10 + deviceField+1. Ten is the max string length of 2^32 in decimal separated from commas
#define NETNODE_DATA_STRING_LENGTH 100

#ifdef __cplusplus
extern "C"
{
#endif

#pragma pack(1)

struct NetNodeState
{
	int netnode;
	int id;
	int state_time;
	int genvar_0;
	int genvar_1;
	int genvar_2;
	int genvar_3;
	int status;

	//the system time
	int systemTime;
};

#pragma pack()

/// \brief Assigns the data in the buffer to the correct struct parameters
///
///@param NetNode is the struct with the data to be set
///
///@param _deviceStateBuffer is the buffer containing the data to be assigned to the struct
///
///@param systemStartTime the time the system started. If unknown, use 0.
///
void NetNodeSetData(struct NetNodeState *netnode, uint32_t _deviceStateBuffer[], int systemStartTime);

/// \brief takes all data and places it into single, comma separated string
///
///@param NetNode is the struct with the data to be placed in the string
///
///@param dataString is where the new string wll be placed 
///
void NetNodeDataToString(struct NetNodeState *netnode, char dataString[NETNODE_DATA_STRING_LENGTH]);

/// \brief retrieves the string equivalent of all parameter names
///
///@param labels is the array of labels containing the parameter names
///
void NetNodeGetLabels(char labels[NETNODE_STRUCT_DEVICE_FIELD_COUNT][NETNODE_LABEL_MAX_CHAR_LENGTH]);

/// \brief retrieves the string equivalent of parameter names starting with state time.  Parameters 
/// prior to state time, such as id,  are not included. 
///
///@param labels is the array of labels containing the parameter names
///
int NetNodeGetLabelsForLog(char labels[NETNODE_STRUCT_DEVICE_FIELD_COUNT][NETNODE_LABEL_MAX_CHAR_LENGTH]);

/// \brief Places data from struct into an array.
///
///@param actpack the data to be converte to an array
///
///@param actpackDataArray the array in which to place the data
///
void NetNodeStructToDataArray(struct NetNodeState netnode, int32_t netnodeDataArray[NETNODE_STRUCT_DEVICE_FIELD_COUNT]);

/// \brief Get data based on data position from device communication.
///
///@param actpack the data to access
///
///@param dataPosition the position of data to access
///
///@param dataValid return false if requested data position is invalid
///
int GetNetNodeDataByDataPosition( struct NetNodeState netnode, int dataPosition);

#ifdef __cplusplus
}//extern "C"
#endif

#endif ////ACTPACK_STRUCT_H
