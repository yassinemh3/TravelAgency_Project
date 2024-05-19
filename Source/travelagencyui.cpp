#include "travelagencyui.h"
#include "ui_travelagencyui.h"
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <flightdetails.h>
#include <suche.h>
#include <travelagency.h>
#include <QTableWidget>
#include <hotelbooking.h>
#include <rentalcarreservation.h>
#include <trainticket.h>
#include<QObject>
travelagencyui::travelagencyui(QWidget *parent, TravelAgency* agency) :
    QMainWindow(parent),
    ui(new Ui::travelagencyui),agency(agency)
{
    ui->setupUi(this);
    ui->groupBox->hide();
    ui->groupBox_2->hide();
//    connect(ui->listWidget, &QListWidget::itemDoubleClicked, this, &travelagencyui::on_listItemDoubleClicked);
}

travelagencyui::~travelagencyui()
{
    delete ui;
}

void travelagencyui::on_actionEinlesen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,"Open a File","C://");
    if (!file.isEmpty()) {
        QString result = QString::fromStdString(agency->readFile(file.toStdString()));
        QMessageBox::information(this,"result",result);
    }
    else {
        QMessageBox::warning(this,"error","file not oppen");
    }

}


void travelagencyui::on_actionSuchen_triggered()
{
    Suche* suche= new Suche(this,agency);
    suche->show();
    if(suche->exec()==QDialog::Accepted){
        ui->groupBox->show();
        QString id = QString::number(suche->getId());
        ui->lineEdit->setText(id);
        QString name = QString::fromStdString(agency->findCustomer(suche->getId())->getName());
        ui->lineEdit_2->setText(name);

        // Clear existing items in the tableWidget
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);  // Clear rows

       vector<Travel*> travelList = agency->findCustomer(suche->getId())->getTravelList();

        // Iterate through the travelList and add items to the tableWidget
        for (const Travel* travel : travelList) {
            int rowPosition = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(rowPosition);

            QTableWidgetItem* idItem = new QTableWidgetItem(QString::number(travel->getId()));
            vector<Booking*> bookings = travel->getBooking();
            if (!bookings.empty()) {
                QTableWidgetItem* startDateItem = new QTableWidgetItem(QString::fromStdString(travel->startDate()));
                QTableWidgetItem* endDateItem = new QTableWidgetItem(QString::fromStdString(travel->getBooking().back()->getToDate()));

                ui->tableWidget->setItem(rowPosition, 0, idItem);
                ui->tableWidget->setItem(rowPosition, 1, startDateItem);
                ui->tableWidget->setItem(rowPosition, 2, endDateItem);}
            else {
                // Handle the case where the Booking vector is empty
                qDebug() << "No bookings available for travel with ID: " << travel->getId();
                delete idItem;  // Clean up the allocated QTableWidgetItem
                ui->tableWidget->removeRow(rowPosition);  // Remove the inserted row
            }

//
    }
}

}

void travelagencyui::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    ui->groupBox_2->show();
    QString S = item->text();
    long id = S.toLong();
    ui->lineEdit_3->setText(S);
    ui->tableWidget_2->clearContents();
    ui->tableWidget_2->setRowCount(0);  // Clear rows
    vector<Booking*> bookings = agency->findTravel(id)->getBooking();
    if (!bookings.empty()) {
        for(Booking* booking : bookings){
            int rowPosition = ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(rowPosition);
            QTableWidgetItem* startDateItem = new QTableWidgetItem(QString::fromStdString(booking->getFromDate()));
            QTableWidgetItem* endDateItem = new QTableWidgetItem(QString::fromStdString(booking->getToDate()));
            QTableWidgetItem* Preis = new QTableWidgetItem(QString::number(booking->getPrice()));
            QTableWidgetItem* Typ = new QTableWidgetItem();
            const FlightBooking* flightBooking = dynamic_cast<const FlightBooking*>(booking);
            const HotelBooking* hotel = dynamic_cast<const HotelBooking*>(booking);
            const RentalCarReservation* car = dynamic_cast<const RentalCarReservation*>(booking);
            const Trainticket* train = dynamic_cast<const Trainticket*>(booking);

            if(flightBooking){
                Typ->setIcon(QPixmap(":/icons/plane_723955.png"));
            }
            if(hotel){
                Typ->setIcon(QPixmap(":/icons/hotel_905462.png"));
            }
            if(car){
                Typ->setIcon(QPixmap(":/icons/icons8-auto-64.png"));
            }
            if(train){
                Typ->setIcon(QPixmap(":/icons/train_11116398.png"));
            }
            ui->tableWidget_2->setItem(rowPosition, 0,Typ);
            ui->tableWidget_2->setItem(rowPosition, 1, startDateItem);
            ui->tableWidget_2->setItem(rowPosition, 2, endDateItem);
            ui->tableWidget_2->setItem(rowPosition, 3, Preis);
            QVariant userData;
            userData.setValue(booking);
            ui->tableWidget_2->item(rowPosition, 0)->setData(Qt::UserRole, userData);
        } }

    else {
        // Handle the case where the Booking vector is empty
        qDebug() << "No bookings available for travel with ID: " << S;
    }


}


void travelagencyui::on_tableWidget_2_itemDoubleClicked(QTableWidgetItem *item)
{

    QVariant userData = item->data(Qt::UserRole);
    Booking* theBooking = userData.value<Booking*>();

    if (theBooking) {
        Booking* booking = agency->findBooking(theBooking->getId());

        FlightBooking* flightBooking = dynamic_cast<FlightBooking*>(booking);

        if (flightBooking) {
            // Create and show the booking details window
            flightDetails *detailsWindow = new flightDetails(this,flightBooking);
            detailsWindow->show(); // Use exec() to show the window modally
        }
    } else {
         qDebug() << "theBooking ios null";
    }

}

