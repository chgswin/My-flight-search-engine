#include "stdafx.h"
Itinerary::Itinerary(Airport * origin, Airport* destination, Time departureTime, Time arrivalTime) :
	aDepartureTime(departureTime),
	aArrivalTime(arrivalTime)
{
	apOrigin = origin;
	apDestination = destination;
}
Itinerary::Itinerary(const Itinerary* i) :
	aDepartureTime(i->aDepartureTime),
	aArrivalTime(i->aArrivalTime)
{
	apOrigin = i->apOrigin;
	apDestination = i->apDestination;
}
Itinerary::Itinerary(const Itinerary&  i) :
	aDepartureTime(i.aDepartureTime), 
	aArrivalTime(i.aArrivalTime)
{
	apOrigin = i.apOrigin;
	apDestination = i.apDestination;
}

void Itinerary::SetOrigin(Airport * airport)
{
	apOrigin = airport;
}
void Itinerary::SetDestination(Airport * airport)
{ 
	apDestination = airport; 
}
Airport* Itinerary::GetOrigin()
{
	return apOrigin;
}
Airport* Itinerary::GetDestination()
{
	return apDestination;
}
Time Itinerary::GetArrivalTime()
{
	return aArrivalTime;
}
Time Itinerary::GetDepartureTime()
{
	return aDepartureTime;
}
string Itinerary::DisplayDepartureAndArrivalTime()
{
	return GetDepartureTime().Display() + " - " + GetArrivalTime().Display();
}
string Itinerary::DisplayDepartureAndArrivalAirport()
{
	return GetOrigin()->GetAviationCode() + " - " + GetDestination()->GetAviationCode();
}
string Itinerary::DisplayPrice(FlightClass rank, int numberPassengers)
{
	return to_string(GetPrice(rank)*numberPassengers);
}

void Itinerary::SetArrivalTime(Time t)
{
	aArrivalTime = t;
}

Itinerary::~Itinerary()
{
	apOrigin = nullptr;
	apDestination = nullptr;
}