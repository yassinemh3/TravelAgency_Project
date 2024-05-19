#include "travelagency.h"
#include "json.hpp"
using namespace nlohmann;
#include <fstream>
#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"
#include "trainticket.h"


TravelAgency::TravelAgency()
{

}

TravelAgency::~TravelAgency()
{
    // Delete each booking in the vector
    for (auto booking : Bookings) {
        delete booking;
    }
    // Clear the vector after deleting all bookings
    Bookings.clear();
    for(auto travel:allTravels){
        delete travel;
    }
    allTravels.clear();
    for(auto customer:allCustomers){
        delete customer;
    }
    allCustomers.clear();
}
void TravelAgency::print(){
    for(size_t i=0; i<Bookings.size(); i++){
        cout<<Bookings[i]->showDetails();
    }
}
double TravelAgency::calculateTotalCarPrice() const {
    double totalHotelPrice = 0.0;
    for (const auto& booking : Bookings) {
        if (dynamic_cast<RentalCarReservation*>(booking)) {
            totalHotelPrice += booking->getPrice();
        }
    }
    return totalHotelPrice;
}
double TravelAgency::calculateTotalTrainPrice() const {
    double totalHotelPrice = 0.0;
    for (const auto& booking : Bookings) {
        if (dynamic_cast<Trainticket*>(booking)) {
            totalHotelPrice += booking->getPrice();
        }
    }
    return totalHotelPrice;
}
double TravelAgency::calculateTotalHotelPrice() const {
    double totalHotelPrice = 0.0;
    for (const auto& booking : Bookings) {
        if (dynamic_cast<HotelBooking*>(booking)) {
            totalHotelPrice += booking->getPrice();
        }
    }
    return totalHotelPrice;
}
double TravelAgency::calculateTotalFlightPrice() const {
    double totalFlightPrice = 0.0;
    for (const auto& booking : Bookings) {
        if (dynamic_cast<FlightBooking*>(booking)) {
            totalFlightPrice += booking->getPrice();
        }
    }
    return totalFlightPrice;
}
string TravelAgency::readFile(string file){
    ifstream datei(file);
    if(!datei) {
        cerr << "Datei kann nicht geöffnet werden" <<endl;
                exit(-1);
    }
    json j;
    datei >> j;
    int c1=0,c2=0,c3=0,c4=0, Cus=0,T=0;

    for (const auto& element : j) {
        Travel* t = new Travel(element["travelId"],element["customerId"]);
        if(findTravel(t->getId())==nullptr){
            allTravels.push_back(t);
            T++;
        }

        Customer* C = new Customer(element["customerId"],element["customerLastName"],element["customerFirstName"]);
        if(findCustomer(C->getId())==nullptr){
           allCustomers.push_back(C);
           findCustomer(C->getId())->addTravel(t);
           Cus++;
        }
        else{
           findCustomer(C->getId())->addTravel(t);
        }
        if (element["type"] == "Flight") {
            Bookings.push_back(new FlightBooking(
                element["id"],
                element["price"],
                element["fromDate"],
                element["toDate"],
                element["fromDest"],
                element["fromDestLatitude"],
                element["fromDestLongitude"],
                element["toDest"],
                element["toDestLatitude"],
                element["toDestLongitude"],
                element["airline"]
                ));       
            findTravel(t->getId())->addBooking(new FlightBooking(
                element["id"],
                element["price"],
                element["fromDate"],
                element["toDate"],
                element["fromDest"],
                element["fromDestLatitude"],
                element["fromDestLongitude"],
                element["toDest"],
                element["toDestLatitude"],
                element["toDestLongitude"],
                element["airline"]
                ));
            c1++;
        }
        else if (element["type"] == "Hotel") {
            Bookings.push_back(new HotelBooking(
                element["id"],
                element["price"],
                element["fromDate"],
                element["toDate"],
                element["hotel"],
                element["town"],
                element["hotelLatitude"],
                element["hotelLongitude"]
                ));
            findTravel(t->getId())->addBooking(new HotelBooking(
                element["id"],
                element["price"],
                element["fromDate"],
                element["toDate"],
                element["hotel"],
                element["town"],
                element["hotelLatitude"],
                element["hotelLongitude"]
                ));
            c2++;
        } else if (element["type"] == "RentalCar") {
            Bookings.push_back(new RentalCarReservation(
                element["id"],
                element["price"],
                element["fromDate"],
                element["toDate"],
                element["pickupLocation"],
                element["pickupLatitude"],
                element["pickupLongitude"],
                element["returnLocation"],
                element["returnLatitude"],
                element["returnLongitude"],
                element["company"]
                ));
            findTravel(t->getId())->addBooking(new RentalCarReservation(
                element["id"],
                element["price"],
                element["fromDate"],
                element["toDate"],
                element["pickupLocation"],
                element["pickupLatitude"],
                element["pickupLongitude"],
                element["returnLocation"],
                element["returnLatitude"],
                element["returnLongitude"],
                element["company"]
                ));
            c3++;
        } else if (element["type"] == "Train") {
            Bookings.push_back(new Trainticket(
                element["id"],
                element["price"],
                element["fromDate"],
                element["toDate"],
                element["fromStation"],
                element["fromStationLatitude"],
                element["fromStationLongitude"],
                element["toStation"],
                element["toStationLatitude"],
                element["toStationLongitude"],
                element["departureTime"],
                element["arrivalTime"]
                ));
            findTravel(t->getId())->addBooking(new Trainticket(
                element["id"],
                element["price"],
                element["fromDate"],
                element["toDate"],
                element["fromStation"],
                element["fromStationLatitude"],
                element["fromStationLongitude"],
                element["toStation"],
                element["toStationLatitude"],
                element["toStationLongitude"],
                element["departureTime"],
                element["arrivalTime"]
                ));
            c4++;
        }
    }
    string result = "Es wurden "+to_string(c1)+" Flugbuchungen im Wert von e , "+to_string(c2)+" Mietwagenbuchungen im Wert von  , "
           + to_string(c3)+" Hotelreservierungen im Wert von  e und "
                    +to_string(c4) +" Zugbuchungen im Wert von e , angelegt. "+"Es wurden "+to_string(T)+" Reisen und "+to_string(Cus)+" Kunden angelegt. Der Kunde mit der ID 1 hat "
                    +to_string(findCustomer(1)->getTravelList().size())+" Reisen gebucht. Zur Reise mit der ID 17 gehören "+to_string(findTravel(17)->getBooking().size())+" Buchungen.";
    return result;
}


vector<Booking *> TravelAgency::getBookings() const
{
    return Bookings;
}

Booking *TravelAgency::findBooking(string id)
{
    Booking* b=nullptr;
    for(Booking* booking: Bookings){
        if(booking->getId()==id){
            b=booking;
        }
    }
    return b;
}

Travel *TravelAgency::findTravel(long id)
{
    Travel* t=nullptr;
    for(Travel* travel: allTravels)
    {
        if(travel->getId()==id){
            t = travel; }
    }
    return t;
}

Customer *TravelAgency::findCustomer(long id)
{   Customer* C=nullptr;
    for(Customer* customer: allCustomers)
    {
        if(customer->getId()==id){
            C=customer;
        }

    }
    return C;
}


