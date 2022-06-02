#include "TempForm.h"
#include <ctime>
#include <direct.h>

System::Void WinForm::TempForm::numUpDownIndex_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	imgUpdate();
}

System::Void WinForm::TempForm::comboBoxImage_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	imgUpdate();
}

System::Void WinForm::TempForm::comboBoxThreshold_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	switch (comboBoxThreshold->SelectedIndex) {
	case 1:
		setting->tempThreshType = THRESH_BINARY;
		setting->tempThreshIsAdaptive = false;
		break;
	case 2:
		setting->tempThreshType = ADAPTIVE_THRESH_MEAN_C;
		setting->tempThreshIsAdaptive = true;
		break;
	case 3:
		setting->tempThreshType = ADAPTIVE_THRESH_GAUSSIAN_C;
		setting->tempThreshIsAdaptive = true;
		break;
	default:
		setting->tempThreshType = THRESH_OTSU;
		setting->tempThreshIsAdaptive = false;
		break;
	}
	//numUpDownIndex->Value = 0;
	imgUpdate();
}

System::Void WinForm::TempForm::trackBarThreshold_Scroll(System::Object^ sender, System::EventArgs^ e) {
	int value = static_cast<int> (trackBarThreshold->Value);
	labelThreshold->Text = value.ToString(CultureInfo::InvariantCulture);
	//numUpDownIndex->Value = 0;
	setting->tempThresh = value;
	imgUpdate();
}

void WinForm::TempForm::imgUpdate() {
	if (tempC == nullptr) return;
	img = &Mat();
	tempC->update();
	tempC->getTemp(*img, int(numUpDownIndex->Value), -1, -1, comboBoxImage->SelectedIndex);
	pictureBox->Image = MyForm::MatToBmp(img, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
	numUpDownIndex->Maximum = tempC->getTempContourSize() - 1;
	cout << "Selected Image Mode: " << comboBoxImage->SelectedIndex << endl;

}

System::Void WinForm::TempForm::buttonFileTemp_Click(System::Object^ sender, System::EventArgs^ e) {
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
	textBoxPath->Text = ofd->FileName;
	System::String^ pathString = textBoxPath->Text;
	std::string pathChar = msclr::interop::marshal_as<std::string>(pathString);
	setting->tempPath = pathChar;
	if (setting->tempclass)
		delete setting->tempclass;
	setting->tempclass = new tempClass(setting);
	tempC = setting->tempclass;
	if (!setting->tempclass->isAble()) {
		MessageBox::Show("템플릿 이미지 경로를 찾을 수 없습니다.");
		setting->tempclass = nullptr;
		return;
	}
	imgUpdate();
}

System::Void WinForm::TempForm::buttonCamTemp_Click(System::Object^ sender, System::EventArgs^ e) {
	if (highForm->getImageProcess() == nullptr || !highForm->getImageProcess()->isOpen()) return;
	Mat temp;
	Mat src;
	highForm->getImageProcess()->getRawImage(temp);
	//char curDir[1000];
	//_getcwd(curDir, 1000);	
	string fileName = to_string(time(NULL));
	fileName.append(".jpg");
	imwrite(fileName,temp);
	setting->tempPath = fileName;
	textBoxPath->Text = msclr::interop::marshal_as<System::String^>(fileName);
	if (setting->tempclass)
		delete setting->tempclass;
	setting->tempclass = new tempClass(setting);
	tempC = setting->tempclass;
	if (!setting->tempclass->isAble()) {
		MessageBox::Show("템플릿 이미지 경로를 찾을 수 없습니다.");
		setting->tempclass = nullptr;
		return;
	}
	imgUpdate();
}