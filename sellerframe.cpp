#include "sellerframe.h"
#include "ui_sellerframe.h"

#include "newsellerdialog.h"

SellerFrame::SellerFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SellerFrame)
{
    ui->setupUi(this);
}

SellerFrame::~SellerFrame()
{
    delete ui;
}

void SellerFrame::on_pushButtonSearch_clicked()
{

}


void SellerFrame::on_pushButtonAdd_clicked()
{
    NewSellerDialog *newSellerDialog = new NewSellerDialog(this);
    newSellerDialog->exec();

    loadData();
}


void SellerFrame::on_pushButtonEdit_clicked()
{

}


void SellerFrame::on_pushButtonDelete_clicked()
{

}

void SellerFrame::loadData()
{

}
