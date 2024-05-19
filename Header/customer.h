#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<travel.h>

class Customer
{
public:
    Customer(long id,string lastName,string firstName);
    ~Customer();
    void addTravel(Travel* travel);
    long getId() const;
    vector<Travel*> getTravelList() const;
    string getName() const;

private:
    long id;
    string lastName;
    string firstName;
    vector<Travel*> travelList;

};

#endif // CUSTOMER_H
