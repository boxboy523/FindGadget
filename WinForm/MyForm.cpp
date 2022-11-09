#include "MyForm.h"
#include "TempForm.h"
#include "DataForm.h"
#include "SettingForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Runtime::InteropServices;
[STAThreadAttribute]

void main() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	WinForm::MyForm form;
	Application::Run(% form);
}

/*System::Void WinForm::MyForm::buttonBrowse_Click(System::Object^ sender, System::EventArgs^ e) {
	IO::Stream^ myStream;
	
	OpenFileDialog ^ ofd = gcnew OpenFileDialog();
	ofd->Title = "Template File";
	ofd->Filter = "그림 파일 (*.jpg, *.gif, *.bmp) | *.jpg; *.gif; *.bmp; | 모든 파일 (*.*) | *.*";
	ofd->FilterIndex = 2;
	ofd->RestoreDirectory = true;

	if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if ((myStream = ofd->OpenFile()) != nullptr)
		{
			// Insert code to read the stream here.
			myStream->Close();
		}
	}
	textPath->Text = ofd->FileName;
	System::String^ pathString = textPath->Text;
	std::string pathChar = msclr::interop::marshal_as<std::string>(pathString);
	setting->tempPath = pathChar;
	if (setting->tempclass)
		delete setting->tempclass;
	setting->tempclass = new tempClass(setting);
	if (!setting->tempclass->isAble()) {
		MessageBox::Show("템플릿 이미지 경로를 찾을 수 없습니다.");
		setting->tempclass = nullptr;
		return;
	}
}*/

System::Void WinForm::MyForm::SetIndexButton_Click(System::Object^ sender, System::EventArgs^ e) {
	//WinForm::TempForm^ form = gcnew WinForm::TempForm(this);
	//form->Show();
	TempForm^ form = gcnew TempForm(this, setting);
	form->Show();
}

System::Void WinForm::MyForm::comboBoxCam_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	ComboIndexCam = comboBoxCam->SelectedIndex;
}

System::Void WinForm::MyForm::comboBoxThreshold_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	ComboIndexThreshold = comboBoxThreshold->SelectedIndex;
	
	updateThresholdUI(ComboIndexThreshold);
	
}

void WinForm::MyForm::updateThresholdUI(int index) {
	switch (index) {
	case 1:
		setting->imgThresh.Type = THRESH_BINARY;
		setting->imgThresh.Canny = false;
		break;
	case 2:
		setting->imgThresh.Type = 100;
		setting->imgThresh.Canny = true;
		break;
	default:
		setting->imgThresh.Type = THRESH_OTSU;
		setting->imgThresh.Canny = false;
		break;
	}
}

System::Void WinForm::MyForm::buttonPos_Click(System::Object^ sender, System::EventArgs^ e) {
	df = gcnew WinForm::DataForm(this, 0);

	df->Show();
}


ImageProcess* WinForm::MyForm::getImageProcess() {
	return FormImageProcess;
}


