#ifndef TRAVEL_H
#define TRAVEL_H
#include<iostream>
#include<vector>
#include<booking.h>
#include <QDate>
using namespace std;

class Travel
{
public:
    Travel(long id,long customerId);
    ~Travel();
    void addBooking(Booking* booking);
    long getId() const ;
    long getCId() const;
    vector<Booking*> getBooking() const;
    string startDate() const;

private:
    long id;
    long customerId;
    vector<Booking*> travelBookings;
};

#endif // TRAVEL_H
