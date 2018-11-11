#include "stdafx.h"
SearchByTime::SearchByTime()
{
}
vector<MultiFlights> SearchByTime::Execute(MapSingleton * map, Airport * origin, Airport * destination, FlightClass rank, int& maximumPaths)
{
	int i, j;
	bool notMet = true;

	//heap containing paths
	priority_queue<MultiFlights, vector<MultiFlights>, shorter > cheapestPaths;
	//priority_queue<MultiFlights, vector<MultiFlights>, cheaperBUSINESS > cheapestPaths;
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
		MultiFlights m((*origin->GetDepartureFlightInventory()->GetPtrFlightList())[i]);
		cheapestPaths.push(m);
	}
	//
	//
	//
	while (!cheapestPaths.empty() && CheapestPathsTo[destination].size() < maximumPaths)
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
		//for each airport to have at most maximumPaths
		//this is because the final result only has at most maximumPaths, 
		//so each airport only needs to have at most maximumPaths towards it.
		//
		if (CheapestPathsTo[crt_airport].size() <= maximumPaths)
		{
			//
			//We only add an airport to a path if that airport has not been added yet. 
			//This makes sense because a path that contains a cycle is always more expensive than those who do not have. 
			//If we encounter an airport that is either the origin airport or is included in the transit list, it means that
			//we have met this airport already, therefore, notMet = false.
			//Otherwise, notMet = true;
			//We only add the airport to the list if notMet = true;
			//
			for (i = 0; i < crt_airport->GetDepartureFlightInventory()->NumberOfFlights(); ++i)
			{
				notMet = true;
				MultiFlights crt_cheapestPath_copy = crt_cheapestPath;

				Airport* nextDestination = (*crt_airport->GetDepartureFlightInventory()->GetPtrFlightList())[i]->GetDestination();
				if (nextDestination == origin) notMet = false;

				for (j = 0; (j < crt_cheapestPath_copy.GetTransitInventory()->NumberOfAirports()) && notMet; ++j)
				{
					if (nextDestination == (*crt_cheapestPath_copy.GetTransitInventory()->GetPtrAirportList())[j])
						notMet = false;
				}

				if (notMet)
				{
					crt_cheapestPath_copy.AddFlight((*crt_airport->GetDepartureFlightInventory()->GetPtrFlightList())[i]);
					//PriceWithPathPair pair = make_pair(crt_cheapestPath_copy.GetPrice(rank), crt_cheapestPath_copy);
					//cheapestPaths.push(pair);
					cheapestPaths.push(crt_cheapestPath_copy);
				}
			}
		}
	}
	if (CheapestPathsTo[destination].size() < maximumPaths)
		maximumPaths = CheapestPathsTo[destination].size();

	return CheapestPathsTo[destination];
}
