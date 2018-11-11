#pragma once
#pragma region ALL LIBRARIES
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <map>
#include <unordered_map>
#include <msclr\marshal_cppstd.h>
#include <stddef.h>
#include <typeindex>
#pragma endregion

using namespace std;

#ifndef FLIGHT_SEARCH_H
#define FLIGHT_SEARCH_H

/// <summary>
/// This enumeration includes BUSINESS and ECONOMY, the rank that passengers choose when boarding a flight.
/// </summary>
enum FlightClass { BUSINESS, ECONOMY };

/// <summary>
/// This enumeration includes SORT_BY_DURATION and SORT_BY_PRICE, the search criteria that the passengers prioritise.
/// </summary>
enum SortCriteria { SORT_BY_DURATION, SORT_BY_PRICE, SORT_BY_ARRIVAL_TIME, SORT_BY_DEPARTURE_TIME };

#pragma region FORWARD_DECLARATION
class Itinerary;
class Flight;
class FlightInventory;
class Airport;
#pragma endregion

/// <summary>
/// Time class takes roles as Time in real world.
/// Time class has information about hour and minute,
/// having the ability to add, substract time.
/// </summary>
class Time
{
	private: int aHour;
	private: int aMin;

	/// <summary>
	/// Initializes a new instance of the <see cref="Time"/> class.
	/// </summary>
	/// <param name="hour">The hour.</param>
	/// <param name="min">The minimum.</param>
	public: Time(int hour, int min);

	/// <summary>
	/// Initializes a new instance of the <see cref="Time" /> class.
	/// </summary>
	/// <param name="t">The Time object we want to copy from.</param>
	public: Time(const Time& t);

	/// <summary>
	/// Finds the duration from the time to this.
	/// </summary>
	/// <param name="time">The time.</param>
	/// <returns>
	/// The duration.
	/// </returns>
	public:	Time FindDuration(Time time);

	/// <summary>
	/// Adds the time.
	/// </summary>
	/// <param name="time">The total time.</param>
	public:	void AddTime(Time time);

	/// <summary>
	/// Gets the hour.
	/// </summary>
	/// <returns>
	/// the Hour number
	/// </returns>
	public: int GetHour();

	/// <summary>
	/// Gets the minute.
	/// </summary>
	/// <returns>
	/// the Minnute number.
	/// </returns>
	public: int GetMin();

	/// <summary>
	/// Displays a string of time in the form "00:00".
	/// </summary>
	/// <returns>
	/// a string to display the time.
	/// </returns>
	public: string Display();

	/// <summary>
	/// Compares this with another Time object.
	/// </summary>
	/// <param name="t">The t.</param>
	/// <returns>
	/// -1 if this is less than the time,
	/// 1 if this is more than the time,
	/// 0 if they are same.
	/// </returns>
	public: int CompareTime(const Time t);
};

/// <summary>
/// IHaveAviationCode provides an interface for Carrier, Flight and Airport.
/// C++ does not support Interface as C# and Java.
/// Therefore, IHaveAviationCode is actually a class.
/// It does not have implementation inside its methods (similarly as Interface).
/// In this app, I have taken advantage of multiple inheritance feature in C++ to create the class that acts as an interface.
/// </summary>
class IHaveAviationCode
{
	/// <summary>
	/// Does nothing as an interface.
	/// </summary>
	public: IHaveAviationCode() {};

	/// <summary>
	/// Finalizes an instance of the <see cref="IHaveAviationCode"/> class.
	/// </summary>
	public: virtual ~IHaveAviationCode() {};

	/// <summary>
	/// Gets the aviation code.
	/// </summary>
	/// <returns>aviationCode by classes that uses this interface.</returns>
	public: virtual string GetAviationCode() = 0;

	/// <summary>
	/// Check if the code is equal to any of the IHaveAviationCode identifiers.
	/// </summary>
	/// <param name="code">The code.</param>
	/// <returns>true or false based on classes that use this interface.</returns>
	public: virtual bool AreYou(string code) = 0;

	/// <summary>
	/// Gets the name.
	/// </summary>
	/// <returns>name by classes that use this interface.</returns>
	public: virtual string GetName() = 0;
};

/// <summary>
/// Carrier represents airlines.
/// It has flights.
/// </summary>
/// <seealso cref="IHaveAviationCode" />
class Carrier : public IHaveAviationCode
{
	private: string aName;
	private: string aAviationCode;

