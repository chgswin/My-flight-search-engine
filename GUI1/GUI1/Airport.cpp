/// <summary>
/// Airport class. An airport object includes its own information 
/// and a list of pointers to flights coming from and to this airport
/// In the graph, each airport plays a role as a vertex.
/// </summary>

#include "stdafx.h"

Airport::Airport(string aviationCode, string cityName, string name) {
	aName = name;
	aAviationCode = aviationCode;
	aCityName = cityName;
}

Airport::Airport(const Airport& airport)
{
	aName = airport.aName;
	aAviationCode = airport.aAviationCode;
	aCityName = airport.aCityName;
	aDepartureFlightInventory = airport.aDepartureFlightInventory;
	aArrivalFlightInventory = airport.aArrivalFlightInventory;
}

string Airport::GetName()
{
	return aName;
}

string Airport::GetAviationCode()
{
	return aAviationCode;
}

string Airport::GetCityName()
{
	return aCityName;
}

bool Airport::AreYou(string ID)
{
	string id = ToLower(ID);
	//
	//check if the id string matches the aviationCode.
	//
	if (ToLower(aAviationCode) == id) return true;
	//
	//check if the id string matches the city name.
	//
	if (ToLower(aCityName) == id) return true;
	//
	//check if the id string matches the name of the airport.
	//
	if (ToLower(aName) == id) return true;
	return false;
}

FlightInventory* Airport::GetDepartureFlightInventory()
{
	return &aDepartureFlightInventory;
}

FlightInventory* Airport::GetArrivalFlightInventory()
{
	return &aArrivalFlightInventory;
}