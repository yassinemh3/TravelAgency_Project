#include "bookingdetails.h"
#include "ui_bookingdetails.h"

BookingDetails::BookingDetails(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BookingDetails)
{
    ui->setupUi(this);
}

BookingDetails::~BookingDetails()
{
    delete ui;
}
