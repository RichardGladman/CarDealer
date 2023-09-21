#ifndef REPORTCARDEALERPERYEARDIALOG_H
#define REPORTCARDEALERPERYEARDIALOG_H

#include <QDialog>

namespace Ui {
class ReportCarDealerPerYearDialog;
}

class ReportCarDealerPerYearDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReportCarDealerPerYearDialog(QWidget *parent = nullptr);
    ~ReportCarDealerPerYearDialog();

private slots:
    void on_pushButtonRun_clicked();

    void on_pushButtonClose_clicked();

private:
    Ui::ReportCarDealerPerYearDialog *ui;
};

#endif // REPORTCARDEALERPERYEARDIALOG_H
