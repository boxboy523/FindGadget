

#pragma once
#include <Windows.h>
#include <gdiplus.h>
#include <opencv2/opencv.hpp>
#include <tuple>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <thread>
#include "../FindGadget/MVSConnect/mvs.h"
#include <io.h>
#pragma comment(lib, "gdiplus")

using namespace cv;
using namespace std;

const int FLAG_NORMAL = 0;
const int FLAG_GRAY = 1;
const int FLAG_THRESHOLD = 2;


class tempClass;
void drawAxis(Mat&, Point, Point, Scalar, const float);
tuple<Point, double> getOrientation(const vector<Point>& pts, Mat& img, bool draw);
struct BITBYTE;
struct SETTING {
	string tempPath;
	int tempContourIndex = 0;
	double tempThresh = 50;
	double tempMaxVal = 255;
	int tempThreshType = THRESH_BINARY | THRESH_OTSU;
	double imgThresh = 50;
	double imgMaxVal = 255;
	int imgThreshType = THRESH_OTSU;
	bool imgThreshIsAdaptive = false;
	bool tempThreshIsAdaptive = false;
	float accuracy = 0.05;
	int CamIndex = 0;
	bool isMVS = false;
	double C = 5; 
	int blockSize = 9;
	tempClass* tempclass = nullptr;
};
class ImageProcess {
private:
	
	uchar* byteImg;

	VideoCapture Capture;

	Mat imgGray;
	Mat imgThreshold;
	vector<vector<Point>> imgContours;
	//Gdiplus::Bitmap* bitmap;

	thread loopThread;
	BITBYTE MatToBytes(Mat image);
	//Gdiplus::Bitmap* MatToBitmap(Mat image);
	
	Mat img;

	vector<tuple<Point, double>> positions;

	MVSConnect* MVCon = nullptr;
public:
	bool isOpen();
	SETTING* set;
	
	ImageProcess(SETTING* setting);
	//BITBYTE getByteImage();
	//Gdiplus::Bitmap* getBitmapImage();
	void refreshTemp();
	void getImage(Mat& dst);
	void loop();
	void getThreshold(Mat& dst);
	void getGray(Mat& dst);
	void getRawImage(Mat& dst);
	vector<tuple<Point, double>> getPositions();
	static void thresholdImg(Mat& src, Mat& output, SETTING* set, bool isTemp);
	void drawTempContour(Mat& src,Mat& output);

	~ImageProcess() {
		if (MVCon != nullptr)
			delete MVCon;
	}
};

class tempClass {
private:
	Mat tempGray;
	Mat tempThreshold;
	Mat temp;
	vector<vector<Point> > tempContours;
	SETTING* set;
	bool success = false;
public:
	tempClass(SETTING* setting);
	void getTemp(Mat& img,int contourIndex,int width,int height, int flag);
	int getTempContourSize();
	vector<vector<Point>> getTempContours();
	void update();
	bool isAble();
};

struct BITBYTE { //이미지정보

	int height; 
	int width; 
	int stride; 
	unsigned char* bytes = nullptr; 
	Gdiplus::PixelFormat format; 
};

vector<Point> approxContour(vector<Point> contour);