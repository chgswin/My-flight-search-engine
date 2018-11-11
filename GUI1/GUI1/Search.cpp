#include "stdafx.h"
//
//
//
vector<MultiFlights> Search::Execute(MapSingleton * map, Airport * origin, Airport * destination, UserPreference * userPreference, int& maxPaths)
{

	int i, j;
	bool notMet = true;
	Compare compare = Compare(userPreference->GetFlightClass(), userPreference->GetSortCriteria());
	//
	//heap containing paths
	//
	priority_queue<MultiFlights, vector<MultiFlights>, decltype(compare)> cheapestPaths(compare);
	unordered_map<Airport*, vector<MultiFlights>> CheapestPathsTo;
	//
	//Initialize the map
	//Map an airport variable with 
	//a vector of its cheapest paths from origin
	//
	for (i = 0; i < map->GetAirportInventory()->NumberOfAirports(); ++i)
	{
		CheapestPathsTo[(*map->GetAirportInventory()->GetPtrAirportList())[i]] = vector<MultiFlights>();
	}
	//
	//Push all flights (in the form of multiflight) into the heap
	//
	for (i = 0; i < origin->GetDepartureFlightInventory()->NumberOfFlights(); ++i)
	{
		vector<Flight*>* v = origin->GetDepartureFlightInventory()->GetPtrFlightList();
		Flight* f = (*v)[i];
		MultiFlights m(f);
		if (IsSatisfied(&m, userPreference)) cheapestPaths.push(m);
	}
	//
	//
	//
	while (!cheapestPaths.empty() && CheapestPathsTo[destination].size() < maxPaths)
	{
		//
		//Get the cheapest path in the heap 
		//
		MultiFlights crt_cheapestPath = cheapestPaths.top();
		//
		//Remove that cheapest path out of the heap
		//
		cheapestPaths.pop();
		//
		//get the airport that the cheapest path going towards
		//
		Airport * crt_airport = crt_cheapestPath.GetDestination();
		CheapestPathsTo[crt_airport].push_back(crt_cheapestPath);
		//
		//in order to save time, we only limit the vectors of cheapest paths 
		//for each airport to have at most maxPaths
		//this is because the final result only has at most maxPaths, 
		//so each airport only needs to have at most maxPaths towards it.
		//
		if (CheapestPathsTo[crt_airport].size() <= maxPaths)
		{
			//
			//We only add a flight to a route if that airport has not been added yet. 
			//This makes sense because a path that contains a cycle is always more expensive than those not having. 
			//If we encounter an airport that is either the origin airport or is included in the transit list, it means that
			//we have met this airport already, therefore, notMet = false.
			//Otherwise, notMet = true;
			//We only add the airport to the priority_queue if notMet = true;
			//
			for (i = 0; i < crt_airport->GetDepartureFlightInventory()->NumberOfFlights(); ++i)
			{
				notMet = true;
				MultiFlights crt_cheapestPath_copy = crt_cheapestPath;

				Airport* nextDestination = (*crt_airport->GetDepartureFlightInventory()->GetPtrFlightList())[i]->GetDestination();
				if (nextDestination == origin) notMet = false;
				//
				//check whether the next destination is the same as the airport we have already stopped over (this is callled path cycle check).
				//
				for (j = 0; (j < crt_cheapestPath_copy.GetTransitInventory()->NumberOfAirports()) && notMet; ++j)
				{
					if (nextDestination == (*crt_cheapestPath_copy.GetTransitInventory()->GetPtrAirportList())[j])
						notMet = false;
				}
				if (notMet)
				{
					crt_cheapestPath_copy.AddFlight((*crt_airport->GetDepartureFlightInventory()->GetPtrFlightList())[i]);
					if (IsSatisfied(&crt_cheapestPath_copy, userPreference)) 
						cheapestPaths.push(crt_cheapestPath_copy);
				}
			}
		}
	}
	//
	//if the result contains fewer multiflights than expected, assign the number of multiflights found to maxPaths.
	//this assignment actually changes the value in maxFlights, because maxFlights in passed in by reference.
	//
	if (CheapestPathsTo[destination].size() < maxPaths)
		maxPaths = CheapestPathsTo[destination].size();

	return CheapestPathsTo[destination];
}
//
//check if a trip satisfies the user wish.
//trips that do not satisfy this wish will be eliminated.
//This method is useful in the advanced search.
//
bool Search::IsSatisfied(MultiFlights * checkedMultiFlights, UserPreference * preference)
{
	if ((checkedMultiFlights->GetPrice(preference->GetFlightClass())) > (preference->GetMaxPrice())) return false;
	if (checkedMultiFlights->GetTravelTime().CompareTime(preference->GetMaxTime()) == 1) return false;
	if (checkedMultiFlights->GetTransitInventory()->NumberOfAirports() > preference->GetMaxTransit()) return false;
	return true;
}