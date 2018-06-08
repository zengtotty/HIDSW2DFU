#ifndef WZ_ERROR_H__
#define WZ_ERROR_H__

#include <stdarg.h> 
#include <stdio.h> 
#include <stdint.h>
#include <stdbool.h>


//error code
typedef enum {
	WZ_RET_Success = 0,
	WZ_RET_Fail,

	WZ_RET_NULL_Pointer = 0x20,
	WZ_RET_BAD_ARGUMENT,

	WZ_RET_Error_Open = 0x40,
	WZ_RET_Error_Write,
	WZ_RET_Error_Read,

	WZ_RET_No_Device = 0x60,
	WZ_RET_Incomplete,

	WZ_RET_MEM_ERROR = 0xEE,
	WZ_RET_UNKNOW_LIB_ERROR = 0xFE,

	NOTVALID
} WZ_ErrorCode_t;

#define WZ_ERROR_LEVEL	(3u)
#define WZ_ERRROR_0U	(0u)
#define WZ_ERRROR_1U	(1u)
#define WZ_ERRROR_2U	(2u)
#define WZ_ERRROR_3U	(3u)

#define bytes_to_u16(MSB, LSB) (((uint16_t)(LSB & 0xFF)) | ((uint16_t)((MSB & 0xFF) << 8)))
#define u16_get_byte0(d)        ((uint8_t)((d) & 0xFF))
#define u16_get_byte1(d)        ((uint8_t)(((d) >>  8) & 0xFF))

//for compatitable usage
typedef bool	bool_t;

uint8_t gl_log_level;


#define WZ_DEBUG_PRINT(logLevel, message, ...)	{	\
if (logLevel <= WZ_ERROR_LEVEL){					   \
	switch (logLevel){							   \
	case WZ_ERRROR_0U:							   \
		printf("[CRTICAL_ERORR]: " message, __VA_ARGS__);	   \
		break;									   \
	case WZ_ERRROR_1U:							   \
		printf("[NO_IGNORE_ERORR]: " message, __VA_ARGS__);   \
		break;									   \
	case WZ_ERRROR_2U:							   \
	case WZ_ERRROR_3U:							   \
		printf("[ERROR]: " message, __VA_ARGS__);			   \
	default:									   \
		break;									   \
		}											   \
}												   \
else if (logLevel <= gl_log_level){				   \
	printf("[INFO]: " message, __VA_ARGS__);					\
}												   \
else{											   \
	;											   \
}												   \
}


#define CMD_RAW_IMU_ID1 (0xBE)
#define CMD_RAW_IMU_ID2 (0xEF)

#define CMD_6DOF_ID1 (0xA2)
#define CMD_6DOF_ID2 (0x33)

#define CMD_AEC_CTRL_ID1 (0xE3)
#define CMD_AEC_CTRL_ID2 (0x22)

//debug commandreportHidCompact
#define CMD_DEB_ID1 (0xDE)
#define CMD_DEB_ID2 (0xBB)

#define CMD_UPDATE_ID1 (0x12)
#define CMD_UPDATE_ID2 (0x34)

#define CMD_CAL_ID1 (0xCA)
#define CMD_CAL_ID2 (0x11)

#define CMD_GET_CAL_INFO_ID1 (0xCA)
#define CMD_GET_CAL_INFO_ID2 (0x12)

#define CMD_OUT_MODE_CTRL_ID1 (0x19)
#define CMD_OUT_MODE_CTRL_ID2 (0x95)

#define CMD_SLAM_CONFIG_ID1 (0x1B)
#define CMD_SLAM_CONFIG_ID2 (0x97)

#define CMD_SLAM_RESET_ID1 (0x1A)
#define CMD_SLAM_RESET_ID2 (0x96)

#define CMD_IMU_CONFIG_ID1 (0xE4)
#define CMD_IMU_CONFIG_ID2 (0x23)

#define CMD_VERSION_INFO_ID1 (0x1C)
#define CMD_VERSION_INFO_ID2 (0x99)

#define CMD_GET_IP_ID1 (0xFF)
#define CMD_GET_IP_ID2 (0x04)

#define CMD_FORWARDED_TO_ESP_ID1 (0xFF)

#define IMU_QUANTITY_ACCEL (0)
#define IMU_QUANTITY_GYRO (1)




typedef enum {
	CMD_RAW_IMU_FULL_ID = bytes_to_u16(CMD_RAW_IMU_ID1, CMD_RAW_IMU_ID2),
	CMD_6DOF_FULL_ID = bytes_to_u16(CMD_6DOF_ID1, CMD_6DOF_ID2),
	CMD_AEC_CTRL_FULL_ID = bytes_to_u16(CMD_AEC_CTRL_ID1, CMD_AEC_CTRL_ID2),
	CMD_DEB_FULL_ID = bytes_to_u16(CMD_DEB_ID1, CMD_DEB_ID2),
	CMD_UPDATE_FULL_ID = bytes_to_u16(CMD_UPDATE_ID1, CMD_UPDATE_ID2),
	CMD_SET_CAL_FULL_ID = bytes_to_u16(CMD_CAL_ID1, CMD_CAL_ID2),
	CMD_GET_CAL_INFO_FULL_ID = bytes_to_u16(CMD_GET_CAL_INFO_ID1, CMD_GET_CAL_INFO_ID2),
	CMD_OUT_MODE_CTRL_FULL_ID = bytes_to_u16(CMD_OUT_MODE_CTRL_ID1, CMD_OUT_MODE_CTRL_ID2),
	CMD_SLAM_CONFIG_FULL_ID = bytes_to_u16(CMD_SLAM_CONFIG_ID1, CMD_SLAM_CONFIG_ID2),
	CMD_SLAM_RESET_FULL_ID = bytes_to_u16(CMD_SLAM_RESET_ID1, CMD_SLAM_RESET_ID2),
	CMD_IMU_CONFIG_FULL_ID = bytes_to_u16(CMD_IMU_CONFIG_ID1, CMD_IMU_CONFIG_ID2),
	CMD_VERSION_INFO_FULL_ID = bytes_to_u16(CMD_VERSION_INFO_ID1, CMD_VERSION_INFO_ID2),
	CMD_GET_IP_FULL_ID = bytes_to_u16(CMD_GET_IP_ID1, CMD_GET_IP_ID2)
} slam_cmds;


#endif