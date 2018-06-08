#include "windows.h"
#include "hid/hidapi.h"
#include "wz_error.h"
#include "tchar.h"

#pragma comment(lib,"Hid.lib")
#pragma comment(lib,"SetupAPI.lib")
#pragma comment(lib,"strmiids.lib")

#define HID_MESS_SIZE	(100u)
#define SET_REPORT_ID		(2u)
#define REPORT_SIZE		(63u)		/*report count is 63u, report size is 8 bits*/


WZ_ErrorCode_t switch_to_fw_update(hid_device *dev){
	int8_t res = 0;
	if (!dev){
		return WZ_RET_No_Device;
	}
	unsigned char buf[HID_MESS_SIZE];
	memset(buf, 0, sizeof(buf));
	buf[0] = SET_REPORT_ID;
	buf[1] = u16_get_byte1(CMD_UPDATE_FULL_ID);
	buf[2] = u16_get_byte0(CMD_UPDATE_FULL_ID);

#if (HID_SET_REPORT_METHOD == 1u)
	res = hid_send_report(dev, buf, REPORT_SIZE);
#else
	res = hid_write(dev, buf, REPORT_SIZE);
#endif
	if (res <= 0){
		WZ_DEBUG_PRINT(0, "[%s] Could not config the device\r\n", __FUNCTION__);
		return WZ_RET_Fail;
	}
	return WZ_RET_Success;
}



int _tmain(int argc, _TCHAR* argv[])
{
	bool ret = true;
	WZ_ErrorCode_t rc = WZ_RET_Success;
	hid_device *handle;
	gl_log_level = 9;
	//handle = hid_open(0x40e, 0xf408, NULL);
	while (1){
		handle = hid_open(0x40e, 0xf408, NULL);
		if (!handle) {
			//WZ_DEBUG_PRINT(0, "Could not find the device\r\n");
		}
		else {
			hid_set_nonblocking(handle, false);
			WZ_DEBUG_PRINT(4, "Find the device\r\n");
			break;
		}
		Sleep(100);
	}
	WZ_DEBUG_PRINT(5, "Start to test the HID\r\n");
	
	for (int index = 0; index < 100000; index++) {
		rc = switch_to_fw_update(handle);
		if (rc == WZ_RET_Success){
			WZ_DEBUG_PRINT(5, "Hid write succesful\r\n");
		}
		Sleep(3000);
	}

	return 0;
}


