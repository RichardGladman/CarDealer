#ifndef EDITSELLERDIALOG_H
#define EDITSELLERDIALOG_H

#include <QDialog>

namespace Ui {
class EditSellerDialog;
}

class EditSellerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditSellerDialog(QWidget *parent = nullptr);
    ~EditSellerDialog();

private:
    Ui::EditSellerDialog *ui;
};

#endif // EDITSELLERDIALOG_H
