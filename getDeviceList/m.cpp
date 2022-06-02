#include <iostream>
#include "getDeviceList.h"

HRESULT UpdateDeviceList()
{
    HRESULT hr = S_OK;
    WCHAR* szFriendlyName = NULL;

    DeviceList g_devices;


    g_devices.Clear();

    hr = g_devices.EnumerateDevices();

    if (FAILED(hr)) { goto done; }
    std::cout << "Nb devices found:" << g_devices.Count() << std::endl;

    for (UINT32 iDevice = 0; iDevice < g_devices.Count(); iDevice++)
    {
        //std::cout << "" << std::endl;
        hr = g_devices.GetDeviceName(iDevice, &szFriendlyName);
        if (FAILED(hr)) { 
            std::cout << "Failed" << std::endl;
            goto done; 
        }
        std::cout << "Camera " << szFriendlyName << std::endl;
        // The list might be sorted, so the list index is not always the same as the
        // array index. Therefore, set the array index as item data.
        CoTaskMemFree(szFriendlyName);
        szFriendlyName = NULL;
    }
    std::cout << "End of EnumDeviceList" << std::endl;
done:
    return hr;
}
