#pragma once
#include "FlightSearchAPI.h"
namespace GUI1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SearchHistoryForm
	/// </summary>
	public ref class SearchHistoryForm : public System::Windows::Forms::Form
	{
	public:
		SearchHistoryForm(User * user)
		{
			currentUser = user;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SearchHistoryForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: User * currentUser;
	private: System::Windows::Forms::TextBox^  SearchHistoryTextBox;
	protected:
	private: System::Windows::Forms::Button^  ClearSearchHistory;

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
			int i;
			IHaveAviationCode* mapElement;
			this->SearchHistoryTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ClearSearchHistory = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// SearchHistoryTextBox
			// 
			this->SearchHistoryTextBox->Location = System::Drawing::Point(50, 46);
			this->SearchHistoryTextBox->Multiline = true;
			this->SearchHistoryTextBox->Name = L"SearchHistoryTextBox";
			this->SearchHistoryTextBox->Size = System::Drawing::Size(350, 314);
			this->SearchHistoryTextBox->TabIndex = 0;
			this->SearchHistoryTextBox->Text = "";
			i = currentUser->GetPtrSearchHistory()->size() - 1;
			while (i >= 0)
			{
				mapElement = (*currentUser->GetPtrSearchHistory())[i];
				this->SearchHistoryTextBox->Text += gcnew String(("#" + mapElement->GetName() + " (" + mapElement->GetAviationCode() + ")").c_str()) + Environment::NewLine;
				i--;
			}
			// 
			// ClearSearchHistory
			// 
			this->ClearSearchHistory->Location = System::Drawing::Point(232, 367);
			this->ClearSearchHistory->Name = L"ClearSearchHistory";
			this->ClearSearchHistory->Size = System::Drawing::Size(128, 23);
			this->ClearSearchHistory->TabIndex = 1;
			this->ClearSearchHistory->Text = L"Clear Search History";
			this->ClearSearchHistory->UseVisualStyleBackColor = true;
			this->ClearSearchHistory->Click += gcnew System::EventHandler(this, &SearchHistoryForm::ClearSearchHistory_Click);
			// 
			// SearchHistoryForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(425, 423);
			this->Controls->Add(this->ClearSearchHistory);
			this->Controls->Add(this->SearchHistoryTextBox);
			this->Name = L"SearchHistoryForm";
			this->Text = L"SearchHistoryForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ClearSearchHistory_Click(System::Object^  sender, System::EventArgs^  e) {
		currentUser->ClearSearchHistory();
		SearchHistoryTextBox->Text = "";
	}
	};
}
