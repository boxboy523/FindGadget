#pragma once
#include "../../ImageProcess/framework.h"

namespace WinForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// SettingForm에 대한 요약입니다.
	/// </summary>
	public ref class SettingForm : public System::Windows::Forms::Form
	{
	public:
		SettingForm(SETTING* set)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			approxContourBox->Checked = set->approxContour;
			histStretchBox->Checked = set->histogramStretch;
			trackBarSecondAcc->Value = int(set->secondAccuracy*100);
			labelAcc->Text = set->secondAccuracy.ToString();
			setting = set;
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~SettingForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::CheckBox^ approxContourBox;
	private: System::Windows::Forms::CheckBox^ histStretchBox;
	private: System::Windows::Forms::TrackBar^ trackBarSecondAcc;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ labelAcc;
	private: System::Windows::Forms::CheckBox^ usePointGroupBox;

	private: System::Windows::Forms::NumericUpDown^ numUpDownArea;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ Area;









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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->approxContourBox = (gcnew System::Windows::Forms::CheckBox());
			this->histStretchBox = (gcnew System::Windows::Forms::CheckBox());
			this->usePointGroupBox = (gcnew System::Windows::Forms::CheckBox());
			this->trackBarSecondAcc = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->labelAcc = (gcnew System::Windows::Forms::Label());
			this->numUpDownArea = (gcnew System::Windows::Forms::NumericUpDown());
			this->Area = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarSecondAcc))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numUpDownArea))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				190)));
			this->tableLayoutPanel1->Controls->Add(this->approxContourBox, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->histStretchBox, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->usePointGroupBox, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->trackBarSecondAcc, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->label1, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->labelAcc, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->numUpDownArea, 2, 3);
			this->tableLayoutPanel1->Controls->Add(this->Area, 1, 3);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 5;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 55.55556F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 44.44444F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 45)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 303)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(624, 490);
			this->tableLayoutPanel1->TabIndex = 0;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SettingForm::tableLayoutPanel1_Paint);
			// 
			// approxContourBox
			// 
			this->approxContourBox->AutoSize = true;
			this->approxContourBox->Location = System::Drawing::Point(3, 3);
			this->approxContourBox->Name = L"approxContourBox";
			this->approxContourBox->Size = System::Drawing::Size(204, 22);
			this->approxContourBox->TabIndex = 1;
			this->approxContourBox->Text = L"Approxmate Contour";
			this->approxContourBox->UseVisualStyleBackColor = true;
			this->approxContourBox->CheckedChanged += gcnew System::EventHandler(this, &SettingForm::approxContourBox_CheckedChanged);
			// 
			// histStretchBox
			// 
			this->histStretchBox->AutoSize = true;
			this->histStretchBox->Location = System::Drawing::Point(3, 54);
			this->histStretchBox->Name = L"histStretchBox";
			this->histStretchBox->Size = System::Drawing::Size(201, 22);
			this->histStretchBox->TabIndex = 2;
			this->histStretchBox->Text = L"Histogram Stretching";
			this->histStretchBox->UseVisualStyleBackColor = true;
			this->histStretchBox->CheckedChanged += gcnew System::EventHandler(this, &SettingForm::histStretchBox_CheckedChanged);
			// 
			// usePointGroupBox
			// 
			this->usePointGroupBox->AutoSize = true;
			this->usePointGroupBox->Checked = true;
			this->usePointGroupBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->usePointGroupBox->Location = System::Drawing::Point(3, 139);
			this->usePointGroupBox->Name = L"usePointGroupBox";
			this->usePointGroupBox->Size = System::Drawing::Size(166, 22);
			this->usePointGroupBox->TabIndex = 6;
			this->usePointGroupBox->Text = L"Use Point Group";
			this->usePointGroupBox->UseVisualStyleBackColor = true;
			this->usePointGroupBox->CheckedChanged += gcnew System::EventHandler(this, &SettingForm::usePointGroupBox_CheckedChanged);
			// 
			// trackBarSecondAcc
			// 
			this->tableLayoutPanel1->SetColumnSpan(this->trackBarSecondAcc, 2);
			this->trackBarSecondAcc->Location = System::Drawing::Point(220, 94);
			this->trackBarSecondAcc->Maximum = 100;
			this->trackBarSecondAcc->Name = L"trackBarSecondAcc";
			this->trackBarSecondAcc->Size = System::Drawing::Size(401, 39);
			this->trackBarSecondAcc->TabIndex = 3;
			this->trackBarSecondAcc->TickFrequency = 5;
			this->trackBarSecondAcc->Scroll += gcnew System::EventHandler(this, &SettingForm::trackBarSecondAcc_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(220, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(106, 18);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Object Ratio";
			// 
			// labelAcc
			// 
			this->labelAcc->AutoSize = true;
			this->labelAcc->Location = System::Drawing::Point(437, 51);
			this->labelAcc->Name = L"labelAcc";
			this->labelAcc->Size = System::Drawing::Size(34, 18);
			this->labelAcc->TabIndex = 5;
			this->labelAcc->Text = L"0.5";
			// 
			// numUpDownArea
			// 
			this->numUpDownArea->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numUpDownArea->Location = System::Drawing::Point(437, 139);
			this->numUpDownArea->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->numUpDownArea->Name = L"numUpDownArea";
			this->numUpDownArea->Size = System::Drawing::Size(120, 28);
			this->numUpDownArea->TabIndex = 7;
			this->numUpDownArea->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->numUpDownArea->ValueChanged += gcnew System::EventHandler(this, &SettingForm::numUpDownArea_ValueChanged);
			// 
			// Area
			// 
			this->Area->AutoSize = true;
			this->Area->Location = System::Drawing::Point(220, 136);
			this->Area->Name = L"Area";
			this->Area->Size = System::Drawing::Size(123, 18);
			this->Area->TabIndex = 8;
			this->Area->Text = L"Minimum Area";
			// 
			// SettingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 490);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"SettingForm";
			this->Text = L"SettingForm";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarSecondAcc))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numUpDownArea))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: 
	SETTING* setting;

	System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	System::Void approxContourBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (setting)
			setting->approxContour = approxContourBox->Checked;
	}
	System::Void histStretchBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (setting)
			setting->histogramStretch = histStretchBox->Checked;
	}
private: System::Void trackBarSecondAcc_Scroll(System::Object^ sender, System::EventArgs^ e) {
	float value = float(trackBarSecondAcc->Value)/100;
	labelAcc->Text = value.ToString();
	setting->secondAccuracy = value;
}
private: System::Void usePointGroupBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (setting)
		setting->usePointGroup = usePointGroupBox->Checked;
}
private: System::Void numUpDownArea_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	setting->minArea = int(numUpDownArea->Value);
}
};
}
