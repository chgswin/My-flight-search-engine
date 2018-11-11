<?xml version="1.0"?><doc>
<members>
<member name="T:FlightClass" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="21">
<summary>
This enumeration includes BUSINESS and ECONOMY, the rank that passengers choose when boarding a flight.
</summary>
</member>
<member name="T:SortCriteria" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="26">
<summary>
This enumeration includes SORT_BY_DURATION and SORT_BY_PRICE, the search criteria that the passengers prioritise.
</summary>
</member>
<member name="T:Time" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="38">
<summary>
Time class takes roles as Time in real world.
Time class has information about hour and minute,
having the ability to add, substract time.
</summary>
</member>
<member name="M:Time.#ctor(System.Int32,System.Int32)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="48">
<summary>
Initializes a new instance of the <see cref="T:Time"/> class.
</summary>
<param name="hour">The hour.</param>
<param name="min">The minimum.</param>
</member>
<member name="M:Time.#ctor(Time!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="55">
<summary>
Initializes a new instance of the <see cref="T:Time"/> class.
</summary>
<param name="t">The Time object we want to copy from.</param>
</member>
<member name="M:Time.FindDuration(Time)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="61">
<summary>
Finds the duration from the time to this.
</summary>
<param name="time">The time.</param>
<returns>
The duration.
</returns>
</member>
<member name="M:Time.AddTime(Time)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="70">
<summary>
Adds the time.
</summary>
<param name="time">The total time.</param>
</member>
<member name="M:Time.GetHour" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="76">
<summary>
Gets the hour.
</summary>
<returns>
the Hour number
</returns>
</member>
<member name="M:Time.GetMin" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="84">
<summary>
Gets the minute.
</summary>
<returns>
the Minnute number.
</returns>
</member>
<member name="M:Time.Display" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="92">
<summary>
Displays a string of time in the form "00:00".
</summary>
<returns>
a string to display the time.
</returns>
</member>
<member name="M:Time.CompareTime(Time!System.Runtime.CompilerServices.IsConst)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="100">
<summary>
Compares this with another Time object.
</summary>
<param name="t">The t.</param>
<returns>
-1 if this is less than the time,
1 if this is more than the time,
0 if they are same.
</returns>
</member>
<member name="T:IHaveAviationCode" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="112">
<summary>
IHaveAviationCode provides an interface for Carrier, Flight and Airport.
C++ does not support Interface as C# and Java.
Therefore, IHaveAviationCode is actually a class.
It does not have implementation inside its methods (similarly as Interface).
In this app, I have taken advantage of multiple inheritance feature in C++ to create the class that acts as an interface.
</summary>
</member>
<member name="M:IHaveAviationCode.#ctor" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="121">
<summary>
Does nothing as an interface.
</summary>
</member>
<member name="M:IHaveAviationCode.Dispose" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="126">
<summary>
Finalizes an instance of the <see cref="T:IHaveAviationCode"/> class.
</summary>
</member>
<member name="M:IHaveAviationCode.GetAviationCode" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="131">
<summary>
Gets the aviation code.
</summary>
<returns>aviationCode by classes that uses this interface.</returns>
</member>
<member name="M:IHaveAviationCode.AreYou(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="137">
<summary>
Check if the code is equal to any of the IHaveAviationCode identifiers.
</summary>
<param name="code">The code.</param>
<returns>true or false based on classes that use this interface.</returns>
</member>
<member name="M:IHaveAviationCode.GetName" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="144">
<summary>
Gets the name.
</summary>
<returns>name by classes that use this interface.</returns>
</member>
<member name="T:Carrier" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="151">
<summary>
Carrier represents airlines.
It has flights.
</summary>
<seealso cref="T:IHaveAviationCode"/>
</member>
<member name="M:Carrier.#ctor(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;,std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="161">
<summary>
Initializes a new instance of the <see cref="T:Carrier"/> class.
</summary>
<param name="aviationCode">The aviation code.</param>
<param name="name">The name.</param>
</member>
<member name="M:Carrier.#ctor(Carrier!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="168">
<summary>
Copies an instance of the <see cref="T:Carrier"/> class.
</summary>
<param name="c">the Carrier we want to copy.</param>
</member>
<member name="M:Carrier.GetName" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="174">
<summary>
Gets the name of the carrier.
</summary>
<returns>
aName
</returns>
</member>
<member name="M:Carrier.GetAviationCode" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="182">
<summary>
Gets the aviation code.
</summary>
<returns>
aAviationCode
</returns>
</member>
<member name="M:Carrier.AreYou(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="190">
<summary>
Check whether the code ID matches the carrier aviationCode or the Name.
</summary>
<param name="code">The code.</param>
<returns>
true if matched and false if unmatched.
</returns>
</member>
<member name="T:Itinerary" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="200">
<summary>
Itinerary is the base class for MultiFlights and Flight.
Itinerary represents a air trip.
It could have a single flight or many flights.
But in common, a trip will have travel time, and a price.
</summary>
</member>
<member name="M:Itinerary.#ctor(Airport*,Airport*,Time,Time)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="208">
<summary>
The main constructor for the Itinerary class
</summary>
<param name="origin">The origin.</param>
<param name="destination">The destination.</param>
<param name="departureTime">The departure time.</param>
<param name="arrivalTime">The arrival time.</param>
</member>
<member name="M:Itinerary.#ctor(Itinerary!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="218">
<summary>
Copies instance of the <see cref="T:Itinerary"/> class.
</summary>
<param name="i">Itinerary i needed to be copied.</param>
</member>
<member name="M:Itinerary.#ctor(Itinerary!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="225">
<summary>
Initializes a new instance of the <see cref="T:Itinerary"/> class based on pointer to another <see cref="T:Itinerary"/> object.
</summary>
<param name="i">The pointer to another Itinerary class.</param>
</member>
<member name="M:Itinerary.GetPrice(FlightClass)" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="231">
<summary>
Gets the price.
</summary>
<param name="rank">The rank.</param>
<returns>
0, but will be overriden by its child classes: MultiFlights and Flight
</returns>
</member>
<member name="M:Itinerary.GetTravelTime" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="240">
<summary>
Gets the travel time.
</summary>
<returns>
00:00, but will be overriden by its child classes: MultiFlights and Flight
</returns>
</member>
<member name="M:Itinerary.GetDepartureTime" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="248">
<summary>
Gets the departure time of the entire Itinerary.
</summary>
<returns>
the Departure time
</returns>
</member>
<member name="M:Itinerary.GetArrivalTime" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="256">
<summary>
Gets the arrival time of the entire Itinerary.
</summary>
<returns>
the Arrival Time
</returns>
</member>
<member name="M:Itinerary.GetOrigin" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="264">
<summary>
Gets the pointer to the origin.
</summary>
<returns>
apOrigin
</returns>
</member>
<member name="M:Itinerary.GetDestination" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="272">
<summary>
Gets the destination.
</summary>
<returns>apDestination.</returns>
</member>
<member name="M:Itinerary.SetOrigin(Airport*)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="278">
<summary>
Sets the origin.
</summary>
<param name="origin">The origin.</param>
</member>
<member name="M:Itinerary.SetDestination(Airport*)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="284">
<summary>
Sets the destination.
</summary>
<param name="destination">The destination.</param>
</member>
<member name="M:Itinerary.SetArrivalTime(Time)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="290">
<summary>
Sets the arrival time.
</summary>
<param name="t">The time.</param>
</member>
<member name="M:Itinerary.DisplayDepartureAndArrivalTime" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="295">
<summary>
Displays the departure and arrival time, in the form of "00:00 - 00:00".
</summary>
<returns>the string of departure and arrival time.</returns>
</member>
<member name="M:Itinerary.DisplayPrice(FlightClass,System.Int32)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="301">
<summary>
Displays the price of an itinerary.
</summary>
<param name="rank">The Flight rank.</param>
<param name="numberPassengers">The number of passengers.</param>
<returns>
a string converted from the price of the Itinerary.
</returns>
</member>
<member name="M:Itinerary.DisplayDepartureAndArrivalAirport" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="311">
<summary>
Displays the departure and arrival airport, in the form "A - B".
</summary>
<returns>
a string that shows the aviationCode of the departure airport and the arrival airport
</returns>
</member>
<member name="T:Flight" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="330">
<summary>
Flight class represent flights in real world.
A flight is an itinerary, having origin, destination, planned departure time and arrvial time.
</summary>
<seealso cref="T:Itinerary"/>
<seealso cref="T:IHaveAviationCode"/>
</member>
<member name="M:Flight.#ctor(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;,Airport*,Airport*,Carrier*,Time,Time,System.Double,System.Double)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="342">
<summary>
the main constructor for the Flight class
</summary>
<param name="aviationCode">The aviation code.</param>
<param name="origin">The origin.</param>
<param name="destination">The destination.</param>
<param name="carrier">The carrier.</param>
<param name="departureTime">The departure time.</param>
<param name="arrivalTime">The arrival time.</param>
<param name="bussinessPrice">The bussiness price of this flight.</param>
<param name="economyPrice">The economy price of this flight.</param>
</member>
<member name="M:Flight.#ctor(Flight!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="355">
<summary>
Copies the instance of the <see cref="T:Flight"/> class.
</summary>
<param name="flight">The flight.</param>
</member>
<member name="M:Flight.GetTravelTime" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="361">
<summary>
Gets the travel time.
</summary>
<returns>
the duration from to departure time to arrival time
</returns>
</member>
<member name="M:Flight.GetPrice(FlightClass)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="369">
<summary>
Gets the price based on the Flight Class.
</summary>
<param name="rank">The flight rank.</param>
<returns>
0, but will be overriden by its child classes: MultiFlights and Flight
</returns>
</member>
<member name="M:Flight.GetCarrier" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="378">
<summary>
Gets the pointer to the carrier.
</summary>
<returns>
its own carrier
</returns>
</member>
<member name="M:Flight.GetAviationCode" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="386">
<summary>
Gets the aviation code.
</summary>
<returns>the aviationCode of the flight.</returns>
</member>
<member name="M:Flight.AreYou(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="392">
<summary>
Ares you.
</summary>
<param name="code">The code.</param>
<returns>true if the code matches any of the flight identifiers, false otherwise..</returns>
</member>
<member name="M:Flight.GetName" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="399">
<summary>
Gets the name of the flight.
</summary>
<returns>
"Flight CODE from A to B"
</returns>
</member>
<member name="M:Flight.Dispose" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="406">
<summary>
Finalizes an instance of the <see cref="T:Flight"/> class.
</summary>
</member>
<member name="T:FlightInventory" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="412">
<summary>
FlightInventory is the class responsible for managing a list of Flight
</summary>
</member>
<member name="M:FlightInventory.#ctor" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="419">
<summary>
The constructor for Flight Inventory
</summary>
</member>
<member name="M:FlightInventory.#ctor(FlightInventory!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="424">
<summary>
Copies instance of the <see cref="T:FlightInventory"/> class.
</summary>
<param name="fi">The flight inventory we want to copy.</param>
</member>
<member name="M:FlightInventory.AddFlight(Flight*)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="430">
<summary>
Adds the flight.
</summary>
<param name="f">The f.</param>
</member>
<member name="M:FlightInventory.RemoveFlight(Flight*)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="436">
<summary>
Removes the flight.
</summary>
<param name="f">The f.</param>
</member>
<member name="M:FlightInventory.NumberOfFlights" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="442">
<summary>
Numbers the of flights.
</summary>
<returns>
size of the flight vector
</returns>
</member>
<member name="M:FlightInventory.LocateFlightByCode(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="450">
<summary>
Locates the flight by code.
</summary>
<param name="code">The code.</param>
<returns>pointer to a flight if the code matches, otherwise returns nullptr.</returns>
</member>
<member name="M:FlightInventory.GetPtrFlightList" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="457">
<summary>
Gets the pointer to the flight list.
</summary>
<returns>
pointer to the flight list.
</returns>
</member>
<member name="T:Airport" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="466">
<summary>
Airport class represents airports in real world.
They are located in city, having its own aviationCode and name.
They contain Departure Flights and Arrival Flights.
</summary>
<seealso cref="T:IHaveAviationCode"/>
</member>
<member name="M:Airport.#ctor(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;,std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;,std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="480">
<summary>
the main constructor for class Airport
</summary>
<param name="aviationCode">The aviation code.</param>
<param name="cityName">Name of the city.</param>
<param name="name">The name.</param>
</member>
<member name="M:Airport.#ctor(Airport!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="488">
<summary>
the copy constructor for class Airport
</summary>
<param name="airport">The airport.</param>
</member>
<member name="M:Airport.GetName" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="494">
<summary>
A getter for the name field of Airport
</summary>
<returns>
aName string field
</returns>
</member>
<member name="M:Airport.GetAviationCode" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="502">
<summary>
Gets the AviationCode
</summary>
<returns>
aAviationCode string field
</returns>
</member>
<member name="M:Airport.AreYou(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="510">
<summary>
check if the string matches the aAviationCode or the aCityName or the aName field
</summary>
<param name="ID">the ID string</param>
<return>
aAviationCode string field
</return>
<value>
true if ID matches one of them
false if ID does not match any of them
</value>
</member>
<member name="M:Airport.GetCityName" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="523">
<summary>
Gets the city name where the airport is located
</summary>
<returns>
aCityName string field
</returns>
</member>
<member name="M:Airport.GetDepartureFlightInventory" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="531">
<summary>
Gets the pointer departure flight inventory.
</summary>
<returns>the pointer to the arrival flight inventory</returns>
</member>
<member name="M:Airport.GetArrivalFlightInventory" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="537">
<summary>
Gets the pointer to the arrival flight inventory.
</summary>
<returns>
the pointer to the arrival flight inventory.
</returns>
</member>
<member name="T:AirportInventory" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="546">
<summary>
AirportInventory is responsible for managing a list of airports.
</summary>
</member>
<member name="M:AirportInventory.#ctor" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="553">
<summary>
Initializes a new instance of the <see cref="T:AirportInventory"/> class.
</summary>
</member>
<member name="M:AirportInventory.#ctor(AirportInventory!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="558">
<summary>
Initializes a new instance of the <see cref="T:AirportInventory"/> class.
</summary>
<param name="AI">The airport inventory we want to copy.</param>
</member>
<member name="M:AirportInventory.AddAirport(Airport*)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="564">
<summary>
Adds the airport.
</summary>
<param name="pAirport">pointer to the airport we want to add</param>
</member>
<member name="M:AirportInventory.RemoveAirport(Airport*)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="570">
<summary>
Removes the airport from the Inventory.
</summary>
<param name="pAirport">The p airport.</param>
</member>
<member name="M:AirportInventory.NumberOfAirports" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="576">
<summary>
Gets number the of airports.
</summary>
<returns>the number of airports of the inventory.</returns>
</member>
<member name="M:AirportInventory.GetPtrAirportList" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="582">
<summary>
Gets the pointer to the airport list.
</summary>
<returns>pointer to the airport list.</returns>
</member>
<member name="M:AirportInventory.LocateAirportByCode(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="588">
<summary>
Locates the airport by code.
</summary>
<param name="code">The code of the map element we want to search for.</param>
<returns>
null if no airport has the code or name or city name matching the code or the pointer
to the airport if we successfully locate the airport
</returns>
</member>
<member name="T:CarrierInventory" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="599">
<summary>
CarrierInventory is responsible for managing a list of carriers.
</summary>
</member>
<member name="M:CarrierInventory.#ctor" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="606">
<summary>
Initializes a new instance of the <see cref="T:CarrierInventory"/> class.
</summary>
</member>
<member name="M:CarrierInventory.#ctor(CarrierInventory!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="611">
<summary>
Copy the instance of the <see cref="T:CarrierInventory"/> class.
</summary>
<param name="CI">The carrier inventory we want to copy from.</param>
</member>
<member name="M:CarrierInventory.AddCarrier(Carrier*)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="617">
<summary>
Adds the carrier.
</summary>
<param name="c">The c.</param>
</member>
<member name="M:CarrierInventory.RemoveCarrier(Carrier*)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="623">
<summary>
Removes the carrier.
</summary>
<param name="c">The c.</param>
</member>
<member name="M:CarrierInventory.NumberOfCarriers" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="629">
<summary>
Numbers the of carriers.
</summary>
<returns>
size of the aCarrierList
</returns>
</member>
<member name="M:CarrierInventory.GetPtrCarrierList" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="637">
<summary>
Gets the pointer to the carrier list.
</summary>
<returns>
address of the carrier list
</returns>
</member>
<member name="M:CarrierInventory.LocateCarrierByCode(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="645">
<summary>
Locates the carrier by code.
</summary>
<param name="code">The code.</param>
<returns>
null if code does not match and pointer to the carrier if it matches.
</returns>
</member>
<member name="T:MultiFlights" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="655">
<summary>
MultiFLights deals with all trips that contain a series of flights.
</summary>
<seealso cref="T:Itinerary"/>
</member>
<member name="M:MultiFlights.#ctor(Flight*)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="664">
<summary>
Initializes a new instance of the <see cref="T:MultiFlights"/> class.
</summary>
<param name="flight">The flight.</param>
</member>
<member name="M:MultiFlights.#ctor(MultiFlights!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="670">
<summary>
Initializes a new instance of the <see cref="T:MultiFlights"/> class.
</summary>
<param name="multiFlights">The multi flights.</param>
</member>
<member name="M:MultiFlights.GetTravelTime" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="676">
<summary>
Gets the travel time.
</summary>
<returns>
the total travel time.
</returns>
</member>
<member name="M:MultiFlights.GetPrice(FlightClass)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="684">
<summary>
Gets the price.
</summary>
<param name="rank">The rank.</param>
<returns>
the total price in all flights.
</returns>
</member>
<member name="M:MultiFlights.AddFlight(Flight*)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="693">
<summary>
Adds the flight to aFlightInventory.
</summary>
<param name="f">The pointer to a flight.</param>
</member>
<member name="M:MultiFlights.CheckMultiCarriers" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="699">
<summary>
Checks whether there is only one carrier responsible for all flights.
</summary>
<returns>
true if there is only one carrier operating in all flights, false otherwise.
</returns>
</member>
<member name="M:MultiFlights.DisplayCarriers" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="707">
<summary>
Displays all carriers.
</summary>
<returns>
the string that have the name of all the carriers operating in this MultiFlights.
</returns>
</member>
<member name="M:MultiFlights.DisplayTransitList" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="715">
<summary>
Displays the transit list.
</summary>
<returns>
the string that have aviationCode of all the airport this MultiFlights stops over at.
</returns>
</member>
<member name="M:MultiFlights.GetTransitInventory" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="723">
<summary>
Gets the transit inventory.
</summary>
<returns>
the address of this aTransitInventory.
</returns>
</member>
<member name="M:MultiFlights.GetFlightInventory" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="731">
<summary>
Gets the flight inventory.
</summary>
<returns>
the address of this aFlightInventory.
</returns>
</member>
<member name="M:MultiFlights.GetTransitTime(System.Int32)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="739">
<summary>
Gets the transit time.
</summary>
<param name="i">index for the transit airport we want to get the time.</param>
<returns>the transit duration for a specific stop.</returns>
</member>
<member name="M:MultiFlights.DisplayNumberOfStops" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="746">
<summary>
Gets the number of stops.
</summary>
<returns>print out the number of stops.</returns>
</member>
<member name="T:UserPreference" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="753">
<summary>
 
</summary>
</member>
<member name="F:UserPreference.aNumberOfPassengers" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="758">
<summary>
The number of passengers
</summary>
</member>
<member name="M:UserPreference.Reset" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="768">
<summary>
Resets this instance.
</summary>
</member>
<member name="M:UserPreference.#ctor" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="772">
<summary>
Initializes a new instance of the <see cref="T:UserPreference"/> struct.
</summary>
</member>
<member name="M:UserPreference.GetNumberOfPassengers" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="777">
<summary>
Gets the number of passengers.
</summary>
<returns>return the number of passengers travelling with this user.</returns>
</member>
<member name="M:UserPreference.GetMaxPrice" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="782">
<summary>
Gets the maximum price.
</summary>
<returns>return the maximum price that the user is willing to pay.</returns>
</member>
<member name="M:UserPreference.GetMaxTime" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="787">
<summary>
Gets the maximum time.
</summary>
<returns>returns the maximum time that the user is willing to spend on their trip.</returns>
</member>
<member name="M:UserPreference.GetMaxTransit" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="792">
<summary>
Gets the maximum transit.
</summary>
<returns>returns the maximum number of stops the user wants.</returns>
</member>
<member name="M:UserPreference.GetFlightClass" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="797">
<summary>
Gets the flight class.
</summary>
<returns>returns the flight rank (ECONOMY, BUSINESS) the user chooses.</returns>
</member>
<member name="M:UserPreference.GetSortCriteria" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="802">
<summary>
Gets the sort criteria.
</summary>
<returns>the sorting criteria.</returns>
</member>
<member name="M:UserPreference.SetNumberOfPassengers(System.Int32)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="807">
<summary>
Sets the number of passengers.
</summary>
<param name="numberOfPassengers">The number of passengers.</param>
</member>
<member name="M:UserPreference.SetMaxPrice(System.Int32)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="812">
<summary>
Sets the maximum price.
</summary>
<param name="maxPrice">The maximum price.</param>
</member>
<member name="M:UserPreference.SetMaxTime(Time)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="817">
<summary>
Sets the maximum time.
</summary>
<param name="maxTime">The maximum time.</param>
</member>
<member name="M:UserPreference.SetMaxTransit(System.Int32)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="822">
<summary>
Sets the maximum transit.
</summary>
<param name="maxTransit">The maximum transit.</param>
</member>
<member name="M:UserPreference.SetFlightClass(FlightClass)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="827">
<summary>
Sets the flight class.
</summary>
<param name="flightClass">The flight class.</param>
</member>
<member name="M:UserPreference.SetSortCriteria(SortCriteria)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="832">
<summary>
Sets the sort criteria.
</summary>
<param name="SortCriteria">The sort criteria.</param>
</member>
<member name="T:User" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="839">
<summary>
User contains the information of user who uses this app.
</summary>
</member>
<member name="M:User.#ctor(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;,std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="847">
<summary>
Initializes a new instance of the <see cref="T:User"/> class.
</summary>
<param name="ID">The identifier.</param>
<param name="password">The password.</param>
</member>
<member name="M:User.AddSearchHistory(IHaveAviationCode*)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="854">
<summary>
Adds the search history.
</summary>
<param name="i">The i.</param>
</member>
<member name="M:User.ClearSearchHistory" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="859">
<summary>
Clears the search history.
</summary>
</member>
<member name="M:User.GetID" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="863">
<summary>
Gets the identifier.
</summary>
<returns>get user ID</returns>
</member>
<member name="M:User.GetPassword" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="868">
<summary>
Gets the password.
</summary>
<returns>get user password.</returns>
</member>
<member name="M:User.GetPtrSearchHistory" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="873">
<summary>
Gets the PTR search history.
</summary>
<returns>get pointer to the search history.</returns>
</member>
<member name="M:User.IsAdmin" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="878">
<summary>
Determines whether this instance is admin.
</summary>
<returns>
  <c>true</c> if this instance is admin; otherwise, <c>false</c>.
</returns>
</member>
<member name="M:User.SetPassword(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="885">
<summary>
Sets the password.
</summary>
<param name="newPassword">The new password.</param>
</member>
<member name="M:User.GetSearchPreference" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="890">
<summary>
Gets the search preference.
</summary>
<returns>the search preference of the user</returns>
</member>
<member name="T:StandardUser" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="897">
<summary>
StandardUser is the ordinary user of this app, different from the admin.
</summary>
<seealso cref="T:User"/>
</member>
<member name="M:StandardUser.#ctor(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;,std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="903">
<summary>
Initializes a new instance of the <see cref="T:StandardUser"/> class.
</summary>
<param name="ID">The identifier.</param>
<param name="password">The password.</param>
</member>
<member name="M:StandardUser.IsAdmin" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="909">
<summary>
Determines whether this instance is admin.
</summary>
<returns>
  <c>true</c> if this instance is admin; otherwise, <c>false</c>.
</returns>
</member>
<member name="T:Admin" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="918">
<summary>
Admin user is the admin of this app.
</summary>
<seealso cref="T:User"/>
</member>
<member name="M:Admin.#ctor(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;,std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="924">
<summary>
Initializes a new instance of the <see cref="T:Admin"/> class.
</summary>
<param name="ID">The identifier.</param>
<param name="password">The password.</param>
</member>
<member name="M:Admin.IsAdmin" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="930">
<summary>
Determines whether this instance is admin.
</summary>
<returns>
  <c>true</c> if this instance is admin; otherwise, <c>false</c>.
</returns>
</member>
<member name="T:Factory" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="939">
<summary>
The factory class is responsible for creating the object for this application.
This is where the factory design pattern is applied.
</summary>
</member>
<member name="M:Factory.CreateMapElement(std.vector&lt;std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;,std.allocator&lt;std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;&gt;&gt;,AirportInventory*,CarrierInventory*,FlightInventory*)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="945">
<summary>
Creates the map element, using the Factory design pattern.
</summary>
<param name="stringList">The string list.</param>
<param name="AI">The pointer to the Airport Inventory.</param>
<param name="CI">The pointer to the Carrier Inventory.</param>
<param name="FI">The pointer to the FlightInventory.</param>
</member>
<member name="M:Factory.CreateUser(std.vector&lt;std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;,std.allocator&lt;std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;&gt;&gt;)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="954">
<summary>
Creates the user.
</summary>
<param name="stringList">The string list.</param>
<returns>the pointer to user newly created.</returns>
</member>
<member name="T:UserControlSingleton" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="962">
<summary>
User control is responsible for the sign-in, sign-out and registration of the users to this application.
</summary>
</member>
<member name="M:UserControlSingleton.IsUsernameTaken(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="975">
<summary>
Determines whether [is username taken] [the specified new username].
</summary>
<param name="newUsername">The new username.</param>
<returns>
  <c>true</c> if [is username taken] [the specified new username]; otherwise, <c>false</c>.
</returns>
</member>
<member name="M:UserControlSingleton.AddUser(User*)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="983">
<summary>
Adds the user.
</summary>
<param name="newUser">The new user.</param>
</member>
<member name="M:UserControlSingleton.GetCurrentUser(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;,std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="988">
<summary>
Gets the current user.
</summary>
<param name="userName">Name of the user.</param>
<param name="password">The password.</param>
<returns>pointer to current user.</returns>
</member>
<member name="M:UserControlSingleton.Instance" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="995">
<summary>
Instances this instance.
</summary>
<returns>pointer to the usercontrol object.</returns>
</member>
<member name="M:UserControlSingleton.LoadData(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="1000">
<summary>
Loads the data.
</summary>
<param name="filename">The filename.</param>
</member>
<member name="M:UserControlSingleton.SaveData(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="1005">
<summary>
Saves the data.
</summary>
<param name="filename">The filename.</param>
</member>
<member name="M:UserControlSingleton.Dispose" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="1010">
<summary>
Finalizes an instance of the <see cref="T:UserControlSingleton"/> class.
</summary>
</member>
<member name="T:MapSingleton" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="1016">
<summary>
MapSingleton is the representation of Map in the app.
</summary>
</member>
<member name="M:MapSingleton.Instance" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="1029">
<summary>
Instances this instance.
</summary>
<returns>
A new MapSingleton Object if there has not been any MapSingleton object created before.
</returns>
</member>
<member name="M:MapSingleton.Organize" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="1036">
<summary>
Organize all the map element in the right order.
</summary>
</member>
<member name="M:MapSingleton.GetFlightInventory" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="1041">
<summary>
Gets the pointer to the flight inventory.
</summary>
<returns>
the pointer to the flight inventory
</returns>
</member>
<member name="M:MapSingleton.GetAirportInventory" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="1049">
<summary>
Gets the pointer to the airport inventory.
</summary>
<returns>
the pointer to the airport inventory
</returns>
</member>
<member name="M:MapSingleton.LoadData(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="1057">
<summary>
Loads the data.
</summary>
<param name="filename">The filename.</param>
</member>
<member name="T:Search" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="1066">
<summary>
Search is responsible for finding the best flights.
</summary>
</member>
<member name="M:Search.Execute(MapSingleton*,Airport*,Airport*,UserPreference*,System.Int32*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="1071">
<summary>
Search for the best trips.
</summary>
<param name="map">The pointer to the map.</param>
<param name="origin">The pointer to the origin airport.</param>
<param name="destination">The pointer to the destination airport.</param>
<param name="rank">The flight rank.</param>
<param name="maximumFlights">The maximum flights we want to get.</param>
<returns>
a vector having the best MultiFlights
</returns>
</member>
<member name="M:Search.IsSatisfied(MultiFlights*,UserPreference*)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="1083">
<summary>
Determines whether the specified multi flight is satisfied with the user Preference.
</summary>
<param name="multiFlight">The multi flight.</param>
<param name="p">The p.</param>
<returns>
  <c>true</c> if the specified multi flight is satisfied; otherwise, <c>false</c>.
</returns>
</member>
<member name="T:Sort" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="1094">
<summary>
Sort is responsible for the sorting action in the application.
</summary>
</member>
<member name="M:Sort.SortFlight(std.vector&lt;Flight**,std.allocator&lt;Flight**&gt;&gt;*,SortCriteria,FlightClass)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="1099">
<summary>
Sorts the flight.
</summary>
<param name="flightList">The pointer to flight list.</param>
<param name="sortCriteria">The sort criteria.</param>
<param name="flightClass">The flight class.</param>
<returns>The sorted flights, based on the sort criteria.</returns>
</member>
<member name="M:Sort.SortMostConnectingAirport(std.vector&lt;Flight**,std.allocator&lt;Flight**&gt;&gt;*)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="1108">
<summary>
Sorts the most connecting airport.
</summary>
<param name="ptrFlightList">The PTR flight list.</param>
<returns>a vector of pair matching the airport with the number of its direct-connected airports.</returns>
</member>
<member name="T:Compare" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="1116">
<summary>
Compare struct is responsible for determining the way to compare two Itinerary objects.
</summary>
</member>
<member name="M:Compare.#ctor(FlightClass,SortCriteria)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="1124">
<summary>
Initializes a new instance of the <see cref="T:Compare"/> struct.
</summary>
<param name="flightClass">The flight class.</param>
<param name="sortCriteria">The sort criteria.</param>
</member>
<member name="M:Compare.op_FunctionCall(Itinerary*,Itinerary*)" decl="true" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsearchapi.h" line="1131">
<summary>
The operator of this class gives comparison of the two itinerary a and b.
This is used by search and sort object.
</summary>
<param name="a">first itineray.</param>
<param name="b">second itineary.</param>
<returns>the </returns>
</member>
<member name="T:GUI1.FlightsDetailForm" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsdetailform.h" line="17">
<summary>
Summary for FlightsDetailForm
</summary>
</member>
<member name="M:GUI1.FlightsDetailForm.Dispose" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsdetailform.h" line="33">
<summary>
Clean up any resources being used.
</summary>
</member>
<member name="F:GUI1.FlightsDetailForm.components" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsdetailform.h" line="46">
<summary>
Required designer variable.
</summary>
</member>
<member name="M:GUI1.FlightsDetailForm.InitializeComponent" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\flightsdetailform.h" line="52">
<summary>
Required method for Designer support - do not modify
the contents of this method with the code editor.
</summary>
</member>
<member name="T:GUI1.SearchPreferenceForm" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\searchpreferenceform.h" line="12">
<summary>
Summary for SearchPreferenceForm
</summary>
</member>
<member name="M:GUI1.SearchPreferenceForm.Dispose" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\searchpreferenceform.h" line="29">
<summary>
Clean up any resources being used.
</summary>
</member>
<member name="F:GUI1.SearchPreferenceForm.components" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\searchpreferenceform.h" line="64">
<summary>
Required designer variable.
</summary>
</member>
<member name="M:GUI1.SearchPreferenceForm.InitializeComponent" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\searchpreferenceform.h" line="70">
<summary>
Required method for Designer support - do not modify
the contents of this method with the code editor.
</summary>
</member>
<member name="T:GUI1.ExploreForm" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\exploreform.h" line="14">
<summary>
Summary for ExploreForm
</summary>
</member>
<member name="M:GUI1.ExploreForm.Dispose" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\exploreform.h" line="31">
<summary>
Clean up any resources being used.
</summary>
</member>
<member name="F:GUI1.ExploreForm.components" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\exploreform.h" line="66">
<summary>
Required designer variable.
</summary>
</member>
<member name="M:GUI1.ExploreForm.InitializeComponent" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\exploreform.h" line="72">
<summary>
Required method for Designer support - do not modify
the contents of this method with the code editor.
</summary>
</member>
<member name="T:GUI1.SearchHistoryForm" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\searchhistoryform.h" line="12">
<summary>
Summary for SearchHistoryForm
</summary>
</member>
<member name="M:GUI1.SearchHistoryForm.Dispose" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\searchhistoryform.h" line="28">
<summary>
Clean up any resources being used.
</summary>
</member>
<member name="F:GUI1.SearchHistoryForm.components" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\searchhistoryform.h" line="44">
<summary>
Required designer variable.
</summary>
</member>
<member name="M:GUI1.SearchHistoryForm.InitializeComponent" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\searchhistoryform.h" line="50">
<summary>
Required method for Designer support - do not modify
the contents of this method with the code editor.
</summary>
</member>
<member name="T:GUI1.main_form" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\main_form.h" line="57">
<summary>
Summary for main_form
</summary>
</member>
<member name="M:GUI1.main_form.Dispose" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\main_form.h" line="78">
<summary>
Clean up any resources being used.
</summary>
</member>
<member name="F:GUI1.main_form.components" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\main_form.h" line="127">
<summary>
Required designer variable.
</summary>
</member>
<member name="M:GUI1.main_form.InitializeComponent" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\main_form.h" line="133">
<summary>
Required method for Designer support - do not modify
the contents of this method with the code editor.
</summary>
</member>
<member name="T:GUI1.LoginForm" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\loginform.h" line="15">
<summary>
Summary for LoginForm
</summary>
</member>
<member name="M:GUI1.LoginForm.Dispose" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\loginform.h" line="33">
<summary>
Clean up any resources being used.
</summary>
</member>
<member name="F:GUI1.LoginForm.components" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\loginform.h" line="75">
<summary>
Required designer variable.
</summary>
</member>
<member name="M:GUI1.LoginForm.InitializeComponent" decl="false" source="e:\y1\oop\semesterproject\guiver6.2-namechange - copy\gui1\gui1\loginform.h" line="81">
<summary>
Required method for Designer support - do not modify
the contents of this method with the code editor.
</summary>
</member>
</members>
</doc>