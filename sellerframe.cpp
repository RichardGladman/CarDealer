#include "sellerframe.h"
#include "ui_sellerframe.h"

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