	/// <summary>
	/// Initializes a new instance of the <see cref="Carrier" /> class.
	/// </summary>
	/// <param name="aviationCode">The aviation code.</param>
	/// <param name="name">The name.</param>
	public:	Carrier(string aviationCode, string name);

	/// <summary>
	/// Copies an instance of the <see cref="Carrier" /> class.
	/// </summary>
	/// <param name="c">the Carrier we want to copy.</param>
	public: Carrier(const Carrier& c);

	/// <summary>
	/// Gets the name of the carrier.
	/// </summary>
	/// <returns>
	/// aName
	/// </returns>
	public:	string GetName() override;

	/// <summary>
	/// Gets the aviation code.
	/// </summary>
	/// <returns>
	/// aAviationCode
	/// </returns>
	public:	string GetAviationCode() override;

	/// <summary>
	/// Check whether the code ID matches the carrier aviationCode or the Name.
	/// </summary>
	/// <param name="code">The code.</param>
	/// <returns>
	/// true if matched and false if unmatched.
	/// </returns>
	public:	bool AreYou(string code) override;
	};

/// <summary>
/// Itinerary is the base class for MultiFlights and Flight.
/// Itinerary represents a air trip.
/// It could have a single flight or many flights.
/// But in common, a trip will have travel time, and a price.
/// </summary>
class Itinerary
{
	/// <summary>
	/// The main constructor for the Itinerary class
	/// </summary>
	/// <param name="origin">The origin.</param>
	/// <param name="destination">The destination.</param>
	/// <param name="departureTime">The departure time.</param>
	/// <param name="arrivalTime">The arrival time.</param>
	public:	Itinerary(Airport* origin, Airport* destination, Time departureTime, Time arrivalTime);


	/// <summary>
	/// Copies instance of the <see cref="Itinerary" /> class.
	/// </summary>
	/// <param name="i">Itinerary i needed to be copied.</param>
	public:	Itinerary(const Itinerary& i);


	/// <summary>
	/// Initializes a new instance of the <see cref="Itinerary" /> class based on pointer to another <see cref="Itinerary" /> object.
	/// </summary>
	/// <param name="i">The pointer to another Itinerary class.</param>
	public:	Itinerary(const Itinerary* i);

	/// <summary>
	/// Gets the price.
	/// </summary>
	/// <param name="rank">The rank.</param>
	/// <returns>
	/// 0, but will be overriden by its child classes: MultiFlights and Flight
	/// </returns>
	public:	virtual double GetPrice(FlightClass rank) = 0;

	/// <summary>
	/// Gets the travel time.
	/// </summary>
	/// <returns>
	/// 00:00, but will be overriden by its child classes: MultiFlights and Flight
	/// </returns>
	public:	virtual Time GetTravelTime() = 0;

	/// <summary>
	/// Gets the departure time of the entire Itinerary.
	/// </summary>
	/// <returns>
	/// the Departure time
	/// </returns>
	public:	Time GetDepartureTime();

	/// <summary>
	/// Gets the arrival time of the entire Itinerary.
	/// </summary>
	/// <returns>
	/// the Arrival Time
	/// </returns>
	public:	Time GetArrivalTime();

	/// <summary>
	/// Gets the pointer to the origin.
	/// </summary>
	/// <returns>
	/// apOrigin
	/// </returns>
	public:	Airport* GetOrigin();

	/// <summary>
	/// Gets the destination.
	/// </summary>
	/// <returns>apDestination.</returns>
	public:	Airport* GetDestination();

	/// <summary>
	/// Sets the origin.
	/// </summary>
	/// <param name="origin">The origin.</param>
	public:	void SetOrigin(Airport* origin);

	/// <summary>
	/// Sets the destination.
	/// </summary>
	/// <param name="destination">The destination.</param>
	public:	void SetDestination(Airport* destination);

	/// <summary>
	/// Sets the arrival time.
	/// </summary>
	/// <param name="t">The time.</param>
	public:	void SetArrivalTime(Time t);
	/// <summary>
	/// Displays the departure and arrival time, in the form of "00:00 - 00:00".
	/// </summary>
	/// <returns>the string of departure and arrival time.</returns>
	public:	string DisplayDepartureAndArrivalTime();

	/// <summary>
	/// Displays the price of an itinerary.
	/// </summary>
	/// <param name="rank">The Flight rank.</param>
	/// <param name="numberPassengers">The number of passengers.</param>
	/// <returns>
	/// a string converted from the price of the Itinerary.
	/// </returns>
	public:	string DisplayPrice(FlightClass rank, int numberPassengers);

	/// <summary>
	/// Displays the departure and arrival airport, in the form "A - B".
	/// </summary>
	/// <returns>
	/// a string that shows the aviationCode of the departure airport and the arrival airport
	/// </returns>
	public:	string DisplayDepartureAndArrivalAirport();
	public: ~Itinerary();
	//
	//These fields are marked as protected, meaning that the child classes are able to get access to this field.
	//As this program deals with copy constructors with child classes of this class. Child classes should get access
	//to these when they are being copied.
	//
	protected: Airport* apOrigin;
	protected: Airport* apDestination;
	protected: Time aDepartureTime;
	protected: Time aArrivalTime;
};

/// <summary>
/// Flight class represent flights in real world.
/// A flight is an itinerary, having origin, destination, planned departure time and arrvial time.
/// </summary>
/// <seealso cref="Itinerary" />
/// <seealso cref="IHaveAviationCode" />
class Flight : public Itinerary, public IHaveAviationCode
{
	private: double aBusinessPrice;
	private: double aEconomyPrice;
	private: Carrier * apCarrier;
	private: string aAviationCode;
	/// <summary>
	/// the main constructor for the Flight class
	/// </summary>
	/// <param name="aviationCode">The aviation code.</param>
	/// <param name="origin">The origin.</param>
	/// <param name="destination">The destination.</param>
	/// <param name="carrier">The carrier.</param>
	/// <param name="departureTime">The departure time.</param>
	/// <param name="arrivalTime">The arrival time.</param>
	/// <param name="bussinessPrice">The bussiness price of this flight.</param>
	/// <param name="economyPrice">The economy price of this flight.</param>
	public:	Flight(string aviationCode, Airport* origin, Airport* destination, Carrier * carrier, Time departureTime, Time arrivalTime, double bussinessPrice, double economyPrice);

	/// <summary>
	/// Copies the instance of the <see cref="Flight" /> class.
	/// </summary>
	/// <param name="flight">The flight.</param>
	public:	Flight(const Flight& flight);

	/// <summary>
	/// Gets the travel time.
	/// </summary>
	/// <returns>
	/// the duration from to departure time to arrival time
	/// </returns>
	public:	Time GetTravelTime() override;

	/// <summary>
	/// Gets the price based on the Flight Class.
	/// </summary>
	/// <param name="rank">The flight rank.</param>
	/// <returns>
	/// 0, but will be overriden by its child classes: MultiFlights and Flight
	/// </returns>
	public:	double GetPrice(FlightClass rank) override;

	/// <summary>
	/// Gets the pointer to the carrier.
	/// </summary>
	/// <returns>
	/// its own carrier
	/// </returns>
	public:	Carrier* GetCarrier();

	/// <summary>
	/// Gets the aviation code.
	/// </summary>
	/// <returns>the aviationCode of the flight.</returns>
	public:	string GetAviationCode() override;

	/// <summary>
	/// Ares you.
	/// </summary>
	/// <param name="code">The code.</param>
	/// <returns>true if the code matches any of the flight identifiers, false otherwise..</returns>
	public:	bool AreYou(string code) override;

	/// <summary>
	/// Gets the name of the flight.
	/// </summary>
	/// <returns>
	/// "Flight CODE from A to B"
	/// </returns>
	public:	string GetName() override;			
	/// <summary>
	/// Finalizes an instance of the <see cref="Flight"/> class.
	/// </summary>
	~Flight();
};

/// <summary>
/// FlightInventory is the class responsible for managing a list of Flight
/// </summary>
class FlightInventory
{
	private: vector<Flight*> aFlightList;

	/// <summary>
	/// The constructor for Flight Inventory
	/// </summary>
	public:	FlightInventory();

	/// <summary>
	/// Copies instance of the <see cref="FlightInventory" /> class.
	/// </summary>
	/// <param name="fi">The flight inventory we want to copy.</param>
	public:	FlightInventory(const FlightInventory& fi);

	/// <summary>
	/// Adds the flight.
	/// </summary>
	/// <param name="f">The f.</param>
	public: void AddFlight(Flight* f);

	/// <summary>
	/// Removes the flight.
	/// </summary>
	/// <param name="f">The f.</param>
	public: void RemoveFlight(Flight* f);

	/// <summary>
	/// Numbers the of flights.
	/// </summary>
	/// <returns>
	/// size of the flight vector
	/// </returns>
	public: int NumberOfFlights();

	/// <summary>
	/// Locates the flight by code.
	/// </summary>
	/// <param name="code">The code.</param>
	/// <returns>pointer to a flight if the code matches, otherwise returns nullptr.</returns>
	public: Flight* LocateFlightByCode(string code);

	/// <summary>
	/// Gets the pointer to the flight list.
	/// </summary>
	/// <returns>
	/// pointer to the flight list.
	/// </returns>
	public: vector<Flight*>* GetPtrFlightList();
};

/// <summary>
/// Airport class represents airports in real world.
/// They are located in city, having its own aviationCode and name.
/// They contain Departure Flights and Arrival Flights.
/// </summary>
/// <seealso cref="IHaveAviationCode" />
class Airport : public IHaveAviationCode
{
	private: string aName;
	private: string aAviationCode;
	private: string aCityName;
	private: FlightInventory aDepartureFlightInventory;
	private: FlightInventory aArrivalFlightInventory;

	/// <summary>
	/// the main constructor for class Airport
	/// </summary>
	/// <param name="aviationCode">The aviation code.</param>
	/// <param name="cityName">Name of the city.</param>
	/// <param name="name">The name.</param>
	public:	Airport(string aviationCode, string cityName, string name);

	/// <summary>
	/// the copy constructor for class Airport
	/// </summary>
	/// <param name="airport">The airport.</param>
	public: Airport(const Airport& airport);

	/// <summary>
	/// A getter for the name field of Airport
	/// </summary>
	/// <returns>
	/// aName string field
	/// </returns>
	public: string GetName() override;

	/// <summary>
	/// Gets the AviationCode
	/// </summary>
	/// <returns>
	/// aAviationCode string field
	/// </returns>
	public: string GetAviationCode() override;

	/// <summary>
	/// check if the string matches the aAviationCode or the aCityName or the aName field
	/// </summary>
	/// <param name="ID">the ID string</param>
	/// <return>
	/// aAviationCode string field
	/// </return>
	/// <value>
	/// true if ID matches one of them
	/// false if ID does not match any of them
	/// </value>
	public: bool AreYou(string ID) override;

	/// <summary>
	/// Gets the city name where the airport is located
	/// </summary>
	/// <returns>
	/// aCityName string field
	/// </returns>
	public: string GetCityName();

	/// <summary>
	/// Gets the pointer departure flight inventory.
	/// </summary>
	/// <returns>the pointer to the arrival flight inventory</returns>
	public: FlightInventory* GetDepartureFlightInventory();

	/// <summary>
	/// Gets the pointer to the arrival flight inventory.
	/// </summary>
	/// <returns>
	/// the pointer to the arrival flight inventory.
	/// </returns>
	public: FlightInventory* GetArrivalFlightInventory();
	};

/// <summary>
/// AirportInventory is responsible for managing a list of airports.
/// </summary>
class AirportInventory
{
	private: vector<Airport*> aAirportList;

	/// <summary>
	/// Initializes a new instance of the <see cref="AirportInventory"/> class.
	/// </summary>
	public:	AirportInventory();

	/// <summary>
	/// Initializes a new instance of the <see cref="AirportInventory" /> class.
	/// </summary>
	/// <param name="AI">The airport inventory we want to copy.</param>
	public:	AirportInventory(const AirportInventory& AI);

	/// <summary>
	/// Adds the airport.
	/// </summary>
	/// <param name="pAirport">pointer to the airport we want to add</param>
	public:	void AddAirport(Airport* pAirport);

	/// <summary>
	/// Removes the airport from the Inventory.
	/// </summary>
	/// <param name="pAirport">The p airport.</param>
	public:	void RemoveAirport(Airport* pAirport);

	/// <summary>
	/// Gets number the of airports.
	/// </summary>
	/// <returns>the number of airports of the inventory.</returns>
	public:	int NumberOfAirports();

	/// <summary>
	/// Gets the pointer to the airport list.
	/// </summary>
	/// <returns>pointer to the airport list.</returns>
	public:	vector<Airport*> * GetPtrAirportList();

	/// <summary>
	/// Locates the airport by code.
	/// </summary>
	/// <param name="code">The code of the map element we want to search for.</param>
	/// <returns>
	/// null if no airport has the code or name or city name matching the code or the pointer
	/// to the airport if we successfully locate the airport
	/// </returns>
	public:	Airport* LocateAirportByCode(string code);
};

