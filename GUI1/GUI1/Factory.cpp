#include "stdafx.h"

//
//Create map element and add into the correct inventory
//
void Factory::CreateMapElement(vector<string> str, AirportInventory* AI, CarrierInventory* CI, FlightInventory* FI)
{
	static IHaveAviationCode* newElement;
	string aviationCode, name, cityName, mapType, departureAirportCode, arrivalAirportCode, carrierCode;
	string departureHourStr, departureMinStr, arrivalHourStr, arrivalMinStr;
	string businessPriceStr, economyPriceStr;
	Airport* pDepartureAirport, * pArrivalAirport;
	Carrier* pCarrier;
	//
	//return nothing if the the string vector does not include anything.
	//
	if (str.size() == 0) return;
		mapType = str[0];

	if (mapType == "Airport")
	{
		aviationCode = str[1];
		cityName = str[2];
		name = str[3];
		newElement =  new Airport(aviationCode, cityName, name);
		AI->AddAirport((Airport*) newElement);
		return;
	}

	if (mapType == "Carrier")
	{
		aviationCode = str[1];
		name = str[2];
		newElement = new Carrier(aviationCode, name);
		CI->AddCarrier((Carrier*) newElement);
		return;
	}
	
	if (mapType == "Flight")
	{
		aviationCode = str[1];
		departureAirportCode = str[2];
		arrivalAirportCode = str[3];
		carrierCode = str[4];
		departureHourStr = str[5];
		departureMinStr = str[6];
		arrivalHourStr = str[7];
		arrivalMinStr = str[8];
		businessPriceStr = str[9];
		economyPriceStr = str[10];
		if (aviationCode.size() <= 2) return;
		//
		//return nothing if the departure aiport code does not exist in the airport inventory of the map.
		//
		if ((pDepartureAirport = AI->LocateAirportByCode(departureAirportCode)) == nullptr) return;
		//
		//return nothing if the arrival aiport code does not exist in the airport inventory of the map.
		//
		if ((pArrivalAirport = AI->LocateAirportByCode(arrivalAirportCode)) == nullptr) return;
		//
		//return nothing if the carrier aviationCode does not exist in the carrier inventory of the map.
		//
		if ((pCarrier = CI->LocateCarrierByCode(carrierCode)) == nullptr) return;
		//
		//else, create flight and add the flight inventory.
		//
		newElement = new Flight(aviationCode, pDepartureAirport, pArrivalAirport, pCarrier,
			Time(stoi(departureHourStr), stoi(departureMinStr)),
			Time(stoi(arrivalHourStr), stoi(arrivalMinStr)),
			stoi(businessPriceStr), stoi(economyPriceStr));
		
		FI->AddFlight((Flight*) newElement);
		return;
	}
	return;
}
//
//create user object and return it.
//if any issue arises, return nullptr.
//
User* Factory::CreateUser(vector<string> str)
{
	static User* newUser;
	string userType, userName, password;
	if (str.size() < 3) return nullptr;
	userType = str[0];
	userName = str[1];
	password = str[2];
	if (userType == "Admin")
	{
		return new Admin(userName, password);
	}
	if (userType == "StandardUser")
	{
		return new StandardUser(userName, password);
	}
	return nullptr;
}