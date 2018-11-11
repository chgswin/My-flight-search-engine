#include "stdafx.h"

AirportInventory::AirportInventory()
{
}
AirportInventory::AirportInventory(const AirportInventory& AI)
{
	aAirportList = AI.aAirportList;
}

void AirportInventory::AddAirport(Airport* pAirport)
{
	aAirportList.push_back(pAirport);
}

void AirportInventory::RemoveAirport(Airport* pAirport)
{
	vector<Airport*>::iterator i;
	for (i = aAirportList.begin(); i != aAirportList.end(); ++i)
	{
		if (*i == pAirport) {
			aAirportList.erase(i);
			break;
		}
	}
}

int AirportInventory::NumberOfAirports()
{
	return aAirportList.size();
}

vector<Airport*> * AirportInventory::GetPtrAirportList()
{
	return &aAirportList;
}

Airport* AirportInventory::LocateAirportByCode(string code)
{
	int i;
	for (i = 0; i < NumberOfAirports(); ++i)
	{
		//
		//return the pointer to the airport if the code matches airport identifiers.
		//
		if (aAirportList[i]->AreYou(code))
			return aAirportList[i];
	}
	//
	// if not matched, returns nulptr.
	//
	return nullptr;
}