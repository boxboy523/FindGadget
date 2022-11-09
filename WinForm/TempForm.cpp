#include "TempForm.h"
#include <ctime>
#include <direct.h>

System::Void WinForm::TempForm::numUpDownIndex_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	if(setting->usePointGroup)
		setting->tempContourIndex = int(numUpDownIndex->Value);
	else
		setting->tempContourIndex = tempC->getComp()[int(numUpDownIndex->Value)];
	cout << setting->tempContourIndex << endl;
  	imgUpdate();
}

System::Void WinForm::TempForm::comboBoxImage_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	imgUpdate();
}

System::Void WinForm::TempForm::comboBoxThreshold_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	switch (comboBoxThreshold->SelectedIndex) {
	case 1:
		setting->tempThresh.Type = THRESH_BINARY;
		setting->tempThresh.Canny= false;
		break;
	case 2:
		setting->tempThresh.Type = 100;
		setting->tempThresh.Canny = true;
		break;
	default:
		setting->tempThresh.Type = THRESH_OTSU;
		setting->tempThresh.Canny = false;
		break;
	}
	//numUpDownIndex->Value = 0;
	imgUpdate();
}

System::Void WinForm::TempForm::trackBarThreshold_Scroll(System::Object^ sender, System::EventArgs^ e) {
	int value = static_cast<int> (trackBarThreshold->Value);
	labelThreshold->Text = value.ToString(CultureInfo::InvariantCulture);
	//numUpDownIndex->Value = 0;
	setting->tempThresh.Small = value;
	imgUpdate();
}

void WinForm::TempForm::imgUpdate() {
	if (tempC == nullptr) return;
	img = &Mat();
	tempC->update();
	tempC->drawTemp(*img, setting->tempContourIndex, -1, -1, comboBoxImage->SelectedIndex);
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
	setting->tempThresh.Path = pathChar;

	if (setting->tempclass)
		delete setting->tempclass;
	setting->tempclass = new tempClass(setting);
	tempC = setting->tempclass;
	if (!setting->tempclass->isAble()) {
		MessageBox::Show("이미지 경로를 찾을 수 없습니다.");
		setting->tempclass = nullptr;
		return;
	}
	numUpDownIndex->Value = 0;
	imgUpdate();
}

System::Void WinForm::TempForm::buttonCamTemp_Click(System::Object^ sender, System::EventArgs^ e) {
	if (highForm->getImageProcess() == nullptr || !highForm->getImageProcess()->isOpen()) return;
	Mat temp;
	Mat src;
	highForm->getImageProcess()->getRawImage(temp);
	string fileName = to_string(time(NULL));
	fileName.append(".jpg");
	imwrite(fileName,temp);
	setting->tempThresh.Path = fileName;
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
	numUpDownIndex->Value = 0;
	imgUpdate();
}

System::Void WinForm::TempForm::setContourButton_Click(System::Object^ sender, System::EventArgs^ e) {


	// 노드 이름을 입력받고, 노드를 만들어 저장
	System::String^ str = gcnew System::String("None");
	AskText^ form = gcnew AskText(str);
	form->ShowDialog();
	if (str == "") {
		return;
	}

	std::string parent = msclr::interop::marshal_as<std::string>(str);

	cout << "index: " << setting->tempContourIndex << endl;

	TreeNode^ node = gcnew TreeNode(str);

	tempTreeView->Nodes->Add(node);

	// v에 contour index를 저장
	vector<int> v;
	THRESHSET ts = setting->tempThresh;
	if (setting->usePointGroup) {
		// pointGroup v
		v = tempC->getPointGroup()[setting->tempContourIndex];
		THRESHSET ts = setting->tempThresh;
		setting->nodeContours.insert(make_pair(parent, make_tuple(tempC->getPointGroupContour().at(setting->tempContourIndex), ts, setting->tempContourIndex)));
		//vector<vector<cv::Point>> contours;
		//for (int i = 0; i < v.size(); i++) {
		//	contours.push_back(tempC->getTempContours()[v[i]]);
		//}
		//tempC->addContour(convexContours(contours), v);
		//tempC->saveTemp(parent, tempC->getTempContours().size()-1);
	}
	else {
		v = findChild(setting->tempContourIndex, tempC->getHierarchy());
		tempC->saveTemp(parent, setting->tempContourIndex);
	}

	//tree 만들기
	setting->tree[parent].element = vector<string>();

	vector<int> comp = tempC->getComp();
	//tree와 노드의 하위, nodeContour에 각각 정보 저장 
	int num = 0;
	if (setting->usePointGroup)
		setting->tree[parent].nodeMode = 1;
	else
		setting->tree[parent].nodeMode = 0;
	for (int i = 0; i < v.size(); i++) {
		if (find(comp.begin(), comp.end(), v[i]) == comp.end()) continue;
		if (setting->usePointGroup && i == 0) continue;
		std::string s = parent + to_string(num);
		cout << "str: " << s << endl;
		// tree 저장
		setting->tree[parent].element.push_back(s);
		//nodeContour 저장
		tempC->saveTemp(s, v[i]);

		// 노드 저장
		node->Nodes->Add(gcnew TreeNode(gcnew System::String(s.c_str())));
		num++;
	}

	tempC->saveGroup(parent);

	tempTreeView->ExpandAll();
}

System::Void WinForm::TempForm::buttonDelObj_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!tempTreeView->SelectedNode) return;
	TreeNode^ node = tempTreeView->SelectedNode;
	std::string name = msclr::interop::marshal_as<std::string>(node->Text);
	if (setting->nodeContours.find(name) != setting->nodeContours.end())
		setting->nodeContours.erase(name);

	if (node->Level == 0) {

		vector<string> iter = setting->tree[name].element;
		for (int i = 0; i < iter.size(); i++) {
			setting->nodeContours.erase(iter[i]);
		}
		setting->tree.erase(name);
	}
	else {
		std::string parent = msclr::interop::marshal_as<std::string>(node->Parent->Text);

		auto it = find(setting->tree[parent].element.begin(), setting->tree[parent].element.end(), name);
		if (it != setting->tree[parent].element.end()) {
			setting->tree[parent].element.erase(it);
		}
		else {
			cout << "tree[parent] 의 값을 찾을 수 없습니다." << it._Ptr << "  " << setting->tree[parent].element.end()._Ptr << (string("s") == string("s")) << endl;
			return;
		}
	}
	node->Remove();

}