#pragma once
#include "MvCameraControl.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>
#include <Windows.h>
#include <process.h>
#include <conio.h>
#include "string.h"

class MVSConnect {
public:
	MVSConnect(unsigned int nIndex);
	~MVSConnect();
	cv::Mat GetMatFrame();
	void GrabCamera();
	static int getDeviceList(MV_CC_DEVICE_INFO_LIST* DeviceList);
	bool Grab = false;
private:
	void* handle = NULL;
	unsigned char* pData;
	MV_FRAME_OUT_INFO_EX stImageInfo;
	MV_CC_DEVICE_INFO_LIST stDeviceList;
	unsigned int g_nPayloadSize = 0;
	cv::Mat Convert2Mat();
};