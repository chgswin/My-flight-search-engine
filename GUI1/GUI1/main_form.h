#pragma once
#include "FlightsDetailForm.h"
#include "FlightSearchAPI.h"
#include "SearchPreferenceForm.h"
#include "ExploreForm.h"
#include "SearchHistoryForm.h"

const int NUMBER_GROUP = 4;
const int NUMBER_SEARCH_RESULT = 50;
const int FIRST_GROUP_X = 120;
const int FIRST_GROUP_Y = 260;
const int GROUP_WIDTH = 600;
const int GROUP_HEIGHT = 80;
const int GROUP_SPACE_Y = 90;
const int TIME_X = 40;
const int TIME_Y = 20;
const int TIME_WIDTH = 45;
const int TIME_HEIGHT = 16;
const int TIME_TRAVELLED_X = 150;
const int TIME_TRAVELLED_Y = 20;
const int TIME_TRAVELLED_WIDTH = 103;
const int TIME_TRAVELLED_HEIGHT = 16;
const int NUMBERSTOPS_X = 280;
const int NUMBERSTOPS_Y = 20;
const int NUMBERSTOPS_WIDTH = 109;
const int NUMBERSTOPS_HEIGHT = 16;
const int PRICE_X = 430;
const int PRICE_Y = 20;
const int PRICE_WIDTH = 48;
const int PRICE_HEIGHT = 16;
const int CARRIER_X = 40;
const int CARRIER_Y = 50;
const int CARRIER_WIDTH = 44;
const int CARRIER_HEIGHT = 13;
const int AIRPORT_X = 150;
const int AIRPORT_Y = 50;
const int AIRPORT_WIDTH = 63;
const int AIRPORT_HEIGHT = 13;
const int TRANSIT_X = 280;
const int TRANSIT_Y = 50;
const int TRANSIT_WIDTH = 63;
const int TRANSIT_HEIGHT = 13;
const int EXPLORE_BUTTON_X = 500;
const int EXPLORE_BUTTON_Y = 30;
const int EXPLORE_BUTTON_WIDTH = 75;
const int EXPLORE_BUTTON_HEIGHT = 25;

namespace GUI1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for main_form
	/// </summary>
	public ref class main_form : public System::Windows::Forms::Form
	{
	public:
		main_form(User* user)
		{
			map = MapSingleton::Instance();
			map->LoadData("MapData.csv");
			map->Organize();
			currentUser = user;
			res = nullptr;
			ResetMinIndex();
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~main_form()
		{
			if (components)
			{
				delete components;
			}

			if (map)
			{
				delete map;
			}
		}
	private: int minIndex;
	private: MapSingleton * map;
	private: User * currentUser;
	private: vector<MultiFlights> * res;
	private: System::Windows::Forms::Button^  GoButton;
	private: System::Windows::Forms::ComboBox^  originBox;
	private: System::Windows::Forms::ComboBox^  destinationBox;
	private: System::Windows::Forms::RadioButton^  searchByPriceRadio;
	private: System::Windows::Forms::RadioButton^  searchByTimeRadio;
	private: System::Windows::Forms::ComboBox^  FlightRankBox;
	private: System::Windows::Forms::Label^  OriginErrorText;
	private: System::Windows::Forms::Label^  DestinationErrorText;
	private: System::Windows::Forms::Label^  numberRoutesFoundText;
	private: System::Windows::Forms::GroupBox^  UserInfoGroup;
	private: System::Windows::Forms::Label^  UserNameLabel;
	private: System::Windows::Forms::Button^  LogOutButton;
	private: System::Windows::Forms::Button^  AdvancedSearchButton;
	private: System::Windows::Forms::Button^  Explore;
	private: System::Windows::Forms::Button^  SearchHistoryButton;
	private: System::Windows::Forms::Button^  AdminControlButton;
	private: System::Windows::Forms::Button^  MoreButton;
	private: System::Windows::Forms::Button^  LessButton;
	private: System::Windows::Forms::GroupBox^  QuickSearchGroup;

	private: cli::array<System::Windows::Forms::GroupBox^> ^MultiFlightGroupBoxArr;
	private: cli::array<System::Windows::Forms::Button^> ^MultiFlightExploreButton;
	private: cli::array<System::Windows::Forms::Label^> ^TimeLabelArr;
	private: cli::array<System::Windows::Forms::Label^> ^TimeTravelledLabelArr;
	private: cli::array<System::Windows::Forms::Label^> ^NumberStopsLabelArr;
	private: cli::array<System::Windows::Forms::Label^> ^PriceLabelArr;
	private: cli::array<System::Windows::Forms::Label^> ^CarrierLabelArr;
	private: cli::array<System::Windows::Forms::Label^> ^AirportInforLabelArr;
	private: cli::array<System::Windows::Forms::Label^> ^TransitLabelArr;

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
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(main_form::typeid));
				 this->GoButton = (gcnew System::Windows::Forms::Button());
				 this->originBox = (gcnew System::Windows::Forms::ComboBox());
				 this->destinationBox = (gcnew System::Windows::Forms::ComboBox());
				 this->searchByTimeRadio = (gcnew System::Windows::Forms::RadioButton());
				 this->FlightRankBox = (gcnew System::Windows::Forms::ComboBox());
				 this->OriginErrorText = (gcnew System::Windows::Forms::Label());
				 this->DestinationErrorText = (gcnew System::Windows::Forms::Label());
				 this->numberRoutesFoundText = (gcnew System::Windows::Forms::Label());
				 this->UserInfoGroup = (gcnew System::Windows::Forms::GroupBox());
				 this->AdminControlButton = (gcnew System::Windows::Forms::Button());
				 this->SearchHistoryButton = (gcnew System::Windows::Forms::Button());
				 this->Explore = (gcnew System::Windows::Forms::Button());
				 this->LogOutButton = (gcnew System::Windows::Forms::Button());
				 this->UserNameLabel = (gcnew System::Windows::Forms::Label());
				 this->AdvancedSearchButton = (gcnew System::Windows::Forms::Button());
				 this->MoreButton = (gcnew System::Windows::Forms::Button());
				 this->QuickSearchGroup = (gcnew System::Windows::Forms::GroupBox());
				 this->searchByPriceRadio = (gcnew System::Windows::Forms::RadioButton());
				 this->LessButton = (gcnew System::Windows::Forms::Button());
				 this->UserInfoGroup->SuspendLayout();
				 this->QuickSearchGroup->SuspendLayout();

				 this->MultiFlightGroupBoxArr = gcnew cli::array<System::Windows::Forms::GroupBox^>(NUMBER_GROUP);
				 this->MultiFlightExploreButton = gcnew cli::array<System::Windows::Forms::Button^>(NUMBER_GROUP);
				 this->TimeLabelArr = gcnew cli::array<System::Windows::Forms::Label^>(NUMBER_GROUP);
				 this->TimeTravelledLabelArr = gcnew cli::array<System::Windows::Forms::Label^>(NUMBER_GROUP);

				 NumberStopsLabelArr = gcnew cli::array<System::Windows::Forms::Label^>(NUMBER_GROUP);
				 PriceLabelArr = gcnew cli::array<System::Windows::Forms::Label^>(NUMBER_GROUP);
				 CarrierLabelArr = gcnew cli::array<System::Windows::Forms::Label^>(NUMBER_GROUP);
				 AirportInforLabelArr = gcnew cli::array<System::Windows::Forms::Label^>(NUMBER_GROUP);
				 TransitLabelArr = gcnew cli::array<System::Windows::Forms::Label^>(NUMBER_GROUP);

				 //this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
				 //this->MoreInfo1Button = (gcnew System::Windows::Forms::Button());
				 //this->carrierName1 = (gcnew System::Windows::Forms::Label());
				 //PriceLabelArr[i] = (gcnew System::Windows::Forms::Label());
				 //this->transitList1 = (gcnew System::Windows::Forms::Label());
				 //this->numberStops1 = (gcnew System::Windows::Forms::Label());
				 //this->airportInfo1 = (gcnew System::Windows::Forms::Label());
				 //this->timeTravelled1 = (gcnew System::Windows::Forms::Label());
				 //this->Time1 = (gcnew System::Windows::Forms::Label());
				 //this->groupBox1->SuspendLayout();

				 this->SuspendLayout();
				 // 
				 // GoButton
				 // 
				 this->GoButton->BackColor = System::Drawing::Color::Red;
				 this->GoButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
				 this->GoButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->GoButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
				 this->GoButton->ForeColor = System::Drawing::Color::Snow;
				 this->GoButton->Location = System::Drawing::Point(633, 199);
				 this->GoButton->Name = L"GoButton";
				 this->GoButton->Size = System::Drawing::Size(75, 39);
				 this->GoButton->TabIndex = 4;
				 this->GoButton->Text = L"Go!";
				 this->GoButton->UseVisualStyleBackColor = false;
				 this->GoButton->Click += gcnew System::EventHandler(this, &main_form::GoButton_Click);
				 // 
				 // originBox
				 // 
				 this->originBox->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(4) {
					 L"Melbourne", L"Sydney", L"Perth",
						 L"Darwin"
				 });
				 this->originBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
				 this->originBox->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
				 this->originBox->BackColor = System::Drawing::SystemColors::Info;
				 this->originBox->FormattingEnabled = true;
				 this->originBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Melbourne", L"Sydney", L"Perth", L"Brisbane" });
				 this->originBox->Location = System::Drawing::Point(189, 118);
				 this->originBox->Name = L"originBox";
				 this->originBox->Size = System::Drawing::Size(211, 21);
				 this->originBox->TabIndex = 1;
				 this->originBox->Text = L"Type your departure city.";
				 // 
				 // destinationBox
				 // 
				 this->destinationBox->BackColor = System::Drawing::SystemColors::Info;
				 this->destinationBox->FormattingEnabled = true;
				 this->destinationBox->Location = System::Drawing::Point(426, 118);
				 this->destinationBox->MaxDropDownItems = 10;
				 this->destinationBox->Name = L"destinationBox";
				 this->destinationBox->Size = System::Drawing::Size(195, 21);
				 this->destinationBox->TabIndex = 2;
				 this->destinationBox->Text = L"Try \'MEL\', \'Sydney\'";
				 // 
				 // searchByTimeRadio
				 // 
				 this->searchByTimeRadio->AutoSize = true;
				 this->searchByTimeRadio->BackColor = System::Drawing::Color::SteelBlue;
				 this->searchByTimeRadio->ForeColor = System::Drawing::Color::Transparent;
				 this->searchByTimeRadio->Location = System::Drawing::Point(429, 175);
				 this->searchByTimeRadio->Name = L"searchByTimeRadio";
				 this->searchByTimeRadio->Size = System::Drawing::Size(98, 17);
				 this->searchByTimeRadio->TabIndex = 10;
				 this->searchByTimeRadio->TabStop = true;
				 this->searchByTimeRadio->Text = L"Looking for shortest time flights.";
				 this->searchByTimeRadio->UseVisualStyleBackColor = false;
				 // 
				 // FlightRankBox
				 // 
				 this->FlightRankBox->FormattingEnabled = true;
				 this->FlightRankBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"ECONOMY", L"BUSINESS" });
				 this->FlightRankBox->Location = System::Drawing::Point(189, 91);
				 this->FlightRankBox->Name = L"FlightRankBox";
				 this->FlightRankBox->Size = System::Drawing::Size(211, 21);
				 this->FlightRankBox->TabIndex = 3;
				 this->FlightRankBox->SelectedItem = "ECONOMY";
				 // 
				 // OriginErrorText
				 // 
				 this->OriginErrorText->AutoSize = true;
				 this->OriginErrorText->BackColor = System::Drawing::Color::SteelBlue;
				 this->OriginErrorText->ForeColor = System::Drawing::Color::Red;
				 this->OriginErrorText->Location = System::Drawing::Point(205, 149);
				 this->OriginErrorText->Name = L"OriginErrorText";
				 this->OriginErrorText->Size = System::Drawing::Size(137, 13);
				 this->OriginErrorText->Text = L"We cannot find your place.";
				 this->OriginErrorText->Visible = false;
				 // 
				 // DestinationErrorText
				 // 
				 this->DestinationErrorText->AutoSize = true;
				 this->DestinationErrorText->BackColor = System::Drawing::Color::SteelBlue;
				 this->DestinationErrorText->ForeColor = System::Drawing::Color::Red;
				 this->DestinationErrorText->Location = System::Drawing::Point(426, 149);
				 this->DestinationErrorText->Name = L"DestinationErrorText";
				 this->DestinationErrorText->Size = System::Drawing::Size(137, 13);
				 this->DestinationErrorText->Text = L"We cannot find your place.";
				 this->DestinationErrorText->Visible = false;
				 // 
				 // numberRoutesFoundText
				 // 
				 this->numberRoutesFoundText->AutoSize = true;
				 this->numberRoutesFoundText->ForeColor = System::Drawing::Color::Red;
				 this->numberRoutesFoundText->Location = System::Drawing::Point(17, 140);
				 this->numberRoutesFoundText->Name = L"numberRoutesFoundText";
				 this->numberRoutesFoundText->Size = System::Drawing::Size(35, 13);
				 this->numberRoutesFoundText->Text = L"label1";
				 this->numberRoutesFoundText->Visible = false;
				 // 
				 // UserInfoGroup
				 // 
				 this->UserInfoGroup->BackColor = System::Drawing::SystemColors::ControlDarkDark;
				 this->UserInfoGroup->Controls->Add(this->AdminControlButton);
				 this->UserInfoGroup->Controls->Add(this->SearchHistoryButton);
				 this->UserInfoGroup->Controls->Add(this->Explore);
				 this->UserInfoGroup->Controls->Add(this->LogOutButton);
				 this->UserInfoGroup->Controls->Add(this->UserNameLabel);
				 this->UserInfoGroup->Location = System::Drawing::Point(13, 2);
				 this->UserInfoGroup->Name = L"UserInfoGroup";
				 this->UserInfoGroup->Size = System::Drawing::Size(771, 49);
				 this->UserInfoGroup->TabStop = false;
				 // 
				 // AdminControlButton
				 // 
				 this->AdminControlButton->BackColor = System::Drawing::Color::Brown;
				 this->AdminControlButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->AdminControlButton->ForeColor = System::Drawing::SystemColors::ButtonFace;
				 this->AdminControlButton->Location = System::Drawing::Point(426, 11);
				 this->AdminControlButton->Name = L"AdminControlButton";
				 this->AdminControlButton->Size = System::Drawing::Size(75, 28);
				 this->AdminControlButton->TabIndex = 18;
				 this->AdminControlButton->Text = L"Admin only";
				 this->AdminControlButton->UseVisualStyleBackColor = false;
				 this->AdminControlButton->Click += gcnew System::EventHandler(this, &main_form::AdminControlButton_Click);
				 // 
				 // SearchHistoryButton
				 // 
				 this->SearchHistoryButton->BackColor = System::Drawing::SystemColors::Highlight;
				 this->SearchHistoryButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->SearchHistoryButton->ForeColor = System::Drawing::SystemColors::ButtonFace;
				 this->SearchHistoryButton->Location = System::Drawing::Point(507, 10);
				 this->SearchHistoryButton->Name = L"SearchHistoryButton";
				 this->SearchHistoryButton->Size = System::Drawing::Size(96, 29);
				 this->SearchHistoryButton->TabIndex = 3;
				 this->SearchHistoryButton->Text = L"Search history";
				 this->SearchHistoryButton->UseVisualStyleBackColor = false;
				 this->SearchHistoryButton->Click += gcnew System::EventHandler(this, &main_form::SearchHistoryButton_Click);
				 // 
				 // Explore
				 // 
				 this->Explore->BackColor = System::Drawing::SystemColors::Highlight;
				 this->Explore->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
				 this->Explore->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->Explore->ForeColor = System::Drawing::SystemColors::ButtonFace;
				 this->Explore->Location = System::Drawing::Point(609, 10);
				 this->Explore->Name = L"Explore";
				 this->Explore->Size = System::Drawing::Size(75, 29);
				 this->Explore->TabIndex = 2;
				 this->Explore->Text = L"Explore";
				 this->Explore->UseVisualStyleBackColor = false;
				 this->Explore->Click += gcnew System::EventHandler(this, &main_form::Explore_Click);
				 // 
				 // LogOutButton
				 // 
				 this->LogOutButton->BackColor = System::Drawing::Color::Brown;
				 this->LogOutButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->LogOutButton->ForeColor = System::Drawing::Color::White;
				 this->LogOutButton->Location = System::Drawing::Point(690, 11);
				 this->LogOutButton->Name = L"LogOutButton";
				 this->LogOutButton->Size = System::Drawing::Size(75, 29);
				 this->LogOutButton->TabIndex = 1;
				 this->LogOutButton->Text = L"Log out";
				 this->LogOutButton->UseVisualStyleBackColor = false;
				 this->LogOutButton->Click += gcnew System::EventHandler(this, &main_form::LogOutButton_Click);
				 // 
				 // UserNameLabel
				 // 
				 this->UserNameLabel->AutoSize = true;
				 this->UserNameLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->UserNameLabel->ForeColor = System::Drawing::SystemColors::ButtonFace;
				 this->UserNameLabel->Location = System::Drawing::Point(6, 17);
				 this->UserNameLabel->Name = L"UserNameLabel";
				 this->UserNameLabel->Size = System::Drawing::Size(19, 16);
				 this->UserNameLabel->TabIndex = 0;
				 this->UserNameLabel->Text = gcnew String (("Hi" + currentUser->GetID()).c_str());
				 // 
				 // AdvancedSearchButton
				 // 
				 this->AdvancedSearchButton->BackColor = System::Drawing::SystemColors::Control;
				 this->AdvancedSearchButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
				 this->AdvancedSearchButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->AdvancedSearchButton->ForeColor = System::Drawing::Color::Black;
				 this->AdvancedSearchButton->Location = System::Drawing::Point(513, 205);
				 this->AdvancedSearchButton->Name = L"AdvancedSearchButton";
				 this->AdvancedSearchButton->Size = System::Drawing::Size(103, 24);
				 this->AdvancedSearchButton->TabIndex = 6;
				 this->AdvancedSearchButton->Text = L"Advanced Search";
				 this->AdvancedSearchButton->UseVisualStyleBackColor = false;
				 this->AdvancedSearchButton->Click += gcnew System::EventHandler(this, &main_form::AdvancedSearchButton_Click);
				 // 
				 // LessButton
				 // 
				 this->LessButton->BackColor = System::Drawing::Color::BlueViolet;
				 this->LessButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				 this->LessButton->Location = System::Drawing::Point(714, 260);
				 this->LessButton->Name = L"LessButton";
				 this->LessButton->Size = System::Drawing::Size(45, 23);
				 this->LessButton->TabIndex = 18;
				 this->LessButton->Text = L"Up";
				 this->LessButton->UseVisualStyleBackColor = false;
				 this->LessButton->Click += gcnew System::EventHandler(this, &main_form::LessButton_Click);
				 // 
				 // groupBox1
				 // 
				 // 
				 // MoreButton
				 // 
				 this->MoreButton->BackColor = System::Drawing::Color::BlueViolet;
				 this->MoreButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				 this->MoreButton->Location = System::Drawing::Point(714, 581);
				 this->MoreButton->Name = L"MoreButton";
				 this->MoreButton->Size = System::Drawing::Size(45, 23);
				 this->MoreButton->TabIndex = 18;
				 this->MoreButton->Text = L"down";
				 this->MoreButton->UseVisualStyleBackColor = false;
				 this->MoreButton->Click += gcnew System::EventHandler(this, &main_form::MoreButton_Click);
				 // 
				 // QuickSearchGroup
				 // 
				 this->QuickSearchGroup->BackColor = System::Drawing::Color::SteelBlue;
				 this->QuickSearchGroup->Controls->Add(this->numberRoutesFoundText);
				 this->QuickSearchGroup->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				 this->QuickSearchGroup->Location = System::Drawing::Point(122, 75);
				 this->QuickSearchGroup->Name = L"QuickSearchGroup";
				 this->QuickSearchGroup->Size = System::Drawing::Size(586, 163);
				 this->QuickSearchGroup->TabIndex = 19;
				 this->QuickSearchGroup->TabStop = false;
				 this->QuickSearchGroup->Text = L"Basic Search";
				 // 
				 // searchByPriceRadio
				 // 
				 this->searchByPriceRadio->AutoSize = true;
				 this->searchByPriceRadio->BackColor = System::Drawing::Color::SteelBlue;
				 this->searchByPriceRadio->Checked = true;
				 this->searchByPriceRadio->ForeColor = System::Drawing::Color::Transparent;
				 this->searchByPriceRadio->Location = System::Drawing::Point(200, 175);
				 this->searchByPriceRadio->Name = L"searchByPriceRadio";
				 this->searchByPriceRadio->Size = System::Drawing::Size(99, 17);
				 this->searchByPriceRadio->TabIndex = 9;
				 this->searchByPriceRadio->TabStop = true;
				 this->searchByPriceRadio->Text = L"Looking for cheapest flights.";
				 this->searchByPriceRadio->UseVisualStyleBackColor = false;

				 /*
				 //
				 //groupBox1
				 //
				 this->groupBox1->Controls->Add(this->MoreInfo1Button);
				 this->groupBox1->Controls->Add(this->carrierName1);
				 this->groupBox1->Controls->Add(PriceLabelArr[i]);
				 this->groupBox1->Controls->Add(this->transitList1);
				 this->groupBox1->Controls->Add(this->numberStops1);
				 this->groupBox1->Controls->Add(this->airportInfo1);
				 this->groupBox1->Controls->Add(this->timeTravelled1);
				 this->groupBox1->Controls->Add(this->Time1);
				 this->groupBox1->Location = System::Drawing::Point(122, 260);
				 this->groupBox1->Name = L"groupBox1";
				 this->groupBox1->Size = System::Drawing::Size(586, 76);
				 this->groupBox1->TabIndex = 8;
				 this->groupBox1->TabStop = false;
				 this->groupBox1->Text = L"#1";
				 this->groupBox1->Visible = false;
				 //
				 // MoreInfo1Button
				 //
				 this->MoreInfo1Button->Location = System::Drawing::Point(500, 30);
				 this->MoreInfo1Button->Name = L"MoreInfo1Button";
				 this->MoreInfo1Button->Size = System::Drawing::Size(75, 23);
				 this->MoreInfo1Button->TabIndex = 1;
				 this->MoreInfo1Button->Text = L"Explore";
				 this->MoreInfo1Button->UseVisualStyleBackColor = true;
				 this->MoreInfo1Button->Click += gcnew System::EventHandler(this, &main_form::button1_Click_1);
				 //
				 // carrierName1
				 //
				 this->carrierName1->AutoSize = true;
				 this->carrierName1->Location = System::Drawing::Point(40, 50);
				 this->carrierName1->Name = L"carrierName1";
				 this->carrierName1->Size = System::Drawing::Size(44, 13);
				 this->carrierName1->TabIndex = 0;
				 this->carrierName1->Text = L"carrier1";
				 this->carrierName1->Visible = false;
				 //
				 // price1
				 //
				 PriceLabelArr[i]->AutoSize = true;
				 PriceLabelArr[i]->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 PriceLabelArr[i]->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
				 PriceLabelArr[i]->Location = System::Drawing::Point(430, 20);
				 PriceLabelArr[i]->Name = L"price1";
				 PriceLabelArr[i]->Size = System::Drawing::Size(48, 16);
				 PriceLabelArr[i]->TabIndex = 0;
				 PriceLabelArr[i]->Text = L"price1";
				 PriceLabelArr[i]->Visible = false;
				 //
				 // transitList1
				 //
				 this->transitList1->AutoSize = true;
				 this->transitList1->Location = System::Drawing::Point(280, 50);
				 this->transitList1->Name = L"transitList1";
				 this->transitList1->Size = System::Drawing::Size(60, 13);
				 this->transitList1->TabIndex = 0;
				 this->transitList1->Text = L"transitList1";
				 this->transitList1->Visible = false;
				 //
				 // numberStops1
				 //
				 this->numberStops1->AutoSize = true;
				 this->numberStops1->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->numberStops1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
				 this->numberStops1->Location = System::Drawing::Point(280, 20);
				 this->numberStops1->Name = L"numberStops1";
				 this->numberStops1->Size = System::Drawing::Size(109, 16);
				 this->numberStops1->TabIndex = 0;
				 this->numberStops1->Text = L"numberOfStop1";
				 this->numberStops1->Visible = false;
				 //
				 // airportInfo1
				 //
				 this->airportInfo1->AutoSize = true;
				 this->airportInfo1->Location = System::Drawing::Point(150, 50);
				 this->airportInfo1->Name = L"airportInfo1";
				 this->airportInfo1->Size = System::Drawing::Size(63, 13);
				 this->airportInfo1->TabIndex = 0;
				 this->airportInfo1->Text = L"airportinfo1";
				 this->airportInfo1->Visible = false;
				 //
				 // timeTravelled1
				 //
				 this->timeTravelled1->AutoSize = true;
				 this->timeTravelled1->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->timeTravelled1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
				 this->timeTravelled1->Location = System::Drawing::Point(150, 20);
				 this->timeTravelled1->Name = L"timeTravelled1";
				 this->timeTravelled1->Size = System::Drawing::Size(103, 16);
				 this->timeTravelled1->TabIndex = 0;
				 this->timeTravelled1->Text = L"timeTravelled1";
				 this->timeTravelled1->Visible = false;
				 //
				 // Time1
				 //
				 this->Time1->AutoSize = true;
				 this->Time1->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->Time1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
				 this->Time1->Location = System::Drawing::Point(40, 20);
				 this->Time1->Name = L"Time1";
				 this->Time1->Size = System::Drawing::Size(45, 16);
				 this->Time1->TabIndex = 0;
				 this->Time1->Text = L"Time1";
				 this->Time1->Visible = false;
				 */
				for (i = 0; i < NUMBER_GROUP; ++i)
				{
					MultiFlightGroupBoxArr[i]	= gcnew System::Windows::Forms::GroupBox();
					MultiFlightExploreButton[i]	= gcnew System::Windows::Forms::Button();
					TimeLabelArr[i]				= gcnew System::Windows::Forms::Label();
					TimeTravelledLabelArr[i]	= gcnew System::Windows::Forms::Label();
					NumberStopsLabelArr[i]		= gcnew System::Windows::Forms::Label();
					CarrierLabelArr[i]			= gcnew System::Windows::Forms::Label();
					AirportInforLabelArr[i]		= gcnew System::Windows::Forms::Label();
					TransitLabelArr[i]			= gcnew System::Windows::Forms::Label();
					PriceLabelArr[i]			= gcnew System::Windows::Forms::Label();
					
					MultiFlightGroupBoxArr[i]->SuspendLayout();
					MultiFlightGroupBoxArr[i]->Controls->Add(MultiFlightExploreButton[i]);
					MultiFlightGroupBoxArr[i]->Controls->Add(TimeLabelArr[i]);
					MultiFlightGroupBoxArr[i]->Controls->Add(TimeTravelledLabelArr[i]);
					MultiFlightGroupBoxArr[i]->Controls->Add(NumberStopsLabelArr[i]);
					MultiFlightGroupBoxArr[i]->Controls->Add(CarrierLabelArr[i]);
					MultiFlightGroupBoxArr[i]->Controls->Add(AirportInforLabelArr[i]);
					MultiFlightGroupBoxArr[i]->Controls->Add(TransitLabelArr[i]);
					MultiFlightGroupBoxArr[i]->Controls->Add(PriceLabelArr[i]);

					MultiFlightGroupBoxArr[i]->Location = System::Drawing::Point(FIRST_GROUP_X, FIRST_GROUP_Y + GROUP_SPACE_Y * i);
					MultiFlightGroupBoxArr[i]->Size = System::Drawing::Size(GROUP_WIDTH, GROUP_HEIGHT);
					MultiFlightGroupBoxArr[i]->TabIndex = 8;
					MultiFlightGroupBoxArr[i]->TabStop = false;
					MultiFlightGroupBoxArr[i]->Visible = false;
					
					MultiFlightExploreButton[i]->Location = System::Drawing::Point(EXPLORE_BUTTON_X, EXPLORE_BUTTON_Y);
					MultiFlightExploreButton[i]->Size = System::Drawing::Size(EXPLORE_BUTTON_WIDTH, EXPLORE_BUTTON_HEIGHT);
					MultiFlightExploreButton[i]->Text = L"Explore";
					MultiFlightExploreButton[i]->TabIndex = 1;
					MultiFlightExploreButton[i]->UseVisualStyleBackColor = true;
					//MultiFlightExploreButton[i]->Click += gcnew System::EventHandler(this, &main_form::button1_Click_1);
					
					TimeLabelArr[i]->AutoSize = true;
					TimeLabelArr[i]->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					TimeLabelArr[i]->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
					TimeLabelArr[i]->Location = System::Drawing::Point(40, 20);
					//TimeLabelArr[i]->Name = L"Time1";
					TimeLabelArr[i]->Size = System::Drawing::Size(45, 16);
					TimeLabelArr[i]->TabIndex = 0;
					//TimeLabelArr[i]->Text = L"Time1";
					TimeLabelArr[i]->Visible = false;

					CarrierLabelArr[i]->AutoSize = true;
					CarrierLabelArr[i]->Location = System::Drawing::Point(40, 50);
					//CarrierLabelArr[i]->Name = L"carrierName1";
					CarrierLabelArr[i]->Size = System::Drawing::Size(44, 13);
					CarrierLabelArr[i]->TabIndex = 0;
					//CarrierLabelArr[i]->Text = L"carrier1";
					CarrierLabelArr[i]->Visible = false;
					//
					// price
					//
					PriceLabelArr[i]->AutoSize = true;
					PriceLabelArr[i]->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					PriceLabelArr[i]->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
					PriceLabelArr[i]->Location = System::Drawing::Point(430, 20);
					//PriceLabelArr[i]->Name = L"price1";
					PriceLabelArr[i]->Size = System::Drawing::Size(48, 16);
					PriceLabelArr[i]->TabIndex = 0;
					//PriceLabelArr[i]->Text = L"price1";
					PriceLabelArr[i]->Visible = false;
					//
					// transitList1
					//
					TransitLabelArr[i]->AutoSize = true;
					TransitLabelArr[i]->Location = System::Drawing::Point(280, 50);
					//TransitLabelArr[i]->Name = L"transitList1";
					TransitLabelArr[i]->Size = System::Drawing::Size(60, 13);
					TransitLabelArr[i]->TabIndex = 0;
					//TransitLabelArr[i]->Text = L"transitList1";
					TransitLabelArr[i]->Visible = false;
					//
					// numberStops1
					//
					NumberStopsLabelArr[i]->AutoSize = true;
					NumberStopsLabelArr[i]->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					NumberStopsLabelArr[i]->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
					NumberStopsLabelArr[i]->Location = System::Drawing::Point(280, 20);
					//NumberStopsLabelArr[i]->Name = L"numberStops1";
					NumberStopsLabelArr[i]->Size = System::Drawing::Size(109, 16);
					NumberStopsLabelArr[i]->TabIndex = 0;
					//NumberStopsLabelArr[i]->Text = L"numberOfStop1";
					NumberStopsLabelArr[i]->Visible = false;
					//
					// airportInfo1
					//
					AirportInforLabelArr[i]->AutoSize = true;
					AirportInforLabelArr[i]->Location = System::Drawing::Point(170, 50);
					AirportInforLabelArr[i]->Name = L"airportInfo1";
					AirportInforLabelArr[i]->Size = System::Drawing::Size(63, 13);
					AirportInforLabelArr[i]->TabIndex = 0;
					AirportInforLabelArr[i]->Text = L"airportinfo1";
					AirportInforLabelArr[i]->Visible = false;
					//
					// timeTravelled1
					//
					TimeTravelledLabelArr[i]->AutoSize = true;
					TimeTravelledLabelArr[i]->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					TimeTravelledLabelArr[i]->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
					TimeTravelledLabelArr[i]->Location = System::Drawing::Point(150, 20);
					//TimeTravelledLabelArr[i]->Name = L"timeTravelled1";
					TimeTravelledLabelArr[i]->Size = System::Drawing::Size(103, 16);
					TimeTravelledLabelArr[i]->TabIndex = 0;
					//TimeTravelledLabelArr[i]->Text = L"timeTravelled1";
					TimeTravelledLabelArr[i]->Visible = false;
					//
					//
					//
					MultiFlightExploreButton[i]->Click += gcnew System::EventHandler(this, &main_form::MultiFlightDetail_Click);
					//
					//allows the main_form to control the group box
					//
					this->Controls->Add(MultiFlightGroupBoxArr[i]);
					//
					//
					//
					MultiFlightGroupBoxArr[i]->ResumeLayout(false);
					MultiFlightGroupBoxArr[i]->PerformLayout();
				}
				 // 
				 // main_form
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
				 this->ClientSize = System::Drawing::Size(796, 686);
				 this->Controls->Add(this->MoreButton);
				 this->Controls->Add(this->AdvancedSearchButton);
				 this->Controls->Add(this->UserInfoGroup);
				 this->Controls->Add(this->LessButton);
				 this->Controls->Add(this->DestinationErrorText);
				 this->Controls->Add(this->OriginErrorText);
				 this->Controls->Add(this->FlightRankBox);
				 this->Controls->Add(this->searchByTimeRadio);
				 this->Controls->Add(this->searchByPriceRadio);
				 this->Controls->Add(this->destinationBox);
				 this->Controls->Add(this->originBox);
				 this->Controls->Add(this->GoButton);
				 this->Controls->Add(this->QuickSearchGroup);
				 this->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F));
				 this->ForeColor = System::Drawing::SystemColors::ActiveCaption;
				 this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
				 this->Name = L"main_form";
				 this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Show;
				 this->Text = L"MyFlightSearch";
				 this->UserInfoGroup->ResumeLayout(false);
				 this->UserInfoGroup->PerformLayout();
				 //this->groupBox1->ResumeLayout(false);
				 //this->groupBox1->PerformLayout();
				 this->QuickSearchGroup->ResumeLayout(false);
				 this->QuickSearchGroup->PerformLayout();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion

	private: System::Void GoButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ResetMinIndex();
		int numberRes = NUMBER_SEARCH_RESULT;
		Search mainSearch;
		static vector<MultiFlights> result;
		Airport* origin; Airport* destination;
		string originText = msclr::interop::marshal_as<std::string>(originBox->Text);
		string destinationText = msclr::interop::marshal_as<std::string>(destinationBox->Text);
		//
		//Stop if can not find the origin airport.
		//
		if ((origin = map->GetAirportInventory()->LocateAirportByCode(originText)) == nullptr)
		{
			OriginErrorText->Visible = true;
			return;
		}
		//
		//Stop if can not find the destination airport
		//
		if ((destination = map->GetAirportInventory()->LocateAirportByCode(destinationText)) == nullptr)
		{
			DestinationErrorText->Visible = true;
			return;
		}
		//
		//Continue and make error notification invisible.
		//
		OriginErrorText->Visible = false;
		DestinationErrorText->Visible = false;
		//
		//Set the user preference, based on what user chose on the quick search box.
		//
		SetUserPreference();
		//
		//Implement the search, print out the number of search result found.
		//
		result = mainSearch.Execute(map, origin, destination, currentUser->GetSearchPreference(), numberRes);
		res = &result;
		numberRoutesFoundText->Text = "We found " + numberRes + " routes for you.";
		numberRoutesFoundText->Visible = true;
		//
		//Check out for errors!!
		//
		DisplayMultiFlightsResult(0, numberRes);
	}
			 /*
		 private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 result = mainSearch.Execute(map, origin, destination, currentUser->GetSearchPreference(), numberOfResults);

			 if (result.size() > 0)
			 {


				 Time1->Visible = true;
				 timeTravelled1->Visible = true;
				 transitList1->Visible = true;
				 price1->Visible = true;
				 groupBox1->Visible = true;
				 carrierName1->Visible = true;
				 airportInfo1->Visible = true;

				 Time1->Text = gcnew String(result[0].DisplayDepartureAndArrivalTime().c_str());
				 timeTravelled1->Text = gcnew String(result[0].GetTravelTime().Display().c_str());
				 transitList1->Text = gcnew String(result[0].DisplayTransitList().c_str());
				 price1->Text = gcnew String(result[0].DisplayPrice(currentUser->GetSearchPreference()->flightClass, (int)numberPassengersBox->Value).c_str());
				 carrierName1->Text = gcnew String(result[0].DisplayCarriers().c_str());
				 airportInfo1->Text = gcnew String(result[0].DisplayDepartureAndArrivalAirport().c_str());

				 Time2->Visible = true;
				 timeTravelled2->Visible = true;
				 transitList2->Visible = true;
				 price2->Visible = true;
				 groupBox2->Visible = true;
				 carrierName2->Visible = true;
				 airportInfo2->Visible = true;

				 Time2->Text = gcnew String(result[1].DisplayDepartureAndArrivalTime().c_str());
				 timeTravelled2->Text = gcnew String(result[1].GetTravelTime().Display().c_str());
				 transitList2->Text = gcnew String(result[1].DisplayTransitList().c_str());
				 price2->Text = gcnew String(result[1].DisplayPrice(currentUser->GetSearchPreference()->flightClass, (int)numberPassengersBox->Value).c_str());
				 carrierName2->Text = gcnew String(result[1].DisplayCarriers().c_str());
				 airportInfo2->Text = gcnew String(result[1].DisplayDepartureAndArrivalAirport().c_str());
			 }
		 }

		 private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 Search mainSearch;
			 vector<MultiFlights> result;
			 Airport* origin; Airport* destination;
			 string originText = msclr::interop::marshal_as<std::string>(originBox->Text);
			 string destinationText = msclr::interop::marshal_as<std::string>(destinationBox->Text);
			 //FlightClass chosenRank;
			 int numberOfResults = 1000;

			 if ((origin = map->GetAirportInventory()->LocateAirportByCode(originText)) == nullptr) {
				 OriginErrorText->Visible = true;
				 return;
			 }

			 if ((destination = map->GetAirportInventory()->LocateAirportByCode(destinationText)) == nullptr) {
				 DestinationErrorText->Visible = true;
				 return;
			 }
			 OriginErrorText->Visible = false;
			 DestinationErrorText->Visible = false;

			 if (searchByPriceRadio->Checked) currentUser->GetSearchPreference()->SortCriteria = SORT_BY_PRICE;
			 if (searchByTimeRadio->Checked) currentUser->GetSearchPreference()->SortCriteria = SORT_BY_DURATION;

			 if (FlightRankBox->SelectedItem == "ECONOMY") currentUser->GetSearchPreference()->flightClass = ECONOMY;
			 if (FlightRankBox->SelectedItem == "BUSINESS") currentUser->GetSearchPreference()->flightClass = BUSINESS;

			 result = mainSearch.Execute(map, origin, destination, currentUser->GetSearchPreference(), numberOfResults);
			 FlightsDetailForm^ detailForm = gcnew FlightsDetailForm(&result[0]);
			 detailForm->ShowDialog();
		 }
		 */

	private: System::Void MultiFlightDetail_Click(System::Object^ sender, System::EventArgs^ e)
	{
		int i;
		for (i = 0; i < NUMBER_GROUP; ++i)
		{
			if (MultiFlightExploreButton[i] == sender) break;
		}
		if (i == NUMBER_GROUP) return;
		FlightsDetailForm^ detailForm = gcnew FlightsDetailForm(&(*res)[i+minIndex]);
		detailForm->ShowDialog();
	}
	private: System::Void AdvancedSearchButton_Click(System::Object^  sender, System::EventArgs^  e) {
		SearchPreferenceForm^ newPreferenceForm = gcnew SearchPreferenceForm(currentUser->GetSearchPreference());
		if (newPreferenceForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
		}
		newPreferenceForm->Close();
		this->Show();
	}
	//
	//
	//
	private: System::Void LogOutButton_Click(System::Object^  sender, System::EventArgs^  e) {
		currentUser = nullptr;
		this->Close();
	}
	//
	//
	//
	private: System::Void Explore_Click(System::Object^  sender, System::EventArgs^  e) {
		ExploreForm^ newExploreForm = gcnew ExploreForm(map, currentUser);
		this->Hide();
		if (newExploreForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
		}
		newExploreForm->Close();
		this->Show();
	}
	//
	//
	//
	private: System::Void SearchHistoryButton_Click(System::Object^  sender, System::EventArgs^  e) {
		SearchHistoryForm^ newSearchHistoryForm = gcnew SearchHistoryForm(currentUser);
		this->Hide();
		if (newSearchHistoryForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
		}
		newSearchHistoryForm->Close();
		delete newSearchHistoryForm;
		this->Show();
	}
	//
	//
	//
	private: System::Void LessButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (res == nullptr) return;
		DecrementMinIndex();
		DisplayMultiFlightsResult(minIndex, res->size());
	}
	//
	//
	//
	private: System::Void MoreButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (res == nullptr) return;
		IncrementMinIndex();
		DisplayMultiFlightsResult(minIndex, res->size());
	}
	//
	//
	//
	private: System::Void AdminControlButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	//
	//
	//
	private: System::Void SetUserPreference(System::Void)
	{
		if (searchByPriceRadio->Checked) currentUser->GetSearchPreference()->SetSortCriteria(SORT_BY_PRICE);
		if (searchByTimeRadio->Checked) currentUser->GetSearchPreference()->SetSortCriteria(SORT_BY_DURATION);
		if (FlightRankBox->SelectedItem == "ECONOMY") currentUser->GetSearchPreference()->SetFlightClass(ECONOMY);
		if (FlightRankBox->SelectedItem == "BUSINESS") currentUser->GetSearchPreference()->SetFlightClass(BUSINESS);
	}
	//
	//
	//
	private: System::Void DisplayMultiFlightsResult(int min, int max)
	{
		int i, group_index;
		MultiFlights * currentRes = nullptr;
		int limit = NUMBER_GROUP + min;
		if (limit >= max)
		{
			limit = max;
		}

		for (i = 0; i < NUMBER_GROUP; ++i)
		{
			IsDisplayGroupBox(i, false);
		}

		for (i = min; i < limit; ++i)
		{
			currentRes = &(*res)[i];
			group_index = i - min;
			IsDisplayGroupBox(group_index, true);
			MultiFlightGroupBoxArr[group_index]->Text = gcnew String(("#" + to_string(i+1)).c_str());
			TimeLabelArr[group_index]->Text = gcnew String(currentRes->DisplayDepartureAndArrivalTime().c_str());
			TimeTravelledLabelArr[group_index]->Text = gcnew String(("Duration: " + currentRes->GetTravelTime().Display() + "h").c_str());
			NumberStopsLabelArr[group_index]->Text = gcnew String(currentRes->DisplayNumberOfStops().c_str());
			CarrierLabelArr[group_index]->Text = gcnew String(currentRes->DisplayCarriers().c_str());
			AirportInforLabelArr[group_index]->Text = gcnew String(currentRes->DisplayDepartureAndArrivalAirport().c_str());
			TransitLabelArr[group_index]->Text = gcnew String(currentRes->DisplayTransitList().c_str());
			PriceLabelArr[group_index]->Text = gcnew String(currentRes->DisplayPrice(currentUser->GetSearchPreference()->GetFlightClass(), currentUser->GetSearchPreference()->GetNumberOfPassengers()).c_str());
		}
	}
	//
	//
	//
	private: System::Void IsDisplayGroupBox(int group_index, bool isDisplay)
	{
			MultiFlightGroupBoxArr[group_index]->Visible = isDisplay;
			MultiFlightGroupBoxArr[group_index]->Visible = isDisplay;
			TimeLabelArr[group_index]->Visible = isDisplay;
			TimeTravelledLabelArr[group_index]->Visible = isDisplay;
			NumberStopsLabelArr[group_index]->Visible = isDisplay;
			CarrierLabelArr[group_index]->Visible = isDisplay;
			AirportInforLabelArr[group_index]->Visible = isDisplay;
			TransitLabelArr[group_index]->Visible = isDisplay;
			PriceLabelArr[group_index]->Visible = isDisplay;
	}
	//
	//
	//
	private: System::Void IncrementMinIndex()
	{
		if (res == nullptr) return;
		if (minIndex < res->size() - 1) minIndex++;
	}
	//
	//
	//
	private: System::Void DecrementMinIndex()
	{
		if (minIndex == 0) return;
		else minIndex--;
	}
	//
	//
	//
	private: System::Void ResetMinIndex()
	{
		minIndex = 0;
	}
	};
}

