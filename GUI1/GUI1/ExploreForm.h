#pragma once

#include "FlightSearchAPI.h"
const int MAX_TOP_ROUTES = 10;
namespace GUI1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ExploreForm
	/// </summary>
	public ref class ExploreForm : public System::Windows::Forms::Form
	{
	public:
		ExploreForm(MapSingleton * map, User * user)
		{
			currentMap = map;
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
		~ExploreForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: MapSingleton * currentMap;
	private: User * currentUser;
	private: System::Windows::Forms::Button^  GoButton;
	private: System::Windows::Forms::TextBox^  SearchTextBox;
	private: System::Windows::Forms::GroupBox^  FlightGroup;


	private: System::Windows::Forms::Label^  carrierName1;

	private: System::Windows::Forms::Label^  transitList1;
	private: System::Windows::Forms::Label^  numberStops1;
	private: System::Windows::Forms::Label^  airportInfo1;
	private: System::Windows::Forms::Label^  timeTravelled1;
	private: System::Windows::Forms::Label^  Time1;

	private: System::Windows::Forms::GroupBox^  TopRouteGroup;
	private: System::Windows::Forms::GroupBox^  ArrivalGroup;
	private: System::Windows::Forms::GroupBox^  DepartureGroup;
	private: System::Windows::Forms::TextBox^  ArrivalListTextBox;
	private: System::Windows::Forms::TextBox^  DepartureListTextBox;
	private: System::Windows::Forms::TextBox^  TopRouteTextBox;
	private: System::Windows::Forms::Label^  ErrorLabel;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ExploreForm::typeid));
			this->GoButton = (gcnew System::Windows::Forms::Button());
			this->SearchTextBox = (gcnew System::Windows::Forms::TextBox());
			this->FlightGroup = (gcnew System::Windows::Forms::GroupBox());
			this->carrierName1 = (gcnew System::Windows::Forms::Label());
			this->transitList1 = (gcnew System::Windows::Forms::Label());
			this->numberStops1 = (gcnew System::Windows::Forms::Label());
			this->airportInfo1 = (gcnew System::Windows::Forms::Label());
			this->timeTravelled1 = (gcnew System::Windows::Forms::Label());
			this->Time1 = (gcnew System::Windows::Forms::Label());
			this->TopRouteGroup = (gcnew System::Windows::Forms::GroupBox());
			this->TopRouteTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ArrivalGroup = (gcnew System::Windows::Forms::GroupBox());
			this->ArrivalListTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DepartureGroup = (gcnew System::Windows::Forms::GroupBox());
			this->DepartureListTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ErrorLabel = (gcnew System::Windows::Forms::Label());
			this->FlightGroup->SuspendLayout();
			this->TopRouteGroup->SuspendLayout();
			this->ArrivalGroup->SuspendLayout();
			this->DepartureGroup->SuspendLayout();
			this->SuspendLayout();
			// 
			// GoButton
			// 
			this->GoButton->Location = System::Drawing::Point(555, 26);
			this->GoButton->Name = L"GoButton";
			this->GoButton->Size = System::Drawing::Size(75, 23);
			this->GoButton->TabIndex = 0;
			this->GoButton->Text = L"Go";
			this->GoButton->UseVisualStyleBackColor = true;
			this->GoButton->Click += gcnew System::EventHandler(this, &ExploreForm::GoButton_Click);
			// 
			// SearchTextBox
			// 
			this->SearchTextBox->Location = System::Drawing::Point(62, 28);
			this->SearchTextBox->Name = L"SearchTextBox";
			this->SearchTextBox->Size = System::Drawing::Size(475, 20);
			this->SearchTextBox->TabIndex = 1;
			this->SearchTextBox->Text = L"Search for an airport, a flight. Try \"MEL\", \"Sydney\", \"SQ228\".";
			// 
			// FlightGroup
			// 
			this->FlightGroup->Controls->Add(this->carrierName1);
			this->FlightGroup->Controls->Add(this->transitList1);
			this->FlightGroup->Controls->Add(this->numberStops1);
			this->FlightGroup->Controls->Add(this->airportInfo1);
			this->FlightGroup->Controls->Add(this->timeTravelled1);
			this->FlightGroup->Controls->Add(this->Time1);
			this->FlightGroup->Location = System::Drawing::Point(53, 70);
			this->FlightGroup->Name = L"FlightGroup";
			this->FlightGroup->Size = System::Drawing::Size(577, 76);
			this->FlightGroup->TabIndex = 9;
			this->FlightGroup->TabStop = false;
			this->FlightGroup->Text = L"The flight we find for you";
			this->FlightGroup->Visible = false;
			// 
			// carrierName1
			// 
			this->carrierName1->AutoSize = true;
			this->carrierName1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->carrierName1->Location = System::Drawing::Point(40, 47);
			this->carrierName1->Name = L"carrierName1";
			this->carrierName1->Size = System::Drawing::Size(45, 17);
			this->carrierName1->TabIndex = 0;
			this->carrierName1->Text = L"label1";
			this->carrierName1->Visible = false;
			// 
			// transitList1
			// 
			this->transitList1->AutoSize = true;
			this->transitList1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->transitList1->Location = System::Drawing::Point(281, 47);
			this->transitList1->Name = L"transitList1";
			this->transitList1->Size = System::Drawing::Size(45, 17);
			this->transitList1->TabIndex = 0;
			this->transitList1->Text = L"label1";
			this->transitList1->Visible = false;
			// 
			// numberStops1
			// 
			this->numberStops1->AutoSize = true;
			this->numberStops1->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numberStops1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->numberStops1->Location = System::Drawing::Point(281, 21);
			this->numberStops1->Name = L"numberStops1";
			this->numberStops1->Size = System::Drawing::Size(46, 16);
			this->numberStops1->TabIndex = 0;
			this->numberStops1->Text = L"label1";
			this->numberStops1->Visible = false;
			// 
			// airportInfo1
			// 
			this->airportInfo1->AutoSize = true;
			this->airportInfo1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->airportInfo1->Location = System::Drawing::Point(151, 47);
			this->airportInfo1->Name = L"airportInfo1";
			this->airportInfo1->Size = System::Drawing::Size(45, 17);
			this->airportInfo1->TabIndex = 0;
			this->airportInfo1->Text = L"label1";
			this->airportInfo1->Visible = false;
			// 
			// timeTravelled1
			// 
			this->timeTravelled1->AutoSize = true;
			this->timeTravelled1->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->timeTravelled1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->timeTravelled1->Location = System::Drawing::Point(151, 21);
			this->timeTravelled1->Name = L"timeTravelled1";
			this->timeTravelled1->Size = System::Drawing::Size(46, 16);
			this->timeTravelled1->TabIndex = 0;
			this->timeTravelled1->Text = L"label1";
			this->timeTravelled1->Visible = false;
			// 
			// Time1
			// 
			this->Time1->AutoSize = true;
			this->Time1->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Time1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Time1->Location = System::Drawing::Point(40, 21);
			this->Time1->Name = L"Time1";
			this->Time1->Size = System::Drawing::Size(46, 16);
			this->Time1->TabIndex = 0;
			this->Time1->Text = L"label1";
			this->Time1->Visible = false;
			// 
			// TopRouteGroup
			// 
			this->TopRouteGroup->Controls->Add(this->TopRouteTextBox);
			this->TopRouteGroup->Location = System::Drawing::Point(53, 71);
			this->TopRouteGroup->Name = L"TopRouteGroup";
			this->TopRouteGroup->Size = System::Drawing::Size(181, 317);
			this->TopRouteGroup->TabIndex = 10;
			this->TopRouteGroup->TabStop = false;
			this->TopRouteGroup->Text = L"Top routes from";
			this->TopRouteGroup->Visible = false;
			// 
			// TopRouteTextBox
			// 
			this->TopRouteTextBox->Location = System::Drawing::Point(9, 20);
			this->TopRouteTextBox->Multiline = true;
			this->TopRouteTextBox->Name = L"TopRouteTextBox";
			this->TopRouteTextBox->ReadOnly = true;
			this->TopRouteTextBox->Size = System::Drawing::Size(156, 266);
			this->TopRouteTextBox->TabIndex = 0;
			// 
			// ArrivalGroup
			// 
			this->ArrivalGroup->Controls->Add(this->ArrivalListTextBox);
			this->ArrivalGroup->Location = System::Drawing::Point(251, 71);
			this->ArrivalGroup->Name = L"ArrivalGroup";
			this->ArrivalGroup->Size = System::Drawing::Size(379, 158);
			this->ArrivalGroup->TabIndex = 10;
			this->ArrivalGroup->TabStop = false;
			this->ArrivalGroup->Text = L"Arrivals";
			this->ArrivalGroup->Visible = false;
			// 
			// ArrivalListTextBox
			// 
			this->ArrivalListTextBox->Location = System::Drawing::Point(18, 20);
			this->ArrivalListTextBox->Multiline = true;
			this->ArrivalListTextBox->Name = L"ArrivalListTextBox";
			this->ArrivalListTextBox->ReadOnly = true;
			this->ArrivalListTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->ArrivalListTextBox->Size = System::Drawing::Size(344, 122);
			this->ArrivalListTextBox->TabIndex = 0;
			// 
			// DepartureGroup
			// 
			this->DepartureGroup->Controls->Add(this->DepartureListTextBox);
			this->DepartureGroup->Location = System::Drawing::Point(251, 235);
			this->DepartureGroup->Name = L"DepartureGroup";
			this->DepartureGroup->Size = System::Drawing::Size(379, 153);
			this->DepartureGroup->TabIndex = 10;
			this->DepartureGroup->TabStop = false;
			this->DepartureGroup->Text = L"Departure";
			this->DepartureGroup->Visible = false;
			// 
			// DepartureListTextBox
			// 
			this->DepartureListTextBox->Location = System::Drawing::Point(18, 19);
			this->DepartureListTextBox->Multiline = true;
			this->DepartureListTextBox->Name = L"DepartureListTextBox";
			this->DepartureListTextBox->ReadOnly = true;
			this->DepartureListTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->DepartureListTextBox->Size = System::Drawing::Size(344, 122);
			this->DepartureListTextBox->TabIndex = 0;
			// 
			// ErrorLabel
			// 
			this->ErrorLabel->AutoSize = true;
			this->ErrorLabel->ForeColor = System::Drawing::Color::Red;
			this->ErrorLabel->Location = System::Drawing::Point(77, 51);
			this->ErrorLabel->Name = L"ErrorLabel";
			this->ErrorLabel->Size = System::Drawing::Size(258, 13);
			this->ErrorLabel->TabIndex = 11;
			this->ErrorLabel->Text = L"Sorry. We seem not to have what you are looking for.";
			this->ErrorLabel->Visible = false;
			// 
			// ExploreForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(665, 495);
			this->Controls->Add(this->ErrorLabel);
			this->Controls->Add(this->DepartureGroup);
			this->Controls->Add(this->ArrivalGroup);
			this->Controls->Add(this->TopRouteGroup);
			this->Controls->Add(this->FlightGroup);
			this->Controls->Add(this->SearchTextBox);
			this->Controls->Add(this->GoButton);
			this->Name = L"ExploreForm";
			this->Text = L"Explore";
			this->FlightGroup->ResumeLayout(false);
			this->FlightGroup->PerformLayout();
			this->TopRouteGroup->ResumeLayout(false);
			this->TopRouteGroup->PerformLayout();
			this->ArrivalGroup->ResumeLayout(false);
			this->ArrivalGroup->PerformLayout();
			this->DepartureGroup->ResumeLayout(false);
			this->DepartureGroup->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
	}

private: System::Void GoButton_Click(System::Object^  sender, System::EventArgs^  e) {
	string code =		msclr::interop::marshal_as<std::string>(SearchTextBox->Text);
	Airport * airport = currentMap->GetAirportInventory()->LocateAirportByCode(code);
	Flight * flight =	currentMap->GetFlightInventory()->LocateFlightByCode(code);
	Sort mySort;
	if (airport == nullptr && flight == nullptr)
	{
		ErrorLabel->Visible = true;
		ErrorLabel->Text = "Sorry. We seem not to have what you are looking for.";
		return;
	}

	if (airport != nullptr)
	{
		currentUser->AddSearchHistory(airport);

		FlightGroup->Visible = false;
		TopRouteGroup->Visible = true;
		ArrivalGroup->Visible = true;
		DepartureGroup->Visible = true;
		
		PrintTopRouteText(&mySort.SortMostConnectingAirport(airport->GetDepartureFlightInventory()->GetPtrFlightList()));
		PrintArrivalAndDepartureText(&mySort.SortFlight(airport->GetDepartureFlightInventory()->GetPtrFlightList(), SORT_BY_DEPARTURE_TIME),
										&mySort.SortFlight(airport->GetArrivalFlightInventory()->GetPtrFlightList(), SORT_BY_ARRIVAL_TIME));
		return;
	}

	if (flight != nullptr)
	{
		currentUser->AddSearchHistory(flight);

		TopRouteGroup->Visible = false;
		ArrivalGroup->Visible = false;
		DepartureGroup->Visible = false;
		FlightGroup->Visible = true;
		Time1->Visible = true;
		carrierName1->Visible = true; 
		timeTravelled1->Visible = true;
		airportInfo1->Visible = true;

		Time1->Text = gcnew String(flight->DisplayDepartureAndArrivalTime().c_str());
		carrierName1->Text = gcnew String(flight->GetCarrier()->GetName().c_str());
		timeTravelled1->Text = gcnew String(flight->GetTravelTime().Display().c_str());
		airportInfo1->Text = gcnew String(flight->DisplayDepartureAndArrivalAirport().c_str());
		return;
	}
}

private: System::Void PrintTopRouteText(vector<pair<Airport*, int>>* pairList)
{
	string result = "";
	int maxRoute = MAX_TOP_ROUTES;
	if (maxRoute > pairList->size()) maxRoute = pairList->size();
	int i;
	TopRouteTextBox->Text = "";
	for (i = 0; i < maxRoute; ++i)
	{ 
		result = "#" + to_string(i + 1) + ". " + (*pairList)[i].first->GetAviationCode() + " (" + to_string((*pairList)[i].second) + " flights/day)";
		TopRouteTextBox->Text += gcnew String(result.c_str()) + Environment::NewLine;
	}
	
}

private: System::Void PrintArrivalAndDepartureText(vector<Flight*> * PtrDepartureFlightList, vector<Flight*> * PtrArrivalFlightList)
{
	string resultDeparture = "", resultArrival = "";
	int maxFlightsDeparture = PtrDepartureFlightList->size();
	int maxFlightsArrival = PtrArrivalFlightList->size();
	int i;

	Flight* thisFlight = nullptr;

	DepartureListTextBox->Text = "";
	ArrivalListTextBox->Text = "";

	for (i = 0; i < maxFlightsDeparture; ++i)
	{
		thisFlight = (*PtrDepartureFlightList)[i];
		resultDeparture = (thisFlight->GetDepartureTime().Display()) + " | " + 
			thisFlight->GetAviationCode() + " | to " + thisFlight->GetDestination()->GetCityName() + " | " + thisFlight->GetCarrier()->GetName() + '\n';
		DepartureListTextBox->Text += gcnew String(resultDeparture.c_str()) + Environment::NewLine;
	}

	thisFlight = nullptr;
	for (i = 0; i < maxFlightsArrival; ++i)
	{
		thisFlight = (*PtrArrivalFlightList)[i];
		resultArrival = (thisFlight->GetArrivalTime().Display()) + " | " + 
			thisFlight->GetAviationCode() + " | from " + thisFlight->GetOrigin()->GetCityName() + " | " + thisFlight->GetCarrier()->GetName() + '\n';
		ArrivalListTextBox->Text += gcnew String(resultArrival.c_str()) + Environment::NewLine;
	}
}
};
}