/// <summary>
/// CarrierInventory is responsible for managing a list of carriers.
/// </summary>
class CarrierInventory
{
	private: vector<Carrier*> aCarrierList;

	/// <summary>
	/// Initializes a new instance of the <see cref="CarrierInventory"/> class.
	/// </summary>
	public:	CarrierInventory();

	/// <summary>
	/// Copy the instance of the <see cref="CarrierInventory" /> class.
	/// </summary>
	/// <param name="CI">The carrier inventory we want to copy from.</param>
	public: CarrierInventory(const CarrierInventory& CI);

	/// <summary>
	/// Adds the carrier.
	/// </summary>
	/// <param name="c">The c.</param>
	public:	void AddCarrier(Carrier* c);

	/// <summary>
	/// Removes the carrier.
	/// </summary>
	/// <param name="c">The c.</param>
	public: void RemoveCarrier(Carrier* c);

	/// <summary>
	/// Numbers the of carriers.
	/// </summary>
	/// <returns>
	/// size of the aCarrierList
	/// </returns>
	public:	int NumberOfCarriers();

	/// <summary>
	/// Gets the pointer to the carrier list.
	/// </summary>
	/// <returns>
	/// address of the carrier list
	/// </returns>
	public:	vector<Carrier*> * GetPtrCarrierList();

	/// <summary>
	/// Locates the carrier by code.
	/// </summary>
	/// <param name="code">The code.</param>
	/// <returns>
	/// null if code does not match and pointer to the carrier if it matches.
	/// </returns>
	public:	Carrier* LocateCarrierByCode(string code);
};

/// <summary>
/// MultiFLights deals with all trips that contain a series of flights.
/// </summary>
/// <seealso cref="Itinerary" />
class MultiFlights : public Itinerary
{
	private: AirportInventory aTransitInventory;
	private: FlightInventory aFlightInventory;
	
	/// <summary>
	/// Initializes a new instance of the <see cref="MultiFlights" /> class.
	/// </summary>
	/// <param name="flight">The flight.</param>
	public:	MultiFlights(Flight* flight);

	/// <summary>
	/// Initializes a new instance of the <see cref="MultiFlights" /> class.
	/// </summary>
	/// <param name="multiFlights">The multi flights.</param>
	public: MultiFlights(const MultiFlights& multiFlights);

	/// <summary>
	/// Gets the travel time.
	/// </summary>
	/// <returns>
	/// the total travel time.
	/// </returns>
	public: Time GetTravelTime() override;

	/// <summary>
	/// Gets the price.
	/// </summary>
	/// <param name="rank">The rank.</param>
	/// <returns>
	/// the total price in all flights.
	/// </returns>
	public: double GetPrice(FlightClass rank) override;

	/// <summary>
	/// Adds the flight to aFlightInventory.
	/// </summary>
	/// <param name="f">The pointer to a flight.</param>
	public: void AddFlight(Flight* pFlight);

	/// <summary>
	/// Checks whether there is only one carrier responsible for all flights.
	/// </summary>
	/// <returns>
	/// true if there is only one carrier operating in all flights, false otherwise.
	/// </returns>
	public: bool CheckMultiCarriers();

	/// <summary>
	/// Displays all carriers.
	/// </summary>
	/// <returns>
	/// the string that have the name of all the carriers operating in this MultiFlights.
	/// </returns>
	public: string DisplayCarriers();

	/// <summary>
	/// Displays the transit list.
	/// </summary>
	/// <returns>
	/// the string that have aviationCode of all the airport this MultiFlights stops over at.
	/// </returns>
	public: string DisplayTransitList();

	/// <summary>
	/// Gets the transit inventory.
	/// </summary>
	/// <returns>
	/// the address of this aTransitInventory.
	/// </returns>
	public: AirportInventory* GetTransitInventory();

	/// <summary>
	/// Gets the flight inventory.
	/// </summary>
	/// <returns>
	/// the address of this aFlightInventory.
	/// </returns>
	public: FlightInventory* GetFlightInventory();

	/// <summary>
	/// Gets the transit time.
	/// </summary>
	/// <param name="i">index for the transit airport we want to get the time.</param>
	/// <returns>the transit duration for a specific stop.</returns>
	public: Time GetTransitTime(int i);

	/// <summary>
	/// Gets the number of stops.
	/// </summary>
	/// <returns>print out the number of stops.</returns>
	public:	string DisplayNumberOfStops();
};

/// <summary>
///  
/// </summary>
class UserPreference
{	
	/// <summary>
	/// The number of passengers
	/// </summary>
	private: int aNumberOfPassengers;
	private: int aMaxPrice;
	private: Time aMaxTime;
	private: int aMaxTransit;
	private: FlightClass aFlightClass;
	private: SortCriteria aSortCriteria;

	/// <summary>
	/// Resets this instance.
	/// </summary>
	public: void Reset();		
	/// <summary>
	/// Initializes a new instance of the <see cref="UserPreference" /> struct.
	/// </summary>
	public: UserPreference();
	public:	
	/// <summary>
	/// Gets the number of passengers.
	/// </summary>
	/// <returns>return the number of passengers travelling with this user.</returns>
	int GetNumberOfPassengers();	
	/// <summary>
	/// Gets the maximum price.
	/// </summary>
	/// <returns>return the maximum price that the user is willing to pay.</returns>
	int GetMaxPrice();	
	/// <summary>
	/// Gets the maximum time.
	/// </summary>
	/// <returns>returns the maximum time that the user is willing to spend on their trip.</returns>
	Time GetMaxTime();	
	/// <summary>
	/// Gets the maximum transit.
	/// </summary>
	/// <returns>returns the maximum number of stops the user wants.</returns>
	int GetMaxTransit();	
	/// <summary>
	/// Gets the flight class.
	/// </summary>
	/// <returns>returns the flight rank (ECONOMY, BUSINESS) the user chooses.</returns>
	FlightClass GetFlightClass();	
	/// <summary>
	/// Gets the sort criteria.
	/// </summary>
	/// <returns>the sorting criteria.</returns>
	SortCriteria GetSortCriteria();	
	/// <summary>
	/// Sets the number of passengers.
	/// </summary>
	/// <param name="numberOfPassengers">The number of passengers.</param>
	void SetNumberOfPassengers(int numberOfPassengers);	
	/// <summary>
	/// Sets the maximum price.
	/// </summary>
	/// <param name="maxPrice">The maximum price.</param>
	void SetMaxPrice(int maxPrice);	
	/// <summary>
	/// Sets the maximum time.
	/// </summary>
	/// <param name="maxTime">The maximum time.</param>
	void SetMaxTime(Time maxTime);	
	/// <summary>
	/// Sets the maximum transit.
	/// </summary>
	/// <param name="maxTransit">The maximum transit.</param>
	void SetMaxTransit(int maxTransit);	
	/// <summary>
	/// Sets the flight class.
	/// </summary>
	/// <param name="flightClass">The flight class.</param>
	void SetFlightClass(FlightClass flightClass);	
	/// <summary>
	/// Sets the sort criteria.
	/// </summary>
	/// <param name="SortCriteria">The sort criteria.</param>
	void SetSortCriteria(SortCriteria SortCriteria);
};

/// <summary>
/// User contains the information of user who uses this app.
/// </summary>
	class User {
	private: string aID;
	private: UserPreference aPreference;
	private: vector<IHaveAviationCode*> aSearchHistory;
	private: string aPassword;
	/// <summary>
	/// Initializes a new instance of the <see cref="User"/> class.
	/// </summary>
	/// <param name="ID">The identifier.</param>
	/// <param name="password">The password.</param>
	public: User(string ID, string password);

	/// <summary>
	/// Adds the search history.
	/// </summary>
	/// <param name="i">The i.</param>
	public: void AddSearchHistory(IHaveAviationCode* i);
	/// <summary>
	/// Clears the search history.
	/// </summary>
	public: void ClearSearchHistory();
	/// <summary>
	/// Gets the identifier.
	/// </summary>
	/// <returns>get user ID</returns>
	public: string GetID();
	/// <summary>
	/// Gets the password.
	/// </summary>
	/// <returns>get user password.</returns>
	public: string GetPassword();		 
	/// <summary>
	/// Gets the PTR search history.
	/// </summary>
	/// <returns>get pointer to the search history.</returns>
	public: vector<IHaveAviationCode*>* GetPtrSearchHistory();		 
	/// <summary>
	/// Determines whether this instance is admin.
	/// </summary>
	/// <returns>
	///   <c>true</c> if this instance is admin; otherwise, <c>false</c>.
	/// </returns>
	public: virtual bool IsAdmin() = 0;		 
	/// <summary>
	/// Sets the password.
	/// </summary>
	/// <param name="newPassword">The new password.</param>
	public: void SetPassword(string newPassword);		 
	/// <summary>
	/// Gets the search preference.
	/// </summary>
	/// <returns>the search preference of the user</returns>
	public: UserPreference* GetSearchPreference();
};

