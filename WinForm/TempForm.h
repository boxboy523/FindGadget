#pragma once
#include "MyForm.h"
#include "AskText.h"

namespace WinForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm1에 대한 요약입니다.
	/// </summary>
	public ref class TempForm : public System::Windows::Forms::Form
	{
	public:
		TempForm(MyForm^ parent,SETTING* set)
		{
			highForm = parent;
			setting = set;
			InitializeComponent();
			imgUpdate();
			//this->numUpDownIndex->Maximum = tempC->getTempContourSize() - 1;
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//

			for (auto iter = set->tree.begin(); iter != set->tree.end(); ++iter) {
				vector<string> elements = iter->second.element;
				System::String^ str = gcnew System::String(iter->first.c_str());
				TreeNode^ node = gcnew TreeNode(str);
				tempTreeView->Nodes->Add(node);
				for (vector<string>::size_type i = 0; i < elements.size(); i++) {
					System::String^ child = gcnew System::String(elements[i].c_str());
					node->Nodes->Add(gcnew TreeNode(child));
				}
			}

			tempTreeView->ExpandAll();
		}


	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~TempForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox;
	protected:

	private: System::Windows::Forms::NumericUpDown^ numUpDownIndex;

	private: System::Windows::Forms::Label^ label1;



	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Button^ buttonApply;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::ComboBox^ comboBoxImage;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ comboBoxThreshold;


	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::TrackBar^ trackBarThreshold;
	private: System::Windows::Forms::Label^ labelThreshold;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ buttonCamTemp;
	private: System::Windows::Forms::Button^ buttonFileTemp;
	private: System::Windows::Forms::TextBox^ textBoxPath;
	private: System::Windows::Forms::TreeView^ tempTreeView;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
	private: System::Windows::Forms::Button^ buttonDelObj;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel4;
	private: System::Windows::Forms::Button^ setContourButton;
	private: System::Windows::Forms::TrackBar^ trackBarThresholdLarge;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ labelThresholdLarge;
	protected:

	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->numUpDownIndex = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonApply = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->trackBarThresholdLarge = (gcnew System::Windows::Forms::TrackBar());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->buttonCamTemp = (gcnew System::Windows::Forms::Button());
			this->trackBarThreshold = (gcnew System::Windows::Forms::TrackBar());
			this->labelThreshold = (gcnew System::Windows::Forms::Label());
			this->buttonFileTemp = (gcnew System::Windows::Forms::Button());
			this->textBoxPath = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBoxThreshold = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBoxImage = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->labelThresholdLarge = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tempTreeView = (gcnew System::Windows::Forms::TreeView());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->buttonDelObj = (gcnew System::Windows::Forms::Button());
			this->setContourButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numUpDownIndex))->BeginInit();
			this->panel1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarThresholdLarge))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarThreshold))->BeginInit();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox
			// 
			this->pictureBox->Location = System::Drawing::Point(3, 3);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(453, 426);
			this->pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox->TabIndex = 0;
			this->pictureBox->TabStop = false;
			this->pictureBox->Click += gcnew System::EventHandler(this, &TempForm::pictureBox1_Click);
			// 
			// numUpDownIndex
			// 
			this->numUpDownIndex->Location = System::Drawing::Point(144, 444);
			this->numUpDownIndex->Name = L"numUpDownIndex";
			this->numUpDownIndex->Size = System::Drawing::Size(120, 28);
			this->numUpDownIndex->TabIndex = 2;
			this->numUpDownIndex->ValueChanged += gcnew System::EventHandler(this, &TempForm::numUpDownIndex_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 441);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(122, 18);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Contour Index";
			this->label1->Click += gcnew System::EventHandler(this, &TempForm::label1_Click);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 157);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 18);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Threshold";
			this->label2->Click += gcnew System::EventHandler(this, &TempForm::label2_Click);
			// 
			// buttonApply
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->buttonApply, 2);
			this->buttonApply->Location = System::Drawing::Point(3, 671);
			this->buttonApply->Name = L"buttonApply";
			this->buttonApply->Size = System::Drawing::Size(270, 41);
			this->buttonApply->TabIndex = 8;
			this->buttonApply->Text = L"Close";
			this->buttonApply->UseVisualStyleBackColor = true;
			this->buttonApply->Click += gcnew System::EventHandler(this, &TempForm::buttonApply_Click);
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->pictureBox);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(856, 728);
			this->panel1->TabIndex = 9;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &TempForm::panel1_Paint);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->trackBarThresholdLarge, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->label5, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->buttonCamTemp, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->trackBarThreshold, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->labelThreshold, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->buttonFileTemp, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBoxPath, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->buttonApply, 0, 10);
			this->tableLayoutPanel1->Controls->Add(this->label4, 0, 9);
			this->tableLayoutPanel1->Controls->Add(this->comboBoxThreshold, 1, 9);
			this->tableLayoutPanel1->Controls->Add(this->label3, 0, 8);
			this->tableLayoutPanel1->Controls->Add(this->comboBoxImage, 1, 8);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 7);
			this->tableLayoutPanel1->Controls->Add(this->numUpDownIndex, 1, 7);
			this->tableLayoutPanel1->Controls->Add(this->label6, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->labelThresholdLarge, 1, 5);
			this->tableLayoutPanel1->Location = System::Drawing::Point(1168, 3);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 11;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 41.59292F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 58.40708F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 38)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 45)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 86)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 71)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 95)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 65)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 78)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 84)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 59)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(282, 728);
			this->tableLayoutPanel1->TabIndex = 10;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &TempForm::tableLayoutPanel1_Paint);
			// 
			// trackBarThresholdLarge
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->trackBarThresholdLarge, 2);
			this->trackBarThresholdLarge->Location = System::Drawing::Point(3, 349);
			this->trackBarThresholdLarge->Maximum = 255;
			this->trackBarThresholdLarge->Name = L"trackBarThresholdLarge";
			this->trackBarThresholdLarge->Size = System::Drawing::Size(276, 69);
			this->trackBarThresholdLarge->TabIndex = 19;
			this->trackBarThresholdLarge->Value = 100;
			this->trackBarThresholdLarge->Scroll += gcnew System::EventHandler(this, &TempForm::trackBarThresholdLarge_Scroll);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(135, 18);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Template image";
			// 
			// buttonCamTemp
			// 
			this->buttonCamTemp->Location = System::Drawing::Point(144, 47);
			this->buttonCamTemp->Name = L"buttonCamTemp";
			this->buttonCamTemp->Size = System::Drawing::Size(135, 24);
			this->buttonCamTemp->TabIndex = 15;
			this->buttonCamTemp->Text = L"From cam...";
			this->buttonCamTemp->UseVisualStyleBackColor = true;
			this->buttonCamTemp->Click += gcnew System::EventHandler(this, &TempForm::buttonCamTemp_Click);
			// 
			// trackBarThreshold
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->trackBarThreshold, 2);
			this->trackBarThreshold->Location = System::Drawing::Point(3, 192);
			this->trackBarThreshold->Maximum = 255;
			this->trackBarThreshold->Name = L"trackBarThreshold";
			this->trackBarThreshold->Size = System::Drawing::Size(276, 69);
			this->trackBarThreshold->TabIndex = 11;
			this->trackBarThreshold->Value = 50;
			this->trackBarThreshold->Scroll += gcnew System::EventHandler(this, &TempForm::trackBarThreshold_Scroll);
			// 
			// labelThreshold
			// 
			this->labelThreshold->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelThreshold->AutoSize = true;
			this->labelThreshold->Location = System::Drawing::Point(197, 157);
			this->labelThreshold->Name = L"labelThreshold";
			this->labelThreshold->Size = System::Drawing::Size(28, 18);
			this->labelThreshold->TabIndex = 12;
			this->labelThreshold->Text = L"50";
			// 
			// buttonFileTemp
			// 
			this->buttonFileTemp->Location = System::Drawing::Point(3, 47);
			this->buttonFileTemp->Name = L"buttonFileTemp";
			this->buttonFileTemp->Size = System::Drawing::Size(135, 24);
			this->buttonFileTemp->TabIndex = 14;
			this->buttonFileTemp->Text = L"From file...";
			this->buttonFileTemp->UseVisualStyleBackColor = true;
			this->buttonFileTemp->Click += gcnew System::EventHandler(this, &TempForm::buttonFileTemp_Click);
			// 
			// textBoxPath
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->textBoxPath, 2);
			this->textBoxPath->Location = System::Drawing::Point(3, 109);
			this->textBoxPath->Name = L"textBoxPath";
			this->textBoxPath->Size = System::Drawing::Size(276, 28);
			this->textBoxPath->TabIndex = 16;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 584);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(94, 36);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Threshold Method";
			// 
			// comboBoxThreshold
			// 
			this->comboBoxThreshold->FormattingEnabled = true;
			this->comboBoxThreshold->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Auto(OTSU)", L"Self(BINARY)", L"Adaptive(MEAN)",
					L"Adaptive(Gaussian)"
			});
			this->comboBoxThreshold->Location = System::Drawing::Point(144, 587);
			this->comboBoxThreshold->Name = L"comboBoxThreshold";
			this->comboBoxThreshold->Size = System::Drawing::Size(121, 26);
			this->comboBoxThreshold->TabIndex = 10;
			this->comboBoxThreshold->SelectedIndexChanged += gcnew System::EventHandler(this, &TempForm::comboBoxThreshold_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 506);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(97, 18);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Image type";
			// 
			// comboBoxImage
			// 
			this->comboBoxImage->FormattingEnabled = true;
			this->comboBoxImage->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Normal", L"Gray", L"Threshold" });
			this->comboBoxImage->Location = System::Drawing::Point(144, 509);
			this->comboBoxImage->Name = L"comboBoxImage";
			this->comboBoxImage->Size = System::Drawing::Size(121, 26);
			this->comboBoxImage->TabIndex = 7;
			this->comboBoxImage->SelectedIndexChanged += gcnew System::EventHandler(this, &TempForm::comboBoxImage_SelectedIndexChanged);
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(23, 292);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(94, 36);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Threshold Large";
			// 
			// labelThresholdLarge
			// 
			this->labelThresholdLarge->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelThresholdLarge->AutoSize = true;
			this->labelThresholdLarge->Location = System::Drawing::Point(192, 301);
			this->labelThresholdLarge->Name = L"labelThresholdLarge";
			this->labelThresholdLarge->Size = System::Drawing::Size(38, 18);
			this->labelThresholdLarge->TabIndex = 18;
			this->labelThresholdLarge->Text = L"100";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				303)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				288)));
			this->tableLayoutPanel2->Controls->Add(this->panel1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel1, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(1453, 734);
			this->tableLayoutPanel2->TabIndex = 11;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->tempTreeView, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel4, 0, 1);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(865, 3);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 2;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 92.30769F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.692307F)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(297, 728);
			this->tableLayoutPanel3->TabIndex = 11;
			this->tableLayoutPanel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &TempForm::tableLayoutPanel3_Paint);
			// 
			// tempTreeView
			// 
			this->tempTreeView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tempTreeView->Location = System::Drawing::Point(3, 3);
			this->tempTreeView->Name = L"tempTreeView";
			this->tempTreeView->Size = System::Drawing::Size(291, 666);
			this->tempTreeView->TabIndex = 11;
			this->tempTreeView->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &TempForm::tempTreeView_AfterSelect);
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				141)));
			this->tableLayoutPanel4->Controls->Add(this->buttonDelObj, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->setContourButton, 1, 0);
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 675);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(291, 50);
			this->tableLayoutPanel4->TabIndex = 12;
			// 
			// buttonDelObj
			// 
			this->buttonDelObj->Location = System::Drawing::Point(3, 3);
			this->buttonDelObj->Name = L"buttonDelObj";
			this->buttonDelObj->Size = System::Drawing::Size(118, 30);
			this->buttonDelObj->TabIndex = 12;
			this->buttonDelObj->Text = L"Delete node";
			this->buttonDelObj->UseVisualStyleBackColor = true;
			this->buttonDelObj->Click += gcnew System::EventHandler(this, &TempForm::buttonDelObj_Click);
			// 
			// setContourButton
			// 
			this->setContourButton->Location = System::Drawing::Point(153, 3);
			this->setContourButton->Name = L"setContourButton";
			this->setContourButton->Size = System::Drawing::Size(128, 30);
			this->setContourButton->TabIndex = 13;
			this->setContourButton->Text = L"Set Contour";
			this->setContourButton->UseVisualStyleBackColor = true;
			this->setContourButton->Click += gcnew System::EventHandler(this, &TempForm::setContourButton_Click);
			// 
			// TempForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1453, 734);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Name = L"TempForm";
			this->Text = L"Template";
			this->Load += gcnew System::EventHandler(this, &TempForm::TempForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numUpDownIndex))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarThresholdLarge))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarThreshold))->EndInit();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private:
	SETTING* setting;
	tempClass* tempC = nullptr;
	MyForm^ highForm;

	System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}
	System::Void numUpDownIndex_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {}
	System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {}
	System::Void TempForm_Load(System::Object^ sender, System::EventArgs^ e) {}
	System::Void comboBoxImage_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	System::Void trackBarThreshold_Scroll(System::Object^ sender, System::EventArgs^ e);
	System::Void comboBoxThreshold_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	System::Void buttonFileTemp_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void buttonCamTemp_Click(System::Object^ sender, System::EventArgs^ e);
	void imgUpdate();
	Mat* img = &Mat();
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void buttonApply_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void tempTreeView_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e) {

	System::String^ name = e->Node->Text;
	string nameStr = msclr::interop::marshal_as<std::string>(name);
	tuple<vector<cv::Point>, THRESHSET, int> t = setting->nodeContours[nameStr];
	setting->tempThresh = std::get<1>(t);
	setting->tempContourIndex = std::get<2>(t);
	setting->usePointGroup = true;
	imgUpdate();
}
private: System::Void buttonDelObj_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tableLayoutPanel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void setContourButton_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void trackBarThresholdLarge_Scroll(System::Object^ sender, System::EventArgs^ e) {
	int value = static_cast<int> (trackBarThresholdLarge->Value);
	labelThresholdLarge->Text = value.ToString(CultureInfo::InvariantCulture);
	//numUpDownIndex->Value = 0;
	setting->tempThresh.Large = value;
	imgUpdate();
}
};
}
