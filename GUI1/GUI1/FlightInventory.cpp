#include "stdafx.h"

FlightInventory::FlightInventory()
{
	aFlightList.clear();
}
FlightInventory::FlightInventory(const FlightInventory& fi)
{
	aFlightList = fi.aFlightList;
}
void FlightInventory::AddFlight(Flight* pFlight)
{
	aFlightList.push_back(pFlight);
}
void FlightInventory::RemoveFlight(Flight* pFlight)
{
	vector<Flight*>::iterator i;
	for (i = aFlightList.begin(); i != aFlightList.end(); ++i)
	{
		if (*i == pFlight) {
			aFlightList.erase(i);
			break;
		}
	}
}
int FlightInventory::NumberOfFlights()
{
	return aFlightList.size();
}
vector<Flight*>* FlightInventory::GetPtrFlightList()
{
	return &aFlightList;
}

Flight* FlightInventory::LocateFlightByCode(string code)
{
	int i;
	for (i = 0; i < NumberOfFlights(); ++i)
	{ 
		Flight* f = aFlightList[i];
		if (f->AreYou(code)) return f;
	}
	return nullptr;
}
