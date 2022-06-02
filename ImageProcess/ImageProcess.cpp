// ImageProcess.cpp : 정적 라이브러리를 위한 함수를 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include <thread>

ImageProcess::ImageProcess(SETTING* setting) {
	set = setting;
	if (set->isMVS) {
		MVCon = new MVSConnect(set->CamIndex);
		MVCon->GrabCamera();
	}
	else {
		VideoCapture cap(set->CamIndex);
		Capture = cap;
		if (!isOpen()) { return; }
	}

		/*if (_access(setting.tempPath.c_str(), 0) == -1)
			return;
		if (_access(setting.tempPath.c_str(), 4) == -1)
			return;*/
	cout << "ImageProcess is created" << endl;
	/*for (size_t i = 0; i < tempContours.size(); i++)
	{
		double area = contourArea(tempContours[i]);
		if (area < 1e2 || 1e5 < area) continue;
		drawContours(temp, tempContours, static_cast<int>(i), Scalar(0, 0, 255), 2);
		getOrientation(tempContours[i], temp, true);
	}*/

	//loop();
	//loopThread = thread(&ImageProcess::loop, this);
}



void ImageProcess::loop() { //계속 실행되는 loop
	cout << "loop" << endl;
	Mat i;
	if (set->isMVS) {
		i = MVCon->GetMatFrame();
		cout << "MVS" << endl;
		//resize(img, img, Size(640,480));
		cvtColor(i, i, COLOR_GRAY2BGR);
	}
	else {
		Capture >> i;
	}
	//cout << set->imgThresh << endl;
	if (true)
		bilateralFilter(i, img, -1, 10, 5);
	else
		i.copyTo(img);
	thresholdImg(img, imgThreshold, set, false);
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	if (set->tempclass) { // tempclass가 생성되어 있으면( 비교할 templete이 있으면)
		findContours(imgThreshold, imgContours, RETR_LIST, CHAIN_APPROX_NONE);

		positions.clear();

		vector<tuple<Point, double>>().swap(positions);
	}
}

BITBYTE ImageProcess::MatToBytes(cv::Mat image)
{
	int image_size = image.total() * image.elemSize();
	unsigned char* image_uchar = new uchar[image_size];
	//image_uchar is a class data member of uchar*
	memcpy(image_uchar, image.data, image_size * sizeof(uchar));

	cv::Size size = image.size();

	BITBYTE byteimg;
	byteimg.bytes = image_uchar;
	byteimg.height = size.height;
	byteimg.width = size.width;
	byteimg.stride = image.step1();
	byteimg.format = PixelFormat24bppRGB;

	return byteimg;
}

void ImageProcess::thresholdImg(Mat& src, Mat& dst, SETTING* set, bool isTemp) {
	Mat srcGray;
	double maxVal;
	double threshType;
	double thresh;
	bool adaptive;
	cvtColor(src, srcGray, COLOR_BGR2GRAY);
	if (isTemp) {
		maxVal = set->tempMaxVal;
		threshType = set->tempThreshType;
		thresh = set->tempThresh;
		adaptive = set->tempThreshIsAdaptive;
	}
	else {
		maxVal = set->imgMaxVal;
		threshType = set->imgThreshType;
		thresh = set->imgThresh;
		adaptive = set->imgThreshIsAdaptive;
	}
	if (adaptive)
		adaptiveThreshold(srcGray, dst, maxVal, threshType, THRESH_BINARY, set->blockSize, set->C);
	else
		threshold(srcGray, dst, thresh, maxVal, threshType);
	cout << "thresholdImg thresh: " << thresh << " maxVal: " << maxVal << endl;
}
/*Gdiplus::Bitmap* ImageProcess::MatToBitmap(Mat Image) {
	cv::Size size = Image.size();
	Gdiplus::Bitmap* bitmap = new Gdiplus::Bitmap(size.width, size.height, Image.step1(), PixelFormat24bppRGB, Image.data);
	return bitmap;
}

BITBYTE ImageProcess::getByteImage() {
	return MatToBytes(img);
}

Gdiplus::Bitmap* ImageProcess::getBitmapImage() {
	return MatToBitmap(img);
}*/

void ImageProcess::drawTempContour(Mat& src, Mat& output) {
	src.copyTo(output);
	if (set->tempclass == nullptr) return;
	if (set->tempclass->getTempContourSize() <= set->tempContourIndex) return;
	vector<Point> tempContour;
	if (true)
		tempContour = approxContour(set->tempclass->getTempContours()[set->tempContourIndex]);
	else
		tempContour = set->tempclass->getTempContours()[set->tempContourIndex];
	for (size_t i = 0; i < imgContours.size(); i++)
	{
		double area = contourArea(imgContours[i]);
		if ((area < 1e2 || 1e5 < area) || (matchShapes(tempContour , imgContours[i], CONTOURS_MATCH_I2, 0.0) > 1.0 - (set->accuracy))) continue;
		drawContours(output, imgContours, static_cast<int>(i), Scalar(0, 0, 255), 2);
		tuple<Point, double> position = getOrientation(imgContours[i], output, true);
		positions.push_back(position);
	}
}

void ImageProcess::getRawImage(Mat& dst) {
	img.copyTo(dst);
}

void ImageProcess::getImage(Mat& dst) {
	img.copyTo(dst);
	drawTempContour(img, dst);;
}

bool ImageProcess::isOpen() {
	if (set->isMVS) {
		return true;
	} else {
		return Capture.isOpened();
	}
	return false;
}

void ImageProcess::getThreshold(Mat& dst) {
	cvtColor(imgThreshold, dst, COLOR_GRAY2BGR);
	drawTempContour(dst, dst);
}

void ImageProcess::getGray(Mat& dst ) {
	cvtColor(imgGray, dst, COLOR_GRAY2BGR);
	drawTempContour(dst, dst);
}

vector<tuple<Point, double>> ImageProcess::getPositions() {
	return positions;
}

void ImageProcess::refreshTemp() {

}

vector<Point> approxContour(vector<Point> contour) {
	double epsilon = 0.02*(arcLength(contour, true));
	vector<Point> dst;
	approxPolyDP(contour, dst, epsilon, true);
	return dst;
}