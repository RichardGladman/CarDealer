#ifndef NEWCUSTOMERDIALOG_H
#define NEWCUSTOMERDIALOG_H

#include <QDialog>

namespace Ui {
class NewCustomerDialog;
}

class NewCustomerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewCustomerDialog(QWidget *parent = nullptr);
    ~NewCustomerDialog();

private slots:
    void on_pushButtonSave_clicked();

    void on_pushButtonClose_clicked();

private:
    Ui::NewCustomerDialog *ui;
};

#endif // NEWCUSTOMERDIALOG_H
