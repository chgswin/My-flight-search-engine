#pragma once
#include "FlightSearchAPI.h"
#include "main_form.h"

const string DEFAULT_DATA_FILE = "UserData.csv";
namespace GUI1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			userControl = UserControlSingleton::Instance();
			userControl->LoadData("UserData.csv");
			currentUser = nullptr;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
			userControl->SaveData(DEFAULT_DATA_FILE);
			if (userControl)
			{
				delete userControl;
			}
		}
	private: UserControlSingleton * userControl;
	private: User * currentUser;
	private: main_form ^ thisMainForm;

	private: System::Windows::Forms::GroupBox^  LogInGroup;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  LogInErrorLabel;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  PasswordLogInTextBox;
	private: System::Windows::Forms::TextBox^  UserNameLoginTextBox;
	private: System::Windows::Forms::GroupBox^  SignUpGroup;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  ReEnterTextBox;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  PasswordSignUpTextBox;
	private: System::Windows::Forms::TextBox^  UserNameSignUpTextBox;
	private: System::Windows::Forms::Label^  SignUpErrorLabel;


	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  textBox1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->LogInGroup = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->LogInErrorLabel = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->PasswordLogInTextBox = (gcnew System::Windows::Forms::TextBox());
			this->UserNameLoginTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SignUpGroup = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SignUpErrorLabel = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->ReEnterTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->PasswordSignUpTextBox = (gcnew System::Windows::Forms::TextBox());
			this->UserNameSignUpTextBox = (gcnew System::Windows::Forms::TextBox());
			this->LogInGroup->SuspendLayout();
			this->SignUpGroup->SuspendLayout();
			this->SuspendLayout();
			// 
			// LogInGroup
			// 
			this->LogInGroup->Controls->Add(this->button2);
			this->LogInGroup->Controls->Add(this->LogInErrorLabel);
			this->LogInGroup->Controls->Add(this->button1);
			this->LogInGroup->Controls->Add(this->label2);
			this->LogInGroup->Controls->Add(this->label1);
			this->LogInGroup->Controls->Add(this->PasswordLogInTextBox);
			this->LogInGroup->Controls->Add(this->UserNameLoginTextBox);
			this->LogInGroup->Location = System::Drawing::Point(143, 78);
			this->LogInGroup->Name = L"LogInGroup";
			this->LogInGroup->Size = System::Drawing::Size(325, 161);
			this->LogInGroup->TabIndex = 0;
			this->LogInGroup->TabStop = false;
			this->LogInGroup->Text = L"Login";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->Location = System::Drawing::Point(161, 110);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(121, 32);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Enter";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &LoginForm::button2_Click);
			// 
			// LogInErrorLabel
			// 
			this->LogInErrorLabel->AutoSize = true;
			this->LogInErrorLabel->ForeColor = System::Drawing::Color::Red;
			this->LogInErrorLabel->Location = System::Drawing::Point(101, 83);
			this->LogInErrorLabel->Name = L"LogInErrorLabel";
			this->LogInErrorLabel->Size = System::Drawing::Size(181, 13);
			this->LogInErrorLabel->TabIndex = 1;
			this->LogInErrorLabel->Text = L"username or password do not match.";
			this->LogInErrorLabel->Visible = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Red;
			this->button1->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Location = System::Drawing::Point(6, 110);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(136, 32);
			this->button1->TabIndex = 4;
			this->button1->Text = L"New user\?";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &LoginForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(18, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Password";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(18, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"UserName";
			// 
			// PasswordLogInTextBox
			// 
			this->PasswordLogInTextBox->Location = System::Drawing::Point(95, 55);
			this->PasswordLogInTextBox->Name = L"PasswordLogInTextBox";
			this->PasswordLogInTextBox->PasswordChar = '*';
			this->PasswordLogInTextBox->Size = System::Drawing::Size(205, 20);
			this->PasswordLogInTextBox->TabIndex = 2;
			// 
			// UserNameLoginTextBox
			// 
			this->UserNameLoginTextBox->Location = System::Drawing::Point(95, 19);
			this->UserNameLoginTextBox->Name = L"UserNameLoginTextBox";
			this->UserNameLoginTextBox->Size = System::Drawing::Size(205, 20);
			this->UserNameLoginTextBox->TabIndex = 1;
			// 
			// SignUpGroup
			// 
			this->SignUpGroup->Controls->Add(this->label5);
			this->SignUpGroup->Controls->Add(this->SignUpErrorLabel);
			this->SignUpGroup->Controls->Add(this->button3);
			this->SignUpGroup->Controls->Add(this->button4);
			this->SignUpGroup->Controls->Add(this->label4);
			this->SignUpGroup->Controls->Add(this->ReEnterTextBox);
			this->SignUpGroup->Controls->Add(this->label3);
			this->SignUpGroup->Controls->Add(this->textBox1);
			this->SignUpGroup->Controls->Add(this->PasswordSignUpTextBox);
			this->SignUpGroup->Controls->Add(this->UserNameSignUpTextBox);
			this->SignUpGroup->Location = System::Drawing::Point(143, 279);
			this->SignUpGroup->Name = L"SignUpGroup";
			this->SignUpGroup->Size = System::Drawing::Size(329, 208);
			this->SignUpGroup->TabIndex = 1;
			this->SignUpGroup->TabStop = false;
			this->SignUpGroup->Text = L"Sign up";
			this->SignUpGroup->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(1, 115);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(96, 13);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Re-enter password";
			// 
			// SignUpErrorLabel
			// 
			this->SignUpErrorLabel->AutoSize = true;
			this->SignUpErrorLabel->ForeColor = System::Drawing::Color::Red;
			this->SignUpErrorLabel->Location = System::Drawing::Point(57, 135);
			this->SignUpErrorLabel->Name = L"SignUpErrorLabel";
			this->SignUpErrorLabel->Size = System::Drawing::Size(247, 13);
			this->SignUpErrorLabel->TabIndex = 1;
			this->SignUpErrorLabel->Text = L"The password does not match. Please enter again.";
			this->SignUpErrorLabel->Visible = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::DodgerBlue;
			this->button3->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button3->Location = System::Drawing::Point(161, 159);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(121, 32);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Register";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &LoginForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Red;
			this->button4->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button4->Location = System::Drawing::Point(6, 159);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(136, 32);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Already Registered\?";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &LoginForm::button4_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(40, 75);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 13);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Password";
			// 
			// ReEnterTextBox
			// 
			this->ReEnterTextBox->Location = System::Drawing::Point(99, 112);
			this->ReEnterTextBox->Name = L"ReEnterTextBox";
			this->ReEnterTextBox->PasswordChar = '*';
			this->ReEnterTextBox->Size = System::Drawing::Size(205, 20);
			this->ReEnterTextBox->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(36, 34);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 13);
			this->label3->TabIndex = 1;
			this->label3->Text = L"UserName";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(55, 292);
			this->textBox1->Name = L"textBox1";
			this->textBox1->PasswordChar = '*';
			this->textBox1->Size = System::Drawing::Size(205, 20);
			this->textBox1->TabIndex = 0;
			// 
			// PasswordSignUpTextBox
			// 
			this->PasswordSignUpTextBox->Location = System::Drawing::Point(99, 72);
			this->PasswordSignUpTextBox->Name = L"PasswordSignUpTextBox";
			this->PasswordSignUpTextBox->PasswordChar = '*';
			this->PasswordSignUpTextBox->Size = System::Drawing::Size(205, 20);
			this->PasswordSignUpTextBox->TabIndex = 2;
			// 
			// UserNameSignUpTextBox
			// 
			this->UserNameSignUpTextBox->Location = System::Drawing::Point(99, 31);
			this->UserNameSignUpTextBox->Name = L"UserNameSignUpTextBox";
			this->UserNameSignUpTextBox->Size = System::Drawing::Size(205, 20);
			this->UserNameSignUpTextBox->TabIndex = 1;
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(599, 544);
			this->Controls->Add(this->SignUpGroup);
			this->Controls->Add(this->LogInGroup);
			this->Name = L"LoginForm";
			this->Text = L"LoginForm";
			this->LogInGroup->ResumeLayout(false);
			this->LogInGroup->PerformLayout();
			this->SignUpGroup->ResumeLayout(false);
			this->SignUpGroup->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	//
	//
	//
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		LogInGroup->Visible = false;
		SignUpGroup->Visible = true;
	}
	//
	//
	//
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		LogInGroup->Visible = true;
		SignUpGroup->Visible = false;
	}
	//
	//
	//
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	string userName, password;
	//
	//
	//
	if (UserNameLoginTextBox->Text == "")
	{
		LogInErrorLabel->Visible = true;
		LogInErrorLabel->Text = "Please enter the username.";
		return;
	}
	//
	//
	//
	if (PasswordLogInTextBox->Text == "")
	{
		LogInErrorLabel->Visible = true;
		LogInErrorLabel->Text = "Please enter the password.";
		return;
	}

	userName = msclr::interop::marshal_as<std::string>(UserNameLoginTextBox->Text);
	password = msclr::interop::marshal_as<std::string>(PasswordLogInTextBox->Text);

	currentUser = userControl->GetCurrentUser(userName, password);
	if (currentUser == nullptr)
	{
		LogInErrorLabel->Visible = true;
		LogInErrorLabel->Text = "User name and password do not match.";
		return;
	}

	thisMainForm = gcnew main_form(currentUser);
	this->Hide();
	if (thisMainForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		thisMainForm->Close();
		currentUser = nullptr;
	}
	PasswordLogInTextBox->Text = "";
	this->Show();
	;
	
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	Factory thisFactory;
	string userName, password;
	userName = msclr::interop::marshal_as<std::string>(UserNameSignUpTextBox->Text);
	password = msclr::interop::marshal_as<std::string>(PasswordSignUpTextBox->Text);
	if (userControl->IsUsernameTaken(userName))
	{
		SignUpErrorLabel->Visible = true;
		SignUpErrorLabel->Text = "This username is taken. Please try another.";
		return;
	}
	if (PasswordSignUpTextBox->Text != ReEnterTextBox->Text)
	{
		SignUpErrorLabel->Visible = true;
		SignUpErrorLabel->Text = "The passwords do not match. Please try again.";
		return;
	}
	vector<string> str;
	str.insert(str.end(), { "StandardUser", userName, password });
	userControl->AddUser(thisFactory.CreateUser(str));
	SignUpErrorLabel->Visible = true;
	SignUpErrorLabel->Text = "Succesfully registered.";
}
};
}
