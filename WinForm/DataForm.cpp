#include "DataForm.h"
#include "MyForm.h"
#include <tuple>

void WinForm::DataForm::updatePositionTable() {
	ImageProcess* IP = parentForm->getImageProcess();
		if (IP == nullptr) return;
	cout << IP->getPositions()[0].name << endl;
	vector<CONTINFO> P = IP->getPositions();
	table->Clear();
	for (int i = 0; P.size() > i; i++) {
		System::String^ const str = gcnew System::String(P[i].name.c_str());
		table->Rows->Add(i, P[i].point.x, P[i].point.y , P[i].degree, str);
	}

	dataGridView->DataSource = table;
}

void WinForm::DataForm::initTable() {
	table = gcnew DataTable();
	switch (mode) {
	case 0:
		table->Columns->Add(gcnew DataColumn("ID", Int32::typeid));
		table->Columns->Add(gcnew DataColumn("x", Int32::typeid));
		table->Columns->Add(gcnew DataColumn("y", Int32::typeid));
		table->Columns->Add(gcnew DataColumn("degree", double::typeid));
		table->Columns->Add(gcnew DataColumn("Name", System::String::typeid));
		cout << "mode 0 init" << endl;
		break;
	case 1:
		table->Columns->Add(gcnew DataColumn("Index", Int32::typeid));
		table->Columns->Add(gcnew DataColumn("Name", System::String::typeid));
		cout << "mode 1 init" << endl;
		break;
	case 2:
		table->Columns->Add(gcnew DataColumn("Index", Int32::typeid));
		table->Columns->Add(gcnew DataColumn("IP", System::String::typeid));
		table->Columns->Add(gcnew DataColumn("Name", System::String::typeid));
		cout << "mode 1 init" << endl;
		break;
	}
}

HRESULT WinForm::DataForm::updateDeviceTable() {
	HRESULT hr = S_OK;
	WCHAR* szFriendlyName = NULL;
	//table->Rows->Add(333, "asdf");

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
		System::String^ const str = gcnew System::String(szFriendlyName);
		table->Rows->Add(int(iDevice), str);
		// The list might be sorted, so the list index is not always the same as the
		// array index. Therefore, set the array index as item data.
		CoTaskMemFree(szFriendlyName);
		szFriendlyName = NULL;
	}
	dataGridView->DataSource = table;
	std::cout << "End of EnumDeviceList" << std::endl;
done:
	return hr;
}

int WinForm::DataForm::updateMVSDeviceTable() {
	int nRet = MV_OK;
	MV_CC_DEVICE_INFO_LIST DL;
	memset(&DL, 0, sizeof(MV_CC_DEVICE_INFO_LIST));
	MV_GIGE_DEVICE_INFO device;
	int ip;
	System::String ^ ipStr = "";
	System::String^ name = "";
	nRet = MVSConnect::getDeviceList(&DL);
	if (DL.nDeviceNum > 0) {
		for (int i = 0; i < DL.nDeviceNum; i++) {
			device = DL.pDeviceInfo[i]->SpecialInfo.stGigEInfo;
			ip = device.nCurrentIp;
			ipStr = System::Convert::ToString(ip & 0x000000FF) + '.' + System::Convert::ToString(ip & 0x0000FF00 >> 8) + '.' +
				System::Convert::ToString(ip & 0x00FF0000 >> 16) + '.'+ System::Convert::ToString(ip & 0xFF000000 >> 24);
			cout << ip << endl;
			name = gcnew System::String(reinterpret_cast<const char*>(device.chModelName));
			table->Rows->Add(i, ipStr, name);
		}
		dataGridView->DataSource = table;
	}
	return nRet;
}


//HRESULT WinForm::DataForm::updateDeviceTable()