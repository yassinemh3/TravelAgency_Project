#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H
#include "booking.h"

class HotelBooking: public Booking
{
public:
    HotelBooking(string,double,string,string,string,string,double,double);
    string showDetails() override;
private:
    string hotel;
    string town;
    double Lat;
    double Long;

};

#endif // HOTELBOOKING_H
