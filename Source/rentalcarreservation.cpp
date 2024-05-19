#include "rentalcarreservation.h"

RentalCarReservation::RentalCarReservation(string id,double price,string fromDate,string toDate,string pickupLocation,double pickLat,double pickLong,string returnLocation,double returnLat,double returnLong,string company)
    :Booking(id,price,fromDate,toDate),pickupLocation(pickupLocation),returnLocation(returnLocation),company(company),pickLat(pickLat),pickLong(pickLong),returnLat(returnLat),returnLong(returnLong)
{

}

string RentalCarReservation::showDetails()
{
    return "Mietwagenreservierung mit " + company + ". Abholung am " + getFromDate() + " in " + pickupLocation + ". Rückgabe am " + getToDate() + " in " + returnLocation + ".Preis: " + to_string(getPrice());
}
