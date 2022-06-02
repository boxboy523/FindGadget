#include "MyForm.h"
#include "DataForm.h"
#include <gdiplus.h>
using namespace System::Threading;
using namespace System::Runtime::InteropServices;



void WinForm::MyForm::CamLoop(void) {
	int s;
	cout << "CamLoop" << endl;
	while (ShowCam) {
		s = imgUpdate();
		if (s == -1) { break;}
	}
	pictureBox1->Image = nullptr;
	delete FormImageProcess;
	FormImageProcess = nullptr;
}	

System::Drawing::Bitmap^ WinForm::MyForm::MatToBmp(cv::Mat *img, System::Drawing::Imaging::PixelFormat format) {
	cout <<"image information" <<" Cols: " << img->cols<<" Rows: " << img->rows <<" Steps: " << img->step1() << " Depth: " << img->depth() << endl;
	cout << "Flags: " << img->flags << endl;
	//cout <<"data: " << data <<" Size: " << sizeof(img->data) << endl;
	//cout << img->ptr() << endl;
	System::Drawing::Bitmap^ bmp = gcnew System::Drawing::Bitmap(
		img->cols, img->rows, img->step1(),
		format,//System::Drawing::Imaging::PixelFormat::Format24bppRgb,
		(System::IntPtr)img->ptr());
	return bmp;
}

int WinForm::MyForm::imgUpdate() {
	cout << "imgUpdate" << endl;
	Bitmap^ bmp = getImage();
	if (bmp == nullptr) {
		return -1;
	}
	CheckForIllegalCrossThreadCalls = false;
	WinForm::MyForm::pictureBox1->Image = bmp;
	return 0;
}

System::Drawing::Bitmap^ WinForm::MyForm::getImage(){
	if (!FormImageProcess->isOpen()) {
		return nullptr; //cannot find camara
	}
	cout << "getImage" << endl;
	FormImageProcess->loop();
	
	System::Drawing::Imaging::PixelFormat format;
	switch(ComboIndexCam){
	case 1:
		FormImageProcess->getGray(*img);
		format = System::Drawing::Imaging::PixelFormat::Format24bppRgb;
		break;
	case 2:
		FormImageProcess->getThreshold(*img);
		format = System::Drawing::Imaging::PixelFormat::Format24bppRgb;
		break;
	default:
		FormImageProcess->getImage(*img);
		format = System::Drawing::Imaging::PixelFormat::Format24bppRgb;
	}
	//cv::Mat img = FormImageProcess->getImage();
	return MatToBmp(img,format);
}

//System::Drawing::Imaging::ColorPalette^ WinForm::MyForm::getGrayPalette() {
	/*using namespace System::Drawing;
	Bitmap^ bmp = gcnew Bitmap(1, 1, 1, System::Drawing::Imaging::PixelFormat::Format8bppIndexed, (System::IntPtr)nullptr);
	System::Drawing::Imaging::ColorPalette^ _palette = bmp->Palette;
	cli::array <System::Drawing::Color, 1>^ _entries = _palette->Entries;

	for (int i = 0; i < 256; i++)
	{
		Color^ b = gcnew Color();
		b = Color::FromArgb((byte)i, (byte)i, (byte)i);
		_entries[i] = b;
	}
	return _palette;*/
//}
System::Void WinForm::MyForm::Connect_Click(System::Object^ sender, System::EventArgs^ e) {
	
	ImageProcess* IP = new ImageProcess(setting);
	if (!IP->isOpen() && !(checkBoxMVS->Checked)) {
		MessageBox::Show("카메라를 찾을 수 없습니다.");
		return;
	}
	
	if (ShowCam) {
		ShowCam = false;
		Sleep(1);
	}

	FormImageProcess = IP;
	cout << "ImageProcess " << IP << " is connected" << endl;
	setting->accuracy = static_cast<float> (trackBarAccurecy->Value) / static_cast<float> (trackBarAccurecy->Maximum);

	ShowCam = true;

	CamDele^ dele = gcnew CamDele(this, &MyForm::CamLoop);
	IAsyncResult^ result = dele->BeginInvoke(nullptr, nullptr);
}