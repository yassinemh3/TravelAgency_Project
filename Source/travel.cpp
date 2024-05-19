#include "travel.h"


Travel::Travel(long id,long customerId):id(id),customerId(customerId)
{

}
Travel::~Travel()
{
    for(auto travel:travelBookings){
        delete travel;
    }
    travelBookings.clear();
}

void Travel::addBooking(Booking *booking)
{
    travelBookings.push_back(booking);
}

long Travel::getId() const
{
    return id;
}

long Travel::getCId() const
{
    return customerId;
}

vector<Booking *> Travel::getBooking() const
{
    return travelBookings;
}

string Travel::startDate() const
{
    return travelBookings[0]->getFromDate();
}
