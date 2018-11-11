#include "stdafx.h"

auto CompareBySecond = [](pair<Airport*, int> p1, pair<Airport*, int> p2)
{
	return p1.second > p2.second;
};

//
//Sort Flight based on the SortCriteria and FlightClass
//This method uses the Sort algorithm in the <algorithm> libraries in C++.
//I have modified the compare class in order for the built-in sort algorithm to handle many different sort criteria.
//It is necessary to make the code more compact and more resusable.
//

vector<Flight*> Sort::SortFlight(vector<Flight*> * flightList, SortCriteria sortCriteria, FlightClass flightClass)
{
	vector<Flight*> result;
	int i;
	for (i = 0; i < flightList->size(); ++i)
	{
		result.push_back((*flightList)[i]);
	}
	sort(result.begin(), result.end(), Compare(flightClass, sortCriteria));
	return result;
}

//
//This method returns top connecting airports, i.e. airports having the most direct flights to this airport.
//This method uses the Sort algorithm in the <algorithm> libraries in C++.
//
vector<pair<Airport*, int>> Sort::SortMostConnectingAirport(vector<Flight*>* flightList)
{
	vector<pair<Airport*, int>> result;
	unordered_map<Airport*, int> map;
	unordered_map<Airport*, int>::iterator it;
	Airport* airportTo = nullptr;
	int i;
	int numberOfFlights = flightList->size();
	//
	//Set every count to 0
	//
	for (i = 0; i < numberOfFlights; ++i)
	{
		airportTo = (*flightList)[i]->GetDestination();
		map[airportTo] = 0;
	}
	//
	//Count number of flights connecting to the airportFrom
	//
	for (i = 0; i < numberOfFlights; ++i)
	{
		airportTo = (*flightList)[i]->GetDestination();
		map[airportTo]++;
	}

	for (it = map.begin(); it != map.end(); ++it)
	{
		result.push_back(make_pair(it->first, it->second));
	}
	sort(result.begin(), result.end(), CompareBySecond);
	return result;
}