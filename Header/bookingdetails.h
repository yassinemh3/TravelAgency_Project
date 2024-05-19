#ifndef BOOKINGDETAILS_H
#define BOOKINGDETAILS_H

#include <QMainWindow>

namespace Ui {
class BookingDetails;
}

class BookingDetails : public QMainWindow
{
    Q_OBJECT

public:
    explicit BookingDetails(QWidget *parent = nullptr);
    ~BookingDetails();

private:
    Ui::BookingDetails *ui;
};

#endif // BOOKINGDETAILS_H
