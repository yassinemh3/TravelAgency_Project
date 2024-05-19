#ifndef TRAINTICKET_H
#define TRAINTICKET_H
#include "booking.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
struct Station {
    double latitude;
    double longitude;
    std::string stationName;
};
class Trainticket : public Booking
{
public:

    Trainticket(string id, double price, string fromDate,string toDate, string fromDestination,double fromLat,double fromLong ,string toDestination,double toLat,double toLong, string depatureTime, string arrivalTime);
    ~Trainticket();
    string showDetails() override;
    string getAllStations();
private:
    string fromDestination;
    string toDestination;
    string depatureTime;
    string arrivalTime;
    vector <Station> connectingStations;
    double fromLat;
    double fromLong;
    double toLat;
    double toLong;

};
#endif // TRAINTICKET_H



