#pragma once
#include <new>
#include <windows.h>
#include <mfapi.h>
#include <mfidl.h>
#include <mfreadwrite.h>
#include <Wmcodecdsp.h>
#include <assert.h>
#include <Dbt.h>
#include <shlwapi.h>
#include <mfplay.h>

#include <iostream>


const UINT WM_APP_PREVIEW_ERROR = WM_APP + 1;    // wparam = HRESULT

class DeviceList
{
    UINT32      m_cDevices; // contains the number of devices
    IMFActivate** m_ppDevices; // contains properties about each device

public:
    DeviceList() : m_ppDevices(NULL), m_cDevices(0)
    {
        MFStartup(MF_VERSION);
    }
    ~DeviceList()
    {
        Clear();
    }

    UINT32  Count() const { return m_cDevices; }

    void    Clear();
    HRESULT EnumerateDevices();
    HRESULT GetDevice(UINT32 index, IMFActivate** ppActivate);
    HRESULT GetDeviceName(UINT32 index, WCHAR** ppszName);
};