/*void WinForm::MyForm::loadIni() {
	std::string path = "./setting.ini";
	if (_access(path.c_str(), 0) == -1)
		return;
	setting->CamIndex = GetPrivateProfileIntA("MyFormSetting", "CamIndex", 0, path.c_str());
	numUpDownCamIndex->Value = setting->CamIndex;
	comboBoxCam->SelectedIndex = GetPrivateProfileIntA("MyFormSetting", "CamMode", 0, path.c_str());
	setting->imgThresh = GetPrivateProfileIntA("MyFormSetting", "Threshold", 255, path.c_str());
	trackBarThreshold->Value = setting->imgThresh;
	comboBoxThreshold->SelectedIndex = GetPrivateProfileIntA("MyFormSetting", "ThresholdMode", 0, path.c_str());
	ComboIndexThreshold = comboBoxThreshold->SelectedIndex;
	updateThresholdUI(ComboIndexThreshold);
	trackBarAccurecy->Value = GetPrivateProfileIntA("MyFormSetting", "Accuracy", 0, path.c_str());
	float value1 = static_cast<float> (trackBarAccurecy->Value) / static_cast<float> (trackBarAccurecy->Maximum);
	setting->accuracy = value1;
	labelAccurecy->Text = value1.ToString(CultureInfo::InvariantCulture);
	int value2 = trackBarThreshold->Value;
	labelThreshold->Text = value2.ToString(CultureInfo::InvariantCulture);

	char buffer[256];
	GetPrivateProfileStringA("MyFormSetting", "tempPath", "./temp.png", buffer, 256, path.c_str());
	textPath->Text = gcnew System::String(buffer);
	GetPrivateProfileStringA("MyFormSetting", "MVS", "false", buffer, 256, path.c_str());
	cout << "\"" << buffer << "\"" << endl;
	if (strcmp(buffer, "true")){
		checkBoxMVS->Checked = false;
		setting->isMVS = false;
	}
	else {
		checkBoxMVS->Checked = true;
		setting->isMVS = true;
	}

	cout << checkBoxMVS->Checked << endl;

}
*/
/*void WinForm::MyForm::saveIni() {
	std::string path = "./setting.ini";
	if (_access(path.c_str(), 0) == -1) {
		std::ofstream ofs(path, std::ios::out | std::ios::app);
		ofs.close();
	}
	WritePrivateProfileStringA("MyFormSetting", "CamIndex",to_string(int(numUpDownCamIndex->Value)).c_str() , path.c_str());
	WritePrivateProfileStringA("MyFormSetting", "CamMode", to_string(int(comboBoxCam->SelectedIndex)).c_str(), path.c_str());
	WritePrivateProfileStringA("MyFormSetting", "Threshold", to_string(int(trackBarThreshold->Value)).c_str(), path.c_str());
	WritePrivateProfileStringA("MyFormSetting", "ThresholdMode", to_string(int(comboBoxThreshold->SelectedIndex)).c_str(), path.c_str());
	WritePrivateProfileStringA("MyFormSetting", "tempPath", (char*)(void*)Marshal::StringToHGlobalAnsi(textPath->Text) , path.c_str());
	if (checkBoxMVS->Checked)
		WritePrivateProfileStringA("MyFormSetting", "MVS", "true", path.c_str());
	else
		WritePrivateProfileStringA("MyFormSetting", "MVS", "false", path.c_str());
	WritePrivateProfileStringA("MyFormSetting", "Accuracy", to_string(int(trackBarAccurecy->Value)).c_str(), path.c_str());
}
*/
System::Void WinForm::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	/*Mat img = FormImageProcess->getImage();
	Mat img2 = imread(setting->tempPath);
	System::Drawing::Bitmap^ bmp = gcnew System::Drawing::Bitmap(
		img2.cols, img2.rows, img2.step1(),
		System::Drawing::Imaging::PixelFormat::Format24bppRgb,
		(System::IntPtr)img2.ptr());
	WinForm::MyForm::pictureBox1->Image = bmp;*/
	
}

tempClass* WinForm::MyForm::getTempClass() { return setting->tempclass; }

System::Void WinForm::MyForm::buttonDevice_Click(System::Object^ sender, System::EventArgs^ e) {
	if(setting->isMVS)
		df = gcnew WinForm::DataForm(this, 2);
	else
		df = gcnew WinForm::DataForm(this, 1);

	df->Show();
}

System::Void WinForm::MyForm::buttonFromFile_Click(System::Object^ sender, System::EventArgs^ e) {
	IO::Stream^ myStream;

	OpenFileDialog^ ofd = gcnew OpenFileDialog();
	ofd->Title = "Template File";
	ofd->Filter = "그림 파일 (*.jpg, *.gif, *.bmp) | *.jpg; *.gif; *.bmp; | 모든 파일 (*.*) | *.*";
	ofd->FilterIndex = 2;
	ofd->RestoreDirectory = true;

	if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if ((myStream = ofd->OpenFile()) != nullptr)
		{
			// Insert code to read the stream here.
			myStream->Close();
		}
	}
}

System::Void WinForm::MyForm::buttonSetting_Click(System::Object^ sender, System::EventArgs^ e) {
	SettingForm^ sf = gcnew SettingForm(setting);
	sf->Show();
}