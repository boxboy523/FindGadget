#pragma once
#include "MyForm.h"

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
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->buttonCamTemp = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBoxThreshold = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBoxImage = (gcnew System::Windows::Forms::ComboBox());
			this->trackBarThreshold = (gcnew System::Windows::Forms::TrackBar());
			this->labelThreshold = (gcnew System::Windows::Forms::Label());
			this->buttonFileTemp = (gcnew System::Windows::Forms::Button());
			this->textBoxPath = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numUpDownIndex))->BeginInit();
			this->panel1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarThreshold))->BeginInit();
			this->tableLayoutPanel2->SuspendLayout();
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
			this->numUpDownIndex->Location = System::Drawing::Point(153, 377);
			this->numUpDownIndex->Name = L"numUpDownIndex";
			this->numUpDownIndex->Size = System::Drawing::Size(120, 28);
			this->numUpDownIndex->TabIndex = 2;
			this->numUpDownIndex->ValueChanged += gcnew System::EventHandler(this, &TempForm::numUpDownIndex_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 374);
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
			this->label2->Location = System::Drawing::Point(31, 239);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 18);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Threshold";
			this->label2->Click += gcnew System::EventHandler(this, &TempForm::label2_Click);
			// 
			// buttonApply
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->buttonApply, 2);
			this->buttonApply->Location = System::Drawing::Point(3, 713);
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
			this->panel1->Size = System::Drawing::Size(974, 787);
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
			this->tableLayoutPanel1->Controls->Add(this->label5, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->buttonCamTemp, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->buttonApply, 0, 8);
			this->tableLayoutPanel1->Controls->Add(this->label4, 0, 7);
			this->tableLayoutPanel1->Controls->Add(this->comboBoxThreshold, 1, 7);
			this->tableLayoutPanel1->Controls->Add(this->label3, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->comboBoxImage, 1, 6);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->numUpDownIndex, 1, 5);
			this->tableLayoutPanel1->Controls->Add(this->trackBarThreshold, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->labelThreshold, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->buttonFileTemp, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBoxPath, 0, 2);
			this->tableLayoutPanel1->Location = System::Drawing::Point(983, 3);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 9;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 41.59292F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 58.40708F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 58)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 80)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 86)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 186)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 75)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 75)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 76)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(300, 787);
			this->tableLayoutPanel1->TabIndex = 10;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &TempForm::tableLayoutPanel1_Paint);
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
			this->buttonCamTemp->Location = System::Drawing::Point(153, 65);
			this->buttonCamTemp->Name = L"buttonCamTemp";
			this->buttonCamTemp->Size = System::Drawing::Size(138, 44);
			this->buttonCamTemp->TabIndex = 15;
			this->buttonCamTemp->Text = L"From cam...";
			this->buttonCamTemp->UseVisualStyleBackColor = true;
			this->buttonCamTemp->Click += gcnew System::EventHandler(this, &TempForm::buttonCamTemp_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 635);
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
			this->comboBoxThreshold->Location = System::Drawing::Point(153, 638);
			this->comboBoxThreshold->Name = L"comboBoxThreshold";
			this->comboBoxThreshold->Size = System::Drawing::Size(121, 26);
			this->comboBoxThreshold->TabIndex = 10;
			this->comboBoxThreshold->SelectedIndexChanged += gcnew System::EventHandler(this, &TempForm::comboBoxThreshold_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 560);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(97, 18);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Image type";
			// 
			// comboBoxImage
			// 
			this->comboBoxImage->FormattingEnabled = true;
			this->comboBoxImage->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Normal", L"Gray", L"Threshold" });
			this->comboBoxImage->Location = System::Drawing::Point(153, 563);
			this->comboBoxImage->Name = L"comboBoxImage";
			this->comboBoxImage->Size = System::Drawing::Size(121, 26);
			this->comboBoxImage->TabIndex = 7;
			this->comboBoxImage->SelectedIndexChanged += gcnew System::EventHandler(this, &TempForm::comboBoxImage_SelectedIndexChanged);
			// 
			// trackBarThreshold
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->trackBarThreshold, 2);
			this->trackBarThreshold->Location = System::Drawing::Point(3, 291);
			this->trackBarThreshold->Maximum = 255;
			this->trackBarThreshold->Name = L"trackBarThreshold";
			this->trackBarThreshold->Size = System::Drawing::Size(288, 69);
			this->trackBarThreshold->TabIndex = 11;
			this->trackBarThreshold->Scroll += gcnew System::EventHandler(this, &TempForm::trackBarThreshold_Scroll);
			// 
			// labelThreshold
			// 
			this->labelThreshold->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelThreshold->AutoSize = true;
			this->labelThreshold->Location = System::Drawing::Point(216, 239);
			this->labelThreshold->Name = L"labelThreshold";
			this->labelThreshold->Size = System::Drawing::Size(18, 18);
			this->labelThreshold->TabIndex = 12;
			this->labelThreshold->Text = L"0";
			// 
			// buttonFileTemp
			// 
			this->buttonFileTemp->Location = System::Drawing::Point(3, 65);
			this->buttonFileTemp->Name = L"buttonFileTemp";
			this->buttonFileTemp->Size = System::Drawing::Size(135, 44);
			this->buttonFileTemp->TabIndex = 14;
			this->buttonFileTemp->Text = L"From file...";
			this->buttonFileTemp->UseVisualStyleBackColor = true;
			this->buttonFileTemp->Click += gcnew System::EventHandler(this, &TempForm::buttonFileTemp_Click);
			// 
			// textBoxPath
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->textBoxPath, 2);
			this->textBoxPath->Location = System::Drawing::Point(3, 153);
			this->textBoxPath->Name = L"textBoxPath";
			this->textBoxPath->Size = System::Drawing::Size(288, 28);
			this->textBoxPath->TabIndex = 16;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				306)));
			this->tableLayoutPanel2->Controls->Add(this->panel1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel1, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(1286, 793);
			this->tableLayoutPanel2->TabIndex = 11;
			// 
			// TempForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1286, 793);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarThreshold))->EndInit();
			this->tableLayoutPanel2->ResumeLayout(false);
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
};
}
