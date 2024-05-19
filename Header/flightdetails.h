#ifndef FLIGHTDETAILS_H
#define FLIGHTDETAILS_H

#include <QMainWindow>
#include "flightbooking.h"

namespace Ui {
class flightDetails;
}

class flightDetails : public QMainWindow
{
    Q_OBJECT

public:
    explicit flightDetails(QWidget *parent = nullptr,FlightBooking* flight=nullptr);
    ~flightDetails();

private:
    Ui::flightDetails *ui;
    FlightBooking* flight;
};

#endif // FLIGHTDETAILS_H
