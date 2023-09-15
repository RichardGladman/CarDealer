#include "editsellerdialog.h"
#include "ui_editsellerdialog.h"

EditSellerDialog::EditSellerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditSellerDialog)
{
    ui->setupUi(this);
}

EditSellerDialog::~EditSellerDialog()
{
    delete ui;
}
