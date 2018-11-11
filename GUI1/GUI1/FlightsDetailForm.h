#pragma once
#include "FlightSearchAPI.h"

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 400;
const int EACH_FLIGHT_WIDTH = 120;

namespace GUI1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FlightsDetailForm
	/// </summary>
	public ref class FlightsDetailForm : public System::Windows::Forms::Form
	{
	public:
		FlightsDetailForm(MultiFlights * m)
		{
			apMultiFlights = m;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FlightsDetailForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: cli::array< System::Windows::Forms::Label^ > ^DepartureArr, ^ArrivalArr, ^FlightDurationArr, ^TransitArr;
	private: MultiFlights* apMultiFlights;
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
			this->DepartureArr =		gcnew cli::array<System::Windows::Forms::Label^>(10);
			this->ArrivalArr =			gcnew cli::array<System::Windows::Forms::Label^>(10);
			this->FlightDurationArr =	gcnew cli::array<System::Windows::Forms::Label^>(10);
			this->TransitArr =			gcnew cli::array<System::Windows::Forms::Label^>(10);
			this->SuspendLayout();

			int numberOfFlights = apMultiFlights->GetFlightInventory()->NumberOfFlights();
			int numberOfAirports = apMultiFlights->GetTransitInventory()->NumberOfAirports();
			int i;
			//
			//Display every flight to the form
			//
			for (i = 0; i < numberOfFlights; ++i)
			{
				DisplayAFlight(i);
			}
			//
			//Display every transit airport to the form
			//
			for (i = 0; i < numberOfAirports; ++i)
			{
				DisplayTransit(i);
			}

			this->Controls->AddRange(DepartureArr);
			this->Controls->AddRange(ArrivalArr);
			this->Controls->AddRange(FlightDurationArr);
			this->Controls->AddRange(TransitArr);
			// 
			// FlightsDetailForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(WINDOW_WIDTH, WINDOW_HEIGHT);
			this->Name = L"FlightsDetailForm";
			this->Text = gcnew String((apMultiFlights->GetOrigin()->GetCityName() + " - " + apMultiFlights->GetDestination()->GetCityName()).c_str());
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private: void DisplayAFlight(int i)
		{
			Flight* f = (*apMultiFlights->GetFlightInventory()->GetPtrFlightList())[i];
			this->DepartureArr[i] = gcnew System::Windows::Forms::Label();
			this->DepartureArr[i]->AutoSize = true;
			this->DepartureArr[i]->Location = System::Drawing::Point(100, 20 + EACH_FLIGHT_WIDTH * i);
			this->DepartureArr[i]->Name = L"label1";
			this->DepartureArr[i]->TabIndex = 0;
			this->DepartureArr[i]->Size = System::Drawing::Size(35, 13);
			this->DepartureArr[i]->Text = gcnew String(("Departs at: " + f->GetDepartureTime().Display() + " - " + f->GetOrigin()->GetName()).c_str());
			this->DepartureArr[i]->Visible = true;
			this->DepartureArr[i]->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
		
			this->FlightDurationArr[i] = gcnew System::Windows::Forms::Label();
			this->FlightDurationArr[i]->AutoSize = true;
			this->FlightDurationArr[i]->Location = System::Drawing::Point(120, 40 + EACH_FLIGHT_WIDTH * i);
			this->FlightDurationArr[i]->Name = L"label1";
			this->FlightDurationArr[i]->TabIndex = 0;
			this->FlightDurationArr[i]->Size = System::Drawing::Size(35, 13);
			this->FlightDurationArr[i]->Text = gcnew String((f->GetTravelTime().Display() + "h flight").c_str());
			this->FlightDurationArr[i]->Visible = true;
			this->FlightDurationArr[i]->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));

			this->ArrivalArr[i] = gcnew System::Windows::Forms::Label();
			this->ArrivalArr[i]->AutoSize = true;
			this->ArrivalArr[i]->Location = System::Drawing::Point(100, 60 + EACH_FLIGHT_WIDTH * i);
			this->ArrivalArr[i]->Name = L"label1";
			this->ArrivalArr[i]->TabIndex = 0;
			this->ArrivalArr[i]->Size = System::Drawing::Size(35, 13);
			this->ArrivalArr[i]->Text = gcnew String(("Arrives at: " + f->GetArrivalTime().Display() + " - " + f->GetDestination()->GetName()).c_str());
			this->ArrivalArr[i]->Visible = true;
			this->ArrivalArr[i]->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
		}
	
	private: void DisplayTransit(int i)
	{
		if (i >= (apMultiFlights->GetTransitInventory()->NumberOfAirports())) 
			return;
		Airport* transitAirport = (*apMultiFlights->GetTransitInventory()->GetPtrAirportList())[i];
		this->TransitArr[i] = gcnew System::Windows::Forms::Label();
		this->TransitArr[i]->AutoSize = true;
		this->TransitArr[i]->Location = System::Drawing::Point(100, 90 + EACH_FLIGHT_WIDTH * i);
		this->TransitArr[i]->Name = L"label1";
		this->TransitArr[i]->TabIndex = 0;
		this->TransitArr[i]->Size = System::Drawing::Size(35, 13);
		this->TransitArr[i]->Text = gcnew String((apMultiFlights->GetTransitTime(i).Display() + "h layover at " + 
			transitAirport->GetName() + " - " + transitAirport->GetAviationCode()).c_str());
		this->TransitArr[i]->Visible = true;
		this->TransitArr[i]->Font = (gcnew System::Drawing::Font(L"Arial", 8.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
	}
	};
};

