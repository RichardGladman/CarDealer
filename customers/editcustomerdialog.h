#ifndef EDITCUSTOMERDIALOG_H
#define EDITCUSTOMERDIALOG_H

#include <QDialog>

namespace Ui {
class EditCustomerDialog;
}

class EditCustomerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditCustomerDialog(int id, QWidget *parent = nullptr);
    ~EditCustomerDialog();

private slots:
    void on_pushButtonSave_clicked();

    void on_pushButtonClose_clicked();

private:
    Ui::EditCustomerDialog *ui;
    int id;
};

#endif // EDITCUSTOMERDIALOG_H
