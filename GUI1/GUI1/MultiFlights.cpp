#include "stdafx.h"
MultiFlights::MultiFlights(Flight * flight) : Itinerary(flight)
{
	aFlightInventory.AddFlight(flight);
	SetDestination(flight->GetDestination());
	SetArrivalTime(flight->GetArrivalTime());
}
MultiFlights::MultiFlights(const MultiFlights& m): Itinerary(m.apOrigin, m.apDestination, m.aDepartureTime, m.aArrivalTime)
{
	aFlightInventory = m.aFlightInventory;
	aTransitInventory = m.aTransitInventory;
}
void MultiFlights::AddFlight(Flight * flight)
{
	aFlightInventory.AddFlight(flight);
	aTransitInventory.AddAirport(flight->GetOrigin());
	SetDestination(flight->GetDestination());
	SetArrivalTime(flight->GetArrivalTime());
}

AirportInventory* MultiFlights::GetTransitInventory()
{
	return &aTransitInventory;
}
FlightInventory* MultiFlights::GetFlightInventory()
{
	return &aFlightInventory;
}
double MultiFlights::GetPrice(FlightClass rank)
{
	double result = 0;
	unsigned int i;
	//
	//Get price of a particular class, then add all the price of each flight together.
	//
	for (i = 0; i < aFlightInventory.NumberOfFlights(); ++i)
	{
		result += (*aFlightInventory.GetPtrFlightList())[i]->GetPrice(rank);
	}
	return result;
}

Time MultiFlights::GetTravelTime()
{
	Time result(0, 0);
	
	int lastFlightIndex = aFlightInventory.NumberOfFlights() - 1;
	if (lastFlightIndex < 0)
		return result;
		
	int i;
	//
	//Get travel duration of each flight first, then add them together.
	//
	for (i = 0; i <= lastFlightIndex; ++i)
	{
		result.AddTime((*aFlightInventory.GetPtrFlightList())[i]->GetTravelTime());
	}
	for (i = 0; i <= lastFlightIndex - 1; ++i)
	{
		Time transitStartTime = (*aFlightInventory.GetPtrFlightList())[i]->GetArrivalTime();
		Time transitEndTime = (*aFlightInventory.GetPtrFlightList())[i+1]->GetDepartureTime();
		Time transitDuration = transitEndTime.FindDuration(transitStartTime);
		result.AddTime(transitDuration);
	}
	return result;
}
//
//This method is useful in the displaying result to the main form.
//
bool MultiFlights::CheckMultiCarriers()
{
	//
	//Loop from the start to the end of the Flight Inventory.
	//In each loop, check whether carriers of flight in each pair are the same.
	//If there exists any pair of flights whose carriers are different, return true.
	//otherwise, return false.
	//
	int i = 0;
	while (i + 1 <= aFlightInventory.NumberOfFlights() - 1 && 
		((*aFlightInventory.GetPtrFlightList())[i]->GetCarrier() == (*aFlightInventory.GetPtrFlightList())[i+1]->GetCarrier() ))
	{
		i++;
	}
	if (i + 1 == aFlightInventory.NumberOfFlights()) return false;
	else return true;
}

//
//This method is useful in displaying result to the main form.
//
string MultiFlights::DisplayTransitList()
{
	string result = "";
	int i = 0;
	//
	//If there is no airport in the Transit Inventory, the trip is a direct flight.
	//Print out "NONSTOP".
	//
	if (!aTransitInventory.NumberOfAirports()) result = "NONSTOP";
	//
	//Otherwise, print out the list of stopover airport, each airport name seperated by a comma ",".
	//
	for (i = 0; i < aTransitInventory.NumberOfAirports(); ++i)
	{
		result += (*aTransitInventory.GetPtrAirportList())[i]->GetAviationCode();
		if (i == aTransitInventory.NumberOfAirports() - 1) result += ".";
		else result += ", ";
	}
	return result;
}
//
//This method is useful in displaying result to the main form.
//
string MultiFlights::DisplayCarriers()
{
	string result = "";
	int i;
	if (!CheckMultiCarriers()) result = (*aFlightInventory.GetPtrFlightList())[0]->GetCarrier()->GetName();
	else
	{
		for (i = 0; i < aFlightInventory.NumberOfFlights(); ++i)
		{
			result += (*aFlightInventory.GetPtrFlightList())[i]->GetCarrier()->GetName();
			if (i == aFlightInventory.NumberOfFlights() - 1) result += ".";
			else result += ", ";
		}
	}
	return result;
}
//
//This method return the transit duration for each transit airport (represented by the index i)
//It calculates the time from when the previous flight arrives to when the next flight takes off.
//
Time MultiFlights::GetTransitTime(int i)
{
	if (i > aTransitInventory.NumberOfAirports()) return Time(0, 0);
	Time transitStartTime = (*aFlightInventory.GetPtrFlightList())[i]->GetArrivalTime();
	Time transitEndTime = (*aFlightInventory.GetPtrFlightList())[i + 1]->GetDepartureTime();
	Time transitDuration = transitEndTime.FindDuration(transitStartTime);
	return transitDuration;
}

//
//This method is useful in displaying result to the main form.
//
string MultiFlights::DisplayNumberOfStops()
{
	//
	//If the trip is direct, print out "Direct flight"
	//else print out (N) STOPS.
	if (aTransitInventory.NumberOfAirports() == 0) return "Direct Flight.";
	else return to_string(aTransitInventory.NumberOfAirports()) + " stop(s).";
}