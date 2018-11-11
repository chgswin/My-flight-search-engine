#include "stdafx.h"
#include <fstream>
const int READ_TIMES_EACH_LINE = 11;
//
//Singleton Design Pattern
//Exactly one map and only one map is created.
//
MapSingleton* MapSingleton::m_Instance = nullptr;

MapSingleton* MapSingleton::Instance()
{

	if (m_Instance == nullptr)
		m_Instance = new MapSingleton();
	return m_Instance;
}

MapSingleton::MapSingleton()
{
}

AirportInventory* MapSingleton::GetAirportInventory()
{
	return &aAirportInventory;
}
FlightInventory* MapSingleton::GetFlightInventory()
{
	return &aFlightInventory;
}
//
//Loop through every flight
//as having the origin and destination airport,
//it is necessary to put a flight into the origin airport departure list
//and into the destination airport arrival list.
//This can be thought of as the pre-processing for the search algorithm.
//
void MapSingleton::Organize()
{
	int i = 0, j = 0;
	int numberOfFlights = aFlightInventory.NumberOfFlights();
	int numberOfAirports = aAirportInventory.NumberOfAirports();
	for (i = 0; i < numberOfFlights; ++i)
	{
		Flight* thisFlight = (*aFlightInventory.GetPtrFlightList())[i];
		Airport* a1 = (*aFlightInventory.GetPtrFlightList())[i]->GetOrigin();
		Airport* a2 = (*aFlightInventory.GetPtrFlightList())[i]->GetDestination();
		a1->GetDepartureFlightInventory()->AddFlight(thisFlight);
		a2->GetArrivalFlightInventory()->AddFlight(thisFlight);
	}
}

//
//Load data from a file
//Then create map objects: they can be either airport, carrier or flight object.
//
void MapSingleton::LoadData(string filename)
{
	int i;
	vector<string> str;
	string read_str;
	ifstream read(filename);	
	Factory mapFactory;
	if (!read.is_open()) cout << "Can not open file " << filename << endl;
	else
	{
		while (read.good()) {
			for (i = 0; i < READ_TIMES_EACH_LINE - 1; ++i)
			{
				getline(read, read_str, ',');
				str.push_back(read_str);
			}
			getline(read, read_str, '\n');
			str.push_back(read_str);
			mapFactory.CreateMapElement(str, &aAirportInventory, &aCarrierInventory, &aFlightInventory);
			str.clear();
		}
	}
	read.close();
}
//
//Destructor for MapSingleton.
//It will destroy objects in the following order: flights, airports and then carriers.
//
MapSingleton::~MapSingleton()
{
	int i;
	for (i = 0; i < aFlightInventory.NumberOfFlights(); ++i)
	{
		if ((*aFlightInventory.GetPtrFlightList())[i])
			delete (*aFlightInventory.GetPtrFlightList())[i];
	}
	for (i = 0; i < aAirportInventory.NumberOfAirports(); ++i)
	{
		if ((*aAirportInventory.GetPtrAirportList())[i])
			delete (*aAirportInventory.GetPtrAirportList())[i];
	}

	for (i = 0; i < aCarrierInventory.NumberOfCarriers(); ++i)
	{
		if ((*aCarrierInventory.GetPtrCarrierList())[i])
			delete (*aCarrierInventory.GetPtrCarrierList())[i];
	}

	m_Instance = nullptr;
}
