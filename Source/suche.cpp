#include "suche.h"
#include "ui_suche.h"
#include<QMessageBox>

Suche::Suche(QWidget *parent,TravelAgency* travel) :
    QDialog(parent),
    ui(new Ui::Suche),CustomerId(0),travel(travel)
{
    ui->setupUi(this);
}

Suche::~Suche()
{
    delete ui;
}

long Suche::getId() const
{
    return CustomerId;
}

void Suche::on_buttonBox_accepted()
{
    CustomerId = ui->spinBox->value();
    if(!travel->findCustomer(CustomerId)){
        QMessageBox::warning(this,"error","No id found");
    }


}

