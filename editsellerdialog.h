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
    explicit EditSellerDialog(int sellerId, QWidget *parent = nullptr);
    ~EditSellerDialog();

private slots:
    void on_pushButtonSave_clicked();

    void on_pushButtonClose_clicked();

private:
    Ui::EditSellerDialog *ui;
    int sellerId;
};

#endif // EDITSELLERDIALOG_H
