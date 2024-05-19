#ifndef TRAVELAGENCYUI_H
#define TRAVELAGENCYUI_H

#include <QMainWindow>
#include "travelagency.h"
#include <QListWidget>
#include <QTableWidget>
namespace Ui {
class travelagencyui;
}

class travelagencyui : public QMainWindow
{
    Q_OBJECT

public:
    explicit travelagencyui(QWidget *parent = nullptr, TravelAgency* agency=nullptr);
    ~travelagencyui();

private slots:
    void on_actionEinlesen_triggered();

    void on_actionSuchen_triggered();

    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

    void on_tableWidget_2_itemDoubleClicked(QTableWidgetItem *item);

private:
    Ui::travelagencyui *ui;
    TravelAgency* agency;
};

#endif // TRAVELAGENCYUI_H
