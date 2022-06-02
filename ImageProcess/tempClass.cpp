#include "pch.h"
#include "framework.h"

tempClass::tempClass(SETTING* setting) {
	set = setting;
	update();
}

void tempClass::getTemp(Mat& img, int contourIndex, int width, int height, int flag) {
	switch (flag) {
	case FLAG_GRAY:
		cvtColor(tempGray, img, COLOR_GRAY2BGR);
		cout << "Get tempete's Gray image" << endl;
		break;
	case FLAG_THRESHOLD:
		ImageProcess::thresholdImg(temp, img, set, true);
		cvtColor(tempThreshold, img, COLOR_GRAY2BGR);
		cout << "Get tempete's Threshold image" << endl;
		break;
	default:
		img = temp;
		cout << "Get tempete's Normal image" << endl;
		break;
	}
	if(tempContours.size() > contourIndex)
		drawContours(img, tempContours, contourIndex, Scalar(0, 0, 255), 2);
	if (width > 0)
		resize(img, img, Size(width, height));
	//cout <<"temp" << t.cols << "|" << temp.rows << "|" << temp.step1() << "|" << temp.type() << endl;
}

int tempClass::getTempContourSize() {
	return tempContours.size();
}
vector<vector<Point>> tempClass::getTempContours() {
	return tempContours;
}

bool tempClass::isAble() {
	return success;
}

void tempClass::update() {
	if (_access(set->tempPath.c_str(), 0) == -1) {
		success = false;
		cout << "tempClass is fail to update" << endl;
		return;
	}
	temp = imread(set->tempPath);
	cvtColor(temp, tempGray, COLOR_BGR2GRAY);
	ImageProcess::thresholdImg(temp, tempThreshold, set, true);
	vector<vector<Point> > t;
	tempContours.clear();
	findContours(tempThreshold, t, RETR_LIST, CHAIN_APPROX_NONE);
	for (size_t i = 0; i < t.size(); i++)
	{
		double area = contourArea(t[i]);
		if (area < 1e2 || 1e5 < area) continue;
		tempContours.push_back(t[i]);
	}

	success = true;
	cout << "tempClass is updated" << endl << "tempThresh: " << set->tempThresh << endl << "tempThresh type: " << set->tempThreshType << endl;
}