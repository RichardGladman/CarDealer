#include "salesframe.h"
#include "ui_salesframe.h"

SalesFrame::SalesFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SalesFrame)
{
    ui->setupUi(this);
}

SalesFrame::~SalesFrame()
{
    delete ui;
}
