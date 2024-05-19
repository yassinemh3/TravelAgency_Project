#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H
#include <booking.h>


class FlightBooking: public Booking
{
public:
    FlightBooking(string,double,string,string,string,double,double,string,double,double,string);
    string showDetails() override;
    string getID() const;
    double getPrice() const;
    string getfromDate() const;
    string gettoDate() const;
    string getfromDestination() const;
    string gettoDestination() const;
    string getAirline() const;


private:
    string fromDestination;
    string toDestination;
    string airline;
    double fromLat;
    double fromLong;
    double toLat;
    double toLong;

};

#endif // FLIGHTBOOKING_H
