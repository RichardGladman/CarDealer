#ifndef REPORTCUSTOMERBYYEARDIALOG_H
#define REPORTCUSTOMERBYYEARDIALOG_H

#include <QDialog>

namespace Ui {
class ReportCustomerByYearDialog;
}

class ReportCustomerByYearDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReportCustomerByYearDialog(QWidget *parent = nullptr);
    ~ReportCustomerByYearDialog();

private slots:
    void on_pushButtonRun_clicked();

    void on_pushButtonClose_clicked();

private:
    Ui::ReportCustomerByYearDialog *ui;
};

#endif // REPORTCUSTOMERBYYEARDIALOG_H
