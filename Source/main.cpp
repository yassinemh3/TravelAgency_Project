#include "travelagency.h"
#include <iostream>
#include <QApplication>
#include "travelagencyui.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TravelAgency agency;
    travelagencyui w(nullptr,&agency);
    w.show();


    return a.exec();

}