/// <summary>
/// StandardUser is the ordinary user of this app, different from the admin.
/// </summary>
/// <seealso cref="User" />
class StandardUser : public User
{	
	/// <summary>
	/// Initializes a new instance of the <see cref="StandardUser"/> class.
	/// </summary>
	/// <param name="ID">The identifier.</param>
	/// <param name="password">The password.</param>
	public:	StandardUser(string ID, string password);
	/// <summary>
	/// Determines whether this instance is admin.
	/// </summary>
	/// <returns>
	///   <c>true</c> if this instance is admin; otherwise, <c>false</c>.
	/// </returns>
	public: bool IsAdmin() override;
};

/// <summary>
/// Admin user is the admin of this app.
/// </summary>
/// <seealso cref="User" />
class Admin : public User
{ 	
	/// <summary>
	/// Initializes a new instance of the <see cref="Admin"/> class.
	/// </summary>
	/// <param name="ID">The identifier.</param>
	/// <param name="password">The password.</param>
	public: Admin(string ID, string password);
	/// <summary>
	/// Determines whether this instance is admin.
	/// </summary>
	/// <returns>
	///   <c>true</c> if this instance is admin; otherwise, <c>false</c>.
	/// </returns>
	public: bool IsAdmin() override;
};

/// <summary>
/// The factory class is responsible for creating the object for this application.
/// This is where the factory design pattern is applied.
/// </summary>
class Factory
{
	/// <summary>
	/// Creates the map element, using the Factory design pattern.
	/// </summary>
	/// <param name="stringList">The string list.</param>
	/// <param name="AI">The pointer to the Airport Inventory.</param>
	/// <param name="CI">The pointer to the Carrier Inventory.</param>
	/// <param name="FI">The pointer to the FlightInventory.</param>
	public:	void CreateMapElement(vector<string> stringList, AirportInventory* AI, CarrierInventory* CI, FlightInventory* FI);			

	/// <summary>
	/// Creates the user.
	/// </summary>
	/// <param name="stringList">The string list.</param>
	/// <returns>the pointer to user newly created.</returns>
	public:	User * CreateUser(vector<string> stringList);
};

/// <summary>
/// User control is responsible for the sign-in, sign-out and registration of the users to this application.
/// </summary>
class UserControlSingleton
{
private: UserControlSingleton();
private: UserControlSingleton(UserControlSingleton const&) {};
private: UserControlSingleton & operator=(UserControlSingleton const&) {};
private: static UserControlSingleton* u_Instance;
private: map<string, User*> aUserMap;
private: Factory userFactory;

public: 	
	/// <summary>
	/// Determines whether [is username taken] [the specified new username].
	/// </summary>
	/// <param name="newUsername">The new username.</param>
	/// <returns>
	///   <c>true</c> if [is username taken] [the specified new username]; otherwise, <c>false</c>.
	/// </returns>
public: bool IsUsernameTaken(string newUsername);	
	/// <summary>
	/// Adds the user.
	/// </summary>
	/// <param name="newUser">The new user.</param>
public:	void AddUser(User* newUser);
	/// <summary>
	/// Gets the current user.
	/// </summary>
	/// <param name="userName">Name of the user.</param>
	/// <param name="password">The password.</param>
	/// <returns>pointer to current user.</returns>
public:	User * GetCurrentUser(string userName, string password);
	/// <summary>
	/// Instances this instance.
	/// </summary>
	/// <returns>pointer to the usercontrol object.</returns>
public:	static UserControlSingleton* Instance();
	/// <summary>
	/// Loads the data.
	/// </summary>
	/// <param name="filename">The filename.</param>
public:	void LoadData(string filename);
	/// <summary>
	/// Saves the data.
	/// </summary>
	/// <param name="filename">The filename.</param>
public:	void SaveData(string filename);
	/// <summary>
	/// Finalizes an instance of the <see cref="UserControlSingleton"/> class.
	/// </summary>
public:	~UserControlSingleton();
};

/// <summary>
/// MapSingleton is the representation of Map in the app.
/// </summary>
class MapSingleton
{
	private: MapSingleton();
	private: MapSingleton(MapSingleton const&) {};
	private: MapSingleton& operator=(MapSingleton const&) {};
	private: static MapSingleton* m_Instance;
	private: FlightInventory aFlightInventory;
	private: AirportInventory aAirportInventory;
	private: CarrierInventory aCarrierInventory;

