#pragma once
#include "../../ImageProcess/framework.h"
#include <fstream>
#include <msclr\marshal_cppstd.h>

namespace WinForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;
	ref class DataForm;
/*
디자인을 수정할 때에는 위의 ref class DataForm; 클래스 선언문을 주석처리하고 수정하세요.
그러지 않으면 위의 선언문의 클래스를 창으로 인식합니다.
*/


	/// <summary>
	/// MyForm에 대한 요약입니다.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			setting = new SETTING;
			//setting->tempclass = new tempClass(setting);
			//if(setting->tempclass->isAble())
			//loadIni();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MyForm()
		{
			//saveIni();
			if (components)
			{
				delete components;
			}
			if (FormImageProcess) {
				delete FormImageProcess;
				FormImageProcess = 0;
			}
			if (setting->tempclass) {
				delete setting->tempclass;
			}
			delete setting;
		}

	protected:

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::NumericUpDown^ numUpDownCamIndex;
	private: System::Windows::Forms::Label^ labelAccurecy;
	private: System::Windows::Forms::Button^ SetIndexButton;
	private: System::Windows::Forms::ComboBox^ comboBoxCam;
	private: System::Windows::Forms::ComboBox^ comboBoxThreshold;
	private: System::Windows::Forms::Label^ labelThreshold;
	public protected: System::Windows::Forms::CheckBox^ checkBoxMVS;
	private: System::Windows::Forms::Button^ buttonDevice;


	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TrackBar^ trackBarAccurecy;
	private: System::Windows::Forms::Label^ label3;


	private: System::Windows::Forms::TrackBar^ trackBarThreshold;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ Connect;
	private: System::Windows::Forms::Button^ buttonRefresh;


	private: System::Windows::Forms::Button^ buttonPos;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ buttonFromFile;

	private: System::Windows::Forms::Label^ labelThreshLargeN;
	private: System::Windows::Forms::TrackBar^ trackBarThresholdLarge;
	private: System::Windows::Forms::Label^ labelThresholdLarge;
	private: System::Windows::Forms::Label^ labelThresholdL;
	private: System::Windows::Forms::Button^ buttonSetting;

	public protected:
	private:
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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->numUpDownCamIndex = (gcnew System::Windows::Forms::NumericUpDown());
			this->trackBarAccurecy = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->labelAccurecy = (gcnew System::Windows::Forms::Label());
			this->SetIndexButton = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBoxCam = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->trackBarThreshold = (gcnew System::Windows::Forms::TrackBar());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBoxThreshold = (gcnew System::Windows::Forms::ComboBox());
			this->labelThreshold = (gcnew System::Windows::Forms::Label());
			this->checkBoxMVS = (gcnew System::Windows::Forms::CheckBox());
			this->buttonDevice = (gcnew System::Windows::Forms::Button());
			this->Connect = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->trackBarThresholdLarge = (gcnew System::Windows::Forms::TrackBar());
			this->buttonRefresh = (gcnew System::Windows::Forms::Button());
			this->buttonPos = (gcnew System::Windows::Forms::Button());
			this->buttonFromFile = (gcnew System::Windows::Forms::Button());
			this->labelThreshLargeN = (gcnew System::Windows::Forms::Label());
			this->labelThresholdLarge = (gcnew System::Windows::Forms::Label());
			this->buttonSetting = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numUpDownCamIndex))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarAccurecy))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarThreshold))->BeginInit();
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarThresholdLarge))->BeginInit();
			this->tableLayoutPanel2->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(3, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(395, 45);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// numUpDownCamIndex
			// 
			this->numUpDownCamIndex->Location = System::Drawing::Point(107, 3);
			this->numUpDownCamIndex->Name = L"numUpDownCamIndex";
			this->numUpDownCamIndex->Size = System::Drawing::Size(97, 28);
			this->numUpDownCamIndex->TabIndex = 2;
			this->numUpDownCamIndex->ValueChanged += gcnew System::EventHandler(this, &MyForm::numUpDownCamIndexf);
			// 
			// trackBarAccurecy
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->trackBarAccurecy, 3);
			this->trackBarAccurecy->Location = System::Drawing::Point(3, 802);
			this->trackBarAccurecy->Maximum = 100;
			this->trackBarAccurecy->Name = L"trackBarAccurecy";
			this->trackBarAccurecy->Size = System::Drawing::Size(310, 56);
			this->trackBarAccurecy->TabIndex = 6;
			this->trackBarAccurecy->Value = 50;
			this->trackBarAccurecy->Scroll += gcnew System::EventHandler(this, &MyForm::trackBarAccurecy_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 36);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Camera Index";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 751);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 18);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Accurecy";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// labelAccurecy
			// 
			this->labelAccurecy->AutoSize = true;
			this->labelAccurecy->Location = System::Drawing::Point(107, 751);
			this->labelAccurecy->Name = L"labelAccurecy";
			this->labelAccurecy->Size = System::Drawing::Size(34, 18);
			this->labelAccurecy->TabIndex = 10;
			this->labelAccurecy->Text = L"0.5";
			// 
			// SetIndexButton
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->SetIndexButton, 3);
			this->SetIndexButton->Location = System::Drawing::Point(3, 266);
			this->SetIndexButton->Name = L"SetIndexButton";
			this->SetIndexButton->Size = System::Drawing::Size(310, 49);
			this->SetIndexButton->TabIndex = 13;
			this->SetIndexButton->Text = L"Find template";
			this->SetIndexButton->UseVisualStyleBackColor = true;
			this->SetIndexButton->Click += gcnew System::EventHandler(this, &MyForm::SetIndexButton_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 358);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(97, 18);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Cam Mode";
			// 
			// comboBoxCam
			// 
			this->comboBoxCam->FormattingEnabled = true;
			this->comboBoxCam->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Normal", L"Gray", L"Threshold" });
			this->comboBoxCam->Location = System::Drawing::Point(107, 361);
			this->comboBoxCam->Name = L"comboBoxCam";
			this->comboBoxCam->Size = System::Drawing::Size(98, 26);
			this->comboBoxCam->TabIndex = 16;
			this->comboBoxCam->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBoxCam_SelectedIndexChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(3, 500);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(88, 18);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Threshold";
			this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			// 
			// trackBarThreshold
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->trackBarThreshold, 3);
			this->trackBarThreshold->Location = System::Drawing::Point(3, 552);
			this->trackBarThreshold->Maximum = 255;
			this->trackBarThreshold->Name = L"trackBarThreshold";
			this->trackBarThreshold->Size = System::Drawing::Size(310, 69);
			this->trackBarThreshold->TabIndex = 18;
			this->trackBarThreshold->Value = 50;
			this->trackBarThreshold->Scroll += gcnew System::EventHandler(this, &MyForm::trackBarThreshold_Scroll);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(3, 423);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(94, 36);
			this->label7->TabIndex = 19;
			this->label7->Text = L"Threshold Method";
			// 
			// comboBoxThreshold
			// 
			this->comboBoxThreshold->FormattingEnabled = true;
			this->comboBoxThreshold->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Auto(OTSU)", L"Self(BINARY)", L"Adaptive(MEAN)",
					L"Adaptive(Gaussian)"
			});
			this->comboBoxThreshold->Location = System::Drawing::Point(107, 426);
			this->comboBoxThreshold->Name = L"comboBoxThreshold";
			this->comboBoxThreshold->Size = System::Drawing::Size(98, 26);
			this->comboBoxThreshold->TabIndex = 20;
			this->comboBoxThreshold->Text = L"Auto(OTSU)";
			this->comboBoxThreshold->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBoxThreshold_SelectedIndexChanged);
			// 
			// labelThreshold
			// 
			this->labelThreshold->AutoSize = true;
			this->labelThreshold->Location = System::Drawing::Point(107, 500);
			this->labelThreshold->Name = L"labelThreshold";
			this->labelThreshold->Size = System::Drawing::Size(28, 18);
			this->labelThreshold->TabIndex = 21;
			this->labelThreshold->Text = L"50";
			// 
			// checkBoxMVS
			// 
			this->checkBoxMVS->AutoSize = true;
			this->checkBoxMVS->Location = System::Drawing::Point(211, 171);
			this->checkBoxMVS->Name = L"checkBoxMVS";
			this->checkBoxMVS->Size = System::Drawing::Size(71, 22);
			this->checkBoxMVS->TabIndex = 23;
			this->checkBoxMVS->Text = L"MVS";
			this->checkBoxMVS->UseVisualStyleBackColor = true;
			this->checkBoxMVS->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxMVS_CheckedChanged);
			// 
			// buttonDevice
			// 
			this->buttonDevice->Location = System::Drawing::Point(211, 3);
			this->buttonDevice->Name = L"buttonDevice";
			this->buttonDevice->Size = System::Drawing::Size(101, 24);
			this->buttonDevice->TabIndex = 25;
			this->buttonDevice->Text = L"Find...";
			this->buttonDevice->UseVisualStyleBackColor = true;
			this->buttonDevice->Click += gcnew System::EventHandler(this, &MyForm::buttonDevice_Click);
			// 
			// Connect
			// 
			this->Connect->Location = System::Drawing::Point(3, 171);
			this->Connect->Name = L"Connect";
			this->Connect->Size = System::Drawing::Size(98, 51);
			this->Connect->TabIndex = 30;
			this->Connect->Text = L"Connect";
			this->Connect->UseVisualStyleBackColor = true;
			this->Connect->Click += gcnew System::EventHandler(this, &MyForm::Connect_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				108)));
			this->tableLayoutPanel1->Controls->Add(this->trackBarThresholdLarge, 0, 9);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->Connect, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->trackBarAccurecy, 0, 11);
			this->tableLayoutPanel1->Controls->Add(this->labelAccurecy, 1, 10);
			this->tableLayoutPanel1->Controls->Add(this->numUpDownCamIndex, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->buttonDevice, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->label3, 0, 10);
			this->tableLayoutPanel1->Controls->Add(this->labelThreshold, 1, 6);
			this->tableLayoutPanel1->Controls->Add(this->trackBarThreshold, 0, 7);
			this->tableLayoutPanel1->Controls->Add(this->label6, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->checkBoxMVS, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->label5, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->comboBoxCam, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->comboBoxThreshold, 1, 5);
			this->tableLayoutPanel1->Controls->Add(this->label7, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->buttonRefresh, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->buttonPos, 0, 12);
			this->tableLayoutPanel1->Controls->Add(this->SetIndexButton, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->buttonFromFile, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->labelThreshLargeN, 0, 8);
			this->tableLayoutPanel1->Controls->Add(this->labelThresholdLarge, 1, 8);
			this->tableLayoutPanel1->Controls->Add(this->buttonSetting, 2, 1);
			this->tableLayoutPanel1->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 13;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 47.71242F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 52.28758F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 95)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 95)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 65)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 77)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 49)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 79)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 38)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 85)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 48)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 62)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 65)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(316, 927);
			this->tableLayoutPanel1->TabIndex = 31;
			// 
			// trackBarThresholdLarge
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->trackBarThresholdLarge, 3);
			this->trackBarThresholdLarge->Location = System::Drawing::Point(3, 669);
			this->trackBarThresholdLarge->Maximum = 255;
			this->trackBarThresholdLarge->Name = L"trackBarThresholdLarge";
			this->trackBarThresholdLarge->Size = System::Drawing::Size(310, 69);
			this->trackBarThresholdLarge->TabIndex = 36;
			this->trackBarThresholdLarge->Value = 100;
			this->trackBarThresholdLarge->Scroll += gcnew System::EventHandler(this, &MyForm::trackBarThresholdLarge_Scroll);
			// 
			// buttonRefresh
			// 
			this->buttonRefresh->Location = System::Drawing::Point(107, 171);
			this->buttonRefresh->Name = L"buttonRefresh";
			this->buttonRefresh->Size = System::Drawing::Size(92, 51);
			this->buttonRefresh->TabIndex = 32;
			this->buttonRefresh->Text = L"Refresh";
			this->buttonRefresh->UseVisualStyleBackColor = true;
			this->buttonRefresh->Click += gcnew System::EventHandler(this, &MyForm::buttonRefresh_Click);
			// 
			// buttonPos
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->buttonPos, 3);
			this->buttonPos->Location = System::Drawing::Point(3, 864);
			this->buttonPos->Name = L"buttonPos";
			this->buttonPos->Size = System::Drawing::Size(309, 41);
			this->buttonPos->TabIndex = 33;
			this->buttonPos->Text = L"Show Position..";
			this->buttonPos->UseVisualStyleBackColor = true;
			this->buttonPos->Click += gcnew System::EventHandler(this, &MyForm::buttonPos_Click);
			// 
			// buttonFromFile
			// 
			this->buttonFromFile->Location = System::Drawing::Point(3, 83);
			this->buttonFromFile->Name = L"buttonFromFile";
			this->buttonFromFile->Size = System::Drawing::Size(98, 62);
			this->buttonFromFile->TabIndex = 34;
			this->buttonFromFile->Text = L"Image From file..";
			this->buttonFromFile->UseVisualStyleBackColor = true;
			this->buttonFromFile->Click += gcnew System::EventHandler(this, &MyForm::buttonFromFile_Click);
			// 
			// labelThreshLargeN
			// 
			this->labelThreshLargeN->AutoSize = true;
			this->labelThreshLargeN->Location = System::Drawing::Point(3, 628);
			this->labelThreshLargeN->Name = L"labelThreshLargeN";
			this->labelThreshLargeN->Size = System::Drawing::Size(94, 36);
			this->labelThreshLargeN->TabIndex = 35;
			this->labelThreshLargeN->Text = L"Threshold Large";
			// 
			// labelThresholdLarge
			// 
			this->labelThresholdLarge->AutoSize = true;
			this->labelThresholdLarge->Location = System::Drawing::Point(107, 628);
			this->labelThresholdLarge->Name = L"labelThresholdLarge";
			this->labelThresholdLarge->Size = System::Drawing::Size(38, 18);
			this->labelThresholdLarge->TabIndex = 37;
			this->labelThresholdLarge->Text = L"100";
			// 
			// buttonSetting
			// 
			this->buttonSetting->Location = System::Drawing::Point(211, 83);
			this->buttonSetting->Name = L"buttonSetting";
			this->buttonSetting->Size = System::Drawing::Size(101, 62);
			this->buttonSetting->TabIndex = 38;
			this->buttonSetting->Text = L"Setting";
			this->buttonSetting->UseVisualStyleBackColor = true;
			this->buttonSetting->Click += gcnew System::EventHandler(this, &MyForm::buttonSetting_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				19.04481F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				80.95518F)));
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->panel1, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->panel2, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(1696, 953);
			this->tableLayoutPanel2->TabIndex = 34;
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(3, 936);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(200, 14);
			this->panel1->TabIndex = 32;
			// 
			// panel2
			// 
			this->panel2->AutoScroll = true;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(326, 3);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1367, 927);
			this->panel2->TabIndex = 34;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1696, 953);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Name = L"MyForm";
			this->Text = L"f";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numUpDownCamIndex))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarAccurecy))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarThreshold))->EndInit();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarThresholdLarge))->EndInit();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		ImageProcess* FormImageProcess;
		bool ShowCam;
		int ComboIndexCam;
		int ComboIndexThreshold;
		DataForm^ df;
		Mat* img = new Mat();
		
		System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {}
		int imgUpdate();
		Bitmap^ getImage();
		System::Void numUpDownCamIndexf(System::Object^ sender, System::EventArgs^ e) {
			setting->CamIndex = int(numUpDownCamIndex->Value);
		}


		System::Void textPath_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
		//System::Void buttonBrowse_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void treeView1_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e) {}
		System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {}
		System::Void trackBarAccurecy_Scroll(System::Object^ sender, System::EventArgs^ e) {
			float value = static_cast<float> (trackBarAccurecy->Value) / static_cast<float> (trackBarAccurecy->Maximum);
			labelAccurecy->Text = value.ToString(CultureInfo::InvariantCulture);
			setting->accuracy = value;
		}

		System::Void trackBarThreshold_Scroll(System::Object^ sender, System::EventArgs^ e) {
			int value = trackBarThreshold->Value;
			labelThreshold->Text = value.ToString(CultureInfo::InvariantCulture);
			if (FormImageProcess != nullptr) {
				setting->imgThresh.Small = value;
			}
		}
		System::Void Connect_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void comboBoxCam_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void comboBoxThreshold_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void SetIndexButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}
		System::Void checkBoxMVS_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			setting->isMVS = checkBoxMVS->Checked;
		}
		void updateThresholdUI(int index);
		
		//void loadIni();
		//void saveIni();

		SETTING* setting;
	public:
		ImageProcess* getImageProcess();
		tempClass* getTempClass();
		static System::Drawing::Bitmap^ MatToBmp(cv::Mat* img, System::Drawing::Imaging::PixelFormat format);
		//static System::Drawing::Imaging::ColorPalette^ getGrayPalette();
		

private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {}

private: System::Void buttonPos_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void buttonDevice_Click(System::Object^ sender, System::EventArgs^ e);


private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}

private: System::Void buttonRefresh_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonFromFile_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void labelThresholdL_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void trackBarThresholdLarge_Scroll(System::Object^ sender, System::EventArgs^ e) {
	int value = trackBarThresholdLarge->Value;
	labelThresholdLarge->Text = value.ToString(CultureInfo::InvariantCulture);
	if (FormImageProcess != nullptr) {
		setting->imgThresh.Large = value;
	}
}
private: System::Void buttonSetting_Click(System::Object^ sender, System::EventArgs^ e);
};
}

struct FORM_SETTING {
	int CamIndex;
	int CamMode;
	int Threshold;
	int ThresholdMethod;
	std::string tempPath;
	bool MVS;
	double Accuracy;
};