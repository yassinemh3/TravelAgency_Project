#include "flightbooking.h"

FlightBooking::FlightBooking(string id,double price,string fromDate,string toDate,string fromDestination,double fromLat,double fromLong,string toDestination,double toLat,double toLong,string airline)
    :Booking(id,price,fromDate,toDate),fromDestination(fromDestination),toDestination(toDestination),airline(airline),fromLat(fromLat),fromLong(fromLong),toLat(toLat),toLong(toLong)

{

}

string FlightBooking::showDetails()
{
    return "Flugbuchung von "+fromDestination+" nach "+toDestination+" am "+fromDate+" bis "+toDate+" .Preis: "+to_string(getPrice())+" Euro";
}

string FlightBooking::getID() const
{
    return this->id;
}

double FlightBooking::getPrice() const
{
    return this->price;
}

string FlightBooking::getfromDate() const
{
    return fromDate;
}

string FlightBooking::gettoDate() const
{
    return toDate;
}

string FlightBooking::getfromDestination() const
{
    return fromDestination;
}

string FlightBooking::gettoDestination() const
{
    return toDestination;
}

string FlightBooking::getAirline() const
{
    return airline;
}
