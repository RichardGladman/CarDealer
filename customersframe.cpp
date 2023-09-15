#include "customersframe.h"
#include "ui_customersframe.h"

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
