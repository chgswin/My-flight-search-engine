#pragma once

namespace GUI1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SearchPreferenceForm
	/// </summary>
	public ref class SearchPreferenceForm : public System::Windows::Forms::Form
	{
	public:
		SearchPreferenceForm(UserPreference* preference)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			thisPreference = preference;
			InitializeSelection();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SearchPreferenceForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: UserPreference* thisPreference;
	private: System::Windows::Forms::NumericUpDown^  NumberOfPassengersUpDown;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::NumericUpDown^  StopUpDown;

	private: System::Windows::Forms::Label^  label3;



	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::NumericUpDown^  PriceUpDown;
	private: System::Windows::Forms::NumericUpDown^  TimeUpDown;
	private: System::Windows::Forms::Button^  OKButton;



	protected:



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->NumberOfPassengersUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->StopUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->PriceUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->TimeUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->OKButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberOfPassengersUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->StopUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PriceUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TimeUpDown))->BeginInit();
			this->SuspendLayout();
			// 
			// NumberOfPassengersUpDown
			// 
			this->NumberOfPassengersUpDown->Location = System::Drawing::Point(130, 25);
			this->NumberOfPassengersUpDown->Name = L"NumberOfPassengersUpDown";
			this->NumberOfPassengersUpDown->Size = System::Drawing::Size(48, 20);
			this->NumberOfPassengersUpDown->TabIndex = 3;
			this->NumberOfPassengersUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(11, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(113, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Number of passengers";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(11, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(79, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Maximum stops";
			// 
			// StopUpDown
			// 
			this->StopUpDown->Location = System::Drawing::Point(130, 66);
			this->StopUpDown->Name = L"StopUpDown";
			this->StopUpDown->Size = System::Drawing::Size(48, 20);
			this->StopUpDown->TabIndex = 5;
			this->StopUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(212, 32);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(76, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Price less than";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(213, 68);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(75, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Time less than";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(383, 68);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(33, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"hours";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(381, 28);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(37, 13);
			this->label6->TabIndex = 8;
			this->label6->Text = L"dollars";
			// 
			// PriceUpDown
			// 
			this->PriceUpDown->Location = System::Drawing::Point(327, 27);
			this->PriceUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->PriceUpDown->Name = L"PriceUpDown";
			this->PriceUpDown->Size = System::Drawing::Size(48, 20);
			this->PriceUpDown->TabIndex = 5;
			this->PriceUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			// 
			// TimeUpDown
			// 
			this->TimeUpDown->Location = System::Drawing::Point(327, 66);
			this->TimeUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->TimeUpDown->Name = L"TimeUpDown";
			this->TimeUpDown->Size = System::Drawing::Size(48, 20);
			this->TimeUpDown->TabIndex = 5;
			this->TimeUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 48, 0, 0, 0 });
			// 
			// OKButton
			// 
			this->OKButton->Location = System::Drawing::Point(327, 121);
			this->OKButton->Name = L"OKButton";
			this->OKButton->Size = System::Drawing::Size(75, 23);
			this->OKButton->TabIndex = 9;
			this->OKButton->Text = L"OK\r\n";
			this->OKButton->UseVisualStyleBackColor = true;
			this->OKButton->Click += gcnew System::EventHandler(this, &SearchPreferenceForm::OKButton_Click);
			// 
			// SearchPreferenceForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(429, 156);
			this->Controls->Add(this->OKButton);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->TimeUpDown);
			this->Controls->Add(this->PriceUpDown);
			this->Controls->Add(this->StopUpDown);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->NumberOfPassengersUpDown);
			this->Name = L"SearchPreferenceForm";
			this->Text = L"SearchPreferenceForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberOfPassengersUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->StopUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PriceUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TimeUpDown))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void OKButton_Click(System::Object^  sender, System::EventArgs^  e) {
	thisPreference->SetNumberOfPassengers((int) NumberOfPassengersUpDown->Value);
	thisPreference->SetMaxTime( Time((int) TimeUpDown->Value , 0));
	thisPreference->SetMaxPrice((int) PriceUpDown->Value);
	thisPreference->SetMaxTransit((int) StopUpDown->Value);

	this->Close();
}
private: void InitializeSelection(void) {
	NumberOfPassengersUpDown->Value = thisPreference->GetNumberOfPassengers();
	TimeUpDown->Value = thisPreference->GetMaxTime().GetHour();
	PriceUpDown->Value = thisPreference->GetMaxPrice();
	StopUpDown->Value = thisPreference->GetMaxTransit();
}
};
}
