#include "salesframe.h"
#include "ui_salesframe.h"

#include "newsaledialog.h"

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

void SalesFrame::on_pushButtonAdd_clicked()
{
    NewSaleDialog *newSaleDialog = new NewSaleDialog(this);
    newSaleDialog->exec();

    loadData();
}


void SalesFrame::on_pushButtonView_clicked()
{

}

void SalesFrame::loadData()
{

}
