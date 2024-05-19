#ifndef BOOKING_H
#define BOOKING_H
#include<iostream>
using namespace std;
class Booking
{
public:
    Booking(string ,double,string,string);
    virtual ~Booking() = default;
    virtual string showDetails() = 0;
    string getId();
    double getPrice();
    string getFromDate();
    string getToDate();

protected:
    string id;
    double price;
    string fromDate;
    string toDate;

};

#endif // BOOKING_H
