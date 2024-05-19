#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H
#include "booking.h"

class RentalCarReservation: public Booking
{
public:
    RentalCarReservation(string,double,string,string,string,double,double,string,double,double,string);
    string showDetails() override;
private:
    string pickupLocation;
    string returnLocation;
    string company;
    double pickLat;
    double pickLong;
    double returnLat;
    double returnLong;

};

#endif // RENTALCARRESERVATION_H
