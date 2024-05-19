#ifndef SUCHE_H
#define SUCHE_H

#include <QDialog>
#include <travelagency.h>

namespace Ui {
class Suche;
}

class Suche : public QDialog
{
    Q_OBJECT

public:
    explicit Suche(QWidget *parent = nullptr, TravelAgency* travel=nullptr);
    ~Suche();
    long getId() const;

private slots:
    void on_buttonBox_accepted();


private:
    Ui::Suche *ui;
    long CustomerId;
    TravelAgency* travel;
};

#endif // SUCHE_H
