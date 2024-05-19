#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H
#include <vector>
#include <booking.h>
#include <iostream>
#include <iostream>
#include <cstring> // for std::memcpy
#include <QString>
#include <customer.h>
#include <travel.h>

using namespace std;
class TravelAgency
{
private:
    vector<Booking*> Bookings;
    vector<Customer*> allCustomers;
    vector<Travel*> allTravels;
public:
    TravelAgency();
    ~TravelAgency();
    string readFile(string file);
    void print();
    void addBooking(Booking* booking);
    double calculateTotalFlightPrice() const;
    double calculateTotalCarPrice() const;
    double calculateTotalTrainPrice() const;
    double calculateTotalHotelPrice() const;
    vector<Booking*> getBookings() const;
    Booking* findBooking(string id);
    Travel* findTravel(long id);
    Customer* findCustomer(long id);

};


#endif // TRAVELAGENCY_H
