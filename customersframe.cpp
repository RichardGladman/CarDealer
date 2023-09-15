#include "customersframe.h"
#include "ui_customersframe.h"

#include "newcustomerdialog.h"

CustomersFrame::CustomersFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CustomersFrame)
{
    ui->setupUi(this);
}

CustomersFrame::~CustomersFrame()
{
    delete ui;
}

void CustomersFrame::on_pushButtonAdd_clicked()
{
    NewCustomerDialog *newCustomerDialog = new NewCustomerDialog(this);
    newCustomerDialog->exec();
}