	/// <summary>
	/// Instances this instance.
	/// </summary>
	/// <returns>
	/// A new MapSingleton Object if there has not been any MapSingleton object created before.
	/// </returns>
	public:	static MapSingleton* Instance();
	/// <summary>
	/// Organize all the map element in the right order.
	/// </summary>
	public:	void Organize();

	/// <summary>
	/// Gets the pointer to the flight inventory.
	/// </summary>
	/// <returns>
	/// the pointer to the flight inventory
	/// </returns>
	public: FlightInventory* GetFlightInventory();

	/// <summary>
	/// Gets the pointer to the airport inventory.
	/// </summary>
	/// <returns>
	/// the pointer to the airport inventory
	/// </returns>
	public: AirportInventory* GetAirportInventory();

	/// <summary>
	/// Loads the data.
	/// </summary>
	/// <param name="filename">The filename.</param>
	public: void LoadData(string filename);

	public: ~MapSingleton();
};

/// <summary>
/// Search is responsible for finding the best flights.
/// </summary>
class Search
{
	/// <summary>
	/// Search for the best trips.
	/// </summary>
	/// <param name="map">The pointer to the map.</param>
	/// <param name="origin">The pointer to the origin airport.</param>
	/// <param name="destination">The pointer to the destination airport.</param>
	/// <param name="rank">The flight rank.</param>
	/// <param name="maximumFlights">The maximum flights we want to get.</param>
	/// <returns>
	/// a vector having the best MultiFlights
	/// </returns>
	public:	vector<MultiFlights> Execute(MapSingleton * map, Airport * origin, Airport * destination, UserPreference * userPreference, int& maxPaths);	
/// <summary>
/// Determines whether the specified multi flight is satisfied with the user Preference.
/// </summary>
/// <param name="multiFlight">The multi flight.</param>
/// <param name="p">The p.</param>
/// <returns>
///   <c>true</c> if the specified multi flight is satisfied; otherwise, <c>false</c>.
/// </returns>
	public: bool IsSatisfied(MultiFlights * multiFlight, UserPreference * p);
};

/// <summary>
/// Sort is responsible for the sorting action in the application.
/// </summary>
class Sort
{		
	/// <summary>
	/// Sorts the flight.
	/// </summary>
	/// <param name="flightList">The pointer to flight list.</param>
	/// <param name="sortCriteria">The sort criteria.</param>
	/// <param name="flightClass">The flight class.</param>
	/// <returns>The sorted flights, based on the sort criteria.</returns>
	
	public:	vector<Flight*> SortFlight(vector<Flight*> * flightList, SortCriteria sortCriteria = SORT_BY_PRICE, FlightClass flightClass = ECONOMY);		
	/// <summary>
	/// Sorts the most connecting airport.
	/// </summary>
	/// <param name="ptrFlightList">The PTR flight list.</param>
	/// <returns>a vector of pair matching the airport with the number of its direct-connected airports.</returns>
	public: vector<pair<Airport*, int>> SortMostConnectingAirport(vector<Flight*>* ptrFlightList);
};

/// <summary>
/// Compare struct is responsible for determining the way to compare two Itinerary objects.
/// </summary>
struct Compare
{
	FlightClass flightClass;
	SortCriteria sortCriteria;
 	
	/// <summary>
	/// Initializes a new instance of the <see cref="Compare"/> struct.
	/// </summary>
	/// <param name="flightClass">The flight class.</param>
	/// <param name="sortCriteria">The sort criteria.</param>
	Compare(FlightClass flightClass, SortCriteria sortCriteria);
	
	/// <summary>
	/// The operator of this class gives comparison of the two itinerary a and b.
	/// This is used by search and sort object.
	/// </summary>
	/// <param name="a">first itineray.</param>
	/// <param name="b">second itineary.</param>
	/// <returns>the </returns>
	int operator() (Itinerary *a, Itinerary *b);
	int operator() (Itinerary& a, Itinerary& b);
};

static std::string ToLower(std::string s)
{
	int i = 0;
	std::string result = "";
	for (i = 0; i < s.size(); ++i)
	{
		if (s[i] >= 'A' && s[i] <= 'Z') result += s[i] - 'A' + 'a';
		else result += s[i];
	}
	return result;
}
#endif