#include "trainticket.h"


Trainticket::Trainticket(string id, double price, string fromDate,string toDate, string fromDestination,double fromLat,double fromLong ,string toDestination,double toLat,double toLong, string depatureTime, string arrivalTime)
    :Booking(id, price, fromDate, toDate), fromDestination(fromDestination), toDestination(toDestination),depatureTime(depatureTime), arrivalTime(arrivalTime), connectingStations(connectingStations),fromLat(fromLat),fromLong(fromLong),toLat(toLat),toLong(toLong)
{

}

Trainticket::~Trainticket(){

}

string Trainticket::showDetails(){

    return "Zugticket von " + fromDestination + " nach " + toDestination + " am " + getFromDate() + " von " + depatureTime + " bis " + arrivalTime + " über " + getAllStations() + ". Preis: " + to_string(getPrice());
}

string Trainticket::getAllStations(){

}

