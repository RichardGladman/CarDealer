#ifndef VIEWCUSTOMERDIALOG_H
#define VIEWCUSTOMERDIALOG_H

#include <QDialog>

namespace Ui {
class ViewCustomerDialog;
}

class ViewCustomerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewCustomerDialog(int id, QWidget *parent = nullptr);
    ~ViewCustomerDialog();

private slots:
    void on_pushButtonClose_clicked();

private:
    Ui::ViewCustomerDialog *ui;

    int id;
};

#endif // VIEWCUSTOMERDIALOG_H
