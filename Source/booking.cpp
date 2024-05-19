#include "booking.h"

Booking::Booking(string id ,double price,string fromDate,string toDate):id{id},price{price},fromDate{fromDate},toDate{toDate}
{

}

string Booking::getId(){
    return this->id;
}

double Booking::getPrice(){
    return this->price;
}

string Booking::getFromDate(){
    return this->fromDate;
}

string Booking::getToDate(){
    return this->toDate;
}

