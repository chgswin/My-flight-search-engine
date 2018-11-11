#include "stdafx.h"

Compare::Compare(FlightClass fs, SortCriteria ss)
{
	flightClass = fs;
	sortCriteria = ss;
}
//
// operator gives the result
// based on the enum value of sortCriteria.
//
int Compare::operator() (Itinerary * a, Itinerary * b)
{
	switch (sortCriteria)
	{
	case SORT_BY_DURATION:
		if (a->GetTravelTime().CompareTime(b->GetTravelTime()) > 0) return 1;
		else return 0;
		break;
	case SORT_BY_PRICE:
		if (a->GetPrice(flightClass) > b->GetPrice(flightClass)) return 1;
		else return 0;
		break;
	case SORT_BY_ARRIVAL_TIME:
		if (a->GetArrivalTime().CompareTime(b->GetArrivalTime()) < 0) return 1;
		else return 0;
		break;
	case SORT_BY_DEPARTURE_TIME:
		if (a->GetDepartureTime().CompareTime(b->GetDepartureTime()) < 0) return 1;
		else return 0;
		break;
	}
}
//
//operator version for pointer.
//
int Compare::operator() (Itinerary& a, Itinerary& b)
{
	return operator()( &a, &b);
}