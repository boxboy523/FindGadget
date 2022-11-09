
#include "mvs.h"
MVSConnect::MVSConnect(unsigned int nIndex) {
    g_nPayloadSize = 1280 * 1024;
    pData = (unsigned char*)malloc(sizeof(unsigned char) * g_nPayloadSize);
    int nRet = MV_OK;
    handle = NULL;
    stImageInfo = { 0 };
    memset(&stImageInfo, 0, sizeof(MV_FRAME_OUT_INFO_EX));

    memset(&stDeviceList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));

    nRet = MV_CC_EnumDevices(MV_GIGE_DEVICE, &stDeviceList);
    if (MV_OK != nRet)
        printf("Enum Devices fail! nRet [0x%x]\n", nRet);

    nRet = MV_CC_CreateHandle(&handle, stDeviceList.pDeviceInfo[nIndex]);

    // open device
    nRet = MV_CC_OpenDevice(handle);
    if (MV_OK != nRet)
        printf("Open Device fail! nRet [0x%x]\n", nRet);

    printf("Cam is connected\n");
}

int MVSConnect::getDeviceList(MV_CC_DEVICE_INFO_LIST* DeviceList) {
    int nRet = MV_OK;

    nRet = MV_CC_EnumDevices(MV_GIGE_DEVICE, DeviceList);

    if (MV_OK != nRet)
        printf("Enum Devices fail! nRet [0x%x]\n", nRet);

    return nRet;
}

void MVSConnect::GrabCamera() {
    int nRet = MV_OK;
    //start grab image
    nRet = MV_CC_StartGrabbing(handle);
    Grab = true;
    if (MV_OK != nRet)
        printf("Start Grabbing fail! nRet [0x%x]\n", nRet);
}
int RGB2BGR(unsigned char* pRgbData, unsigned int nWidth, unsigned int nHeight)
{
    if (NULL == pRgbData)
    {
        return MV_E_PARAMETER;
    }

    for (unsigned int j = 0; j < nHeight; j++)
    {
        for (unsigned int i = 0; i < nWidth; i++)
        {
            unsigned char red = pRgbData[j * (nWidth * 3) + i * 3];
            pRgbData[j * (nWidth * 3) + i * 3] = pRgbData[j * (nWidth * 3) + i * 3 + 2];
            pRgbData[j * (nWidth * 3) + i * 3 + 2] = red;
        }
    }

    return MV_OK;
}

cv::Mat MVSConnect::Convert2Mat() {
    cv::Mat srcImage;
    srcImage = cv::Mat(stImageInfo.nHeight, stImageInfo.nWidth, CV_8UC1, pData);
    //cv::cvtColor(srcImage, srcImage, cv::COLOR_GRAY2RGB);


    return srcImage;
}

cv::Mat MVSConnect::GetMatFrame() {
    stImageInfo = { 0 };
    memset(&stImageInfo, 0, sizeof(MV_FRAME_OUT_INFO_EX));
    
    cv::Mat image;

    MV_CC_GetOneFrameTimeout(handle, pData, g_nPayloadSize, &stImageInfo, 1000);
    image = Convert2Mat();
    cv::resize(image, image, cv::Size(image.cols / 2, image.rows / 2));
    printf("MVS return Frame");
    return image;
}
MVSConnect::~MVSConnect() {
    int nRet = MV_OK;

    Grab = false;
    //Stop grab image
    nRet = MV_CC_StopGrabbing(handle);
    if (MV_OK != nRet)
        printf("Stop Grabbing fail! nRet [0x%x]\n", nRet);

    //Destroy handle
    nRet = MV_CC_CloseDevice(handle);
    if (MV_OK != nRet)
        printf("CloseDevice fail! nRet [0x%x]\n", nRet);

    nRet = MV_CC_DestroyHandle(handle);
    if (MV_OK != nRet)
        printf("Destroy Handle fail! nRet [0x%x]\n", nRet);

    printf("MVS is deleted \n");
}
