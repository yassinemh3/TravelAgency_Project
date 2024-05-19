#include "customer.h"

Customer::Customer(long id,string lastName,string firstName):id(id),lastName(lastName),firstName(firstName)
{

}
Customer::~Customer()
{
    for(auto travel:travelList){
        delete travel;
    }
    travelList.clear();
}

void Customer::addTravel(Travel *travel)
{
    travelList.push_back(travel);
}

long Customer::getId() const
{
    return id;
}

vector<Travel *> Customer::getTravelList() const
{
    return travelList;
}

string Customer::getName() const
{
    return lastName +" "+firstName;
}
