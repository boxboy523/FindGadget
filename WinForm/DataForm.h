#pragma once
#include "../getDeviceList/getDeviceList.h"


namespace WinForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// DataForm에 대한 요약입니다.
	/// </summary>
	ref class MyForm;
/*
디자인을 수정할 때에는 위의 클래스 선언문을 주석처리하고 수정하세요.
그러지 않으면 위의 선언문의 클래스를 창으로 인식합니다.
*/

	public ref class DataForm : public System::Windows::Forms::Form
	{
	public:
		DataForm(MyForm^ form, int m )// mode 0: position of object, mode 1: device
			{
				mode = m;
				InitializeComponent();
				//
				//TODO: 생성자 코드를 여기에 추가합니다.
				//
				parentForm = form;
				initTable();
				switch (mode) {
				case 0:
					updatePositionTable();
					break;
				case 1:
					updateDeviceTable();
					break;
				default:
					break;
				}

			}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~DataForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView;
	private: System::Windows::Forms::Button^ button1;
	protected:

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
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Location = System::Drawing::Point(0, 0);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->RowHeadersWidth = 62;
			this->dataGridView->RowTemplate->Height = 30;
			this->dataGridView->Size = System::Drawing::Size(750, 545);
			this->dataGridView->TabIndex = 0;
			this->dataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DataForm::dataGridView_CellContentClick);
			this->button1->Location = System::Drawing::Point(879, 95);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"update";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &DataForm::button1_Click);
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1099, 562);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView);
			this->Name = L"DataForm";
			this->Text = L"DataForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		MyForm^ parentForm;
		DataTable^ table;
	public: 
		void updatePositionTable();
		HRESULT updateDeviceTable();
		int updateMVSDeviceTable();
		void initTable();
	private: 
		int mode;
		System::Void dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {}
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			switch (mode) {
			case 0:
				updatePositionTable();
				break;
			case 1:
				updateDeviceTable();
				break;
			case 2:
				updateMVSDeviceTable();
				break;
			default:
				break;
			}
				
		}
	};
}
