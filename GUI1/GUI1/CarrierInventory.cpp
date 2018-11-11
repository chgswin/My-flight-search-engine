#include "stdafx.h"

///
///
///
CarrierInventory::CarrierInventory()
{
}
CarrierInventory::CarrierInventory(const CarrierInventory& CI)
{
	aCarrierList = CI.aCarrierList;
}

void CarrierInventory::AddCarrier(Carrier* pCarrier)
{
	aCarrierList.push_back(pCarrier);
}

void CarrierInventory::RemoveCarrier(Carrier* pCarrier)
{
	vector<Carrier*>::iterator i;
	for (i = aCarrierList.begin(); i != aCarrierList.end(); ++i)
	{
		if (*i == pCarrier) {
			aCarrierList.erase(i);
			break;
		}
	}
}
int CarrierInventory::NumberOfCarriers()
{
	return aCarrierList.size();
}

vector<Carrier*>* CarrierInventory::GetPtrCarrierList()
{
	return &aCarrierList;
}

Carrier* CarrierInventory::LocateCarrierByCode(string code)
{
	int i;
	for (i = 0; i < NumberOfCarriers(); ++i)
	{
		if (code == aCarrierList[i]->GetAviationCode()) return aCarrierList[i];
	}
	return nullptr;
}