#ifndef REPORTCARDEALERBYMONTHDIALOG_H
#define REPORTCARDEALERBYMONTHDIALOG_H

#include <QDialog>

namespace Ui {
class ReportCarDealerByMonthDialog;
}

class ReportCarDealerByMonthDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReportCarDealerByMonthDialog(QWidget *parent = nullptr);
    ~ReportCarDealerByMonthDialog();

private slots:
    void on_pushButtonRun_clicked();

    void on_pushButtonClose_clicked();

private:
    Ui::ReportCarDealerByMonthDialog *ui;
};

#endif // REPORTCARDEALERBYMONTHDIALOG_H
