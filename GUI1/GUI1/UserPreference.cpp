#include "stdafx.h"
#include "FlightSearchAPI.h"

void UserPreference::Reset()
{
	aNumberOfPassengers = 1;
	aMaxPrice = 2000;
	aMaxTransit = 3;
	aMaxTime = Time(48, 00);
	aSortCriteria = SORT_BY_PRICE;
	aFlightClass = ECONOMY;
}

UserPreference::UserPreference() : aMaxTime(48, 00)
{
	Reset();
}

int UserPreference::GetNumberOfPassengers()
{
	return aNumberOfPassengers;
}
int UserPreference::GetMaxPrice()
{
	return aMaxPrice;
}
Time UserPreference::GetMaxTime()
{
	return aMaxTime;
}
int UserPreference::GetMaxTransit()
{
	return aMaxTransit;
}
FlightClass UserPreference::GetFlightClass()
{
	return aFlightClass;
}
SortCriteria UserPreference::GetSortCriteria()
{
	return aSortCriteria;
}
void UserPreference::SetNumberOfPassengers(int numberOfPassengers)
{
	aNumberOfPassengers = numberOfPassengers;
}
void UserPreference::SetMaxPrice(int maxPrice)
{
	aMaxPrice = maxPrice;
}
void UserPreference::SetMaxTime(Time maxTime)
{
	aMaxTime = maxTime;
}
void UserPreference::SetMaxTransit(int maxTransit)
{
	aMaxTransit = maxTransit;
}

void UserPreference::SetFlightClass(FlightClass flightClass)
{
	aFlightClass = flightClass;
}
void UserPreference::SetSortCriteria(SortCriteria sortCriteria)
{
	aSortCriteria = sortCriteria;
}