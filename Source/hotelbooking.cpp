#include "hotelbooking.h"

HotelBooking::HotelBooking(string id,double price,string fromDate,string toDate,string hotel,string town,double Lat,double Long):Booking(id,price,fromDate,toDate),hotel(hotel),town(town),Lat(Lat),Long(Long)
{

}

string HotelBooking::showDetails()
{
    return  "Hotelreservierung  im " + this->hotel + " in " + this->town + " vom " + getFromDate() + " bis zum " + getToDate() + ". Preis: " + to_string(getPrice());
}
