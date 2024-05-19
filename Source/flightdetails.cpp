#include "flightdetails.h"
#include "ui_flightdetails.h"
#include <QString>
#include <QDate>


flightDetails::flightDetails(QWidget *parent,FlightBooking* flight) :
    QMainWindow(parent),
    ui(new Ui::flightDetails),flight(flight)
{
    ui->setupUi(this);
    // Set the text of lineEdit with the flight ID
    QString id = QString::fromStdString(flight->getId());
    ui->lineEdit->setText(id);

    // Set the value of doubleSpinBox with the flight price
    double price = flight->getPrice();
    ui->doubleSpinBox->setValue(price);

    // Set the date in dateEdit with the flight fromDate
    QString qdate = QString::fromStdString(flight->getfromDate());
    QDate date = QDate::fromString(qdate, "yyyyMMdd"); // Adjust the format as needed
    ui->dateEdit->setDate(date);
    if (date.isValid()) {
        ui->dateEdit->setDate(date);
    } else {
        qDebug() << "Invalid date format: " << qdate;
    }

    QString qdate2 = QString::fromStdString(flight->gettoDate());
    QDate date2 = QDate::fromString(qdate2,"yyyyMMdd"); // Adjust the format as needed
    ui->dateEdit_2->setDate(date2);

    QString fromDes = QString::fromStdString(flight->getfromDestination());
    ui->lineEdit_2->setText(fromDes);

    QString toDes = QString::fromStdString(flight->gettoDestination());
    ui->lineEdit_3->setText(toDes);

    QString airline = QString::fromStdString(flight->getAirline());
    ui->lineEdit_4->setText(airline);

}

flightDetails::~flightDetails()
{
    delete ui;
}


