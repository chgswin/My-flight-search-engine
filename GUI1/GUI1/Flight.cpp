#include "stdafx.h"

Flight::Flight(string aviationCode, Airport* origin, Airport* destination, Carrier * carrier, Time departureTime, Time arrivalTime, double businessPrice, double economyPrice) :
	Itinerary(origin, destination, departureTime, arrivalTime), 
	aBusinessPrice(businessPrice), 
	aEconomyPrice(economyPrice)
{
	aAviationCode = aviationCode;
	apCarrier = carrier;
}
Flight::Flight(const Flight& flight): Itinerary(flight)
{
	aAviationCode = flight.aAviationCode;
	apCarrier = flight.apCarrier;
}
Time Flight::GetTravelTime()
{
	return GetArrivalTime().FindDuration(GetDepartureTime());
}
//
//get flight based on the flight class.
//
double Flight::GetPrice(FlightClass rank)
{
	switch (rank) {
	case BUSINESS:
		return aBusinessPrice;
	case ECONOMY:
		return aEconomyPrice;
	default:
		return 0.0;
	}
}

Carrier* Flight::GetCarrier()
{
	return apCarrier;
}
string Flight::GetName()
{
	return "Flight " + aAviationCode + " from" + GetOrigin()->GetName() + " to " + GetDestination()->GetName();
}
string Flight::GetAviationCode()
{
	return aAviationCode;
}
bool Flight::AreYou(string code)
{
	if (code == aAviationCode) return true;
	else return false;
}

Flight::~Flight()
{
	apCarrier = nullptr;

}