#ifndef REPORTSELLERPERYEARDIALOG_H
#define REPORTSELLERPERYEARDIALOG_H

#include <QDialog>

namespace Ui {
class ReportSellerPerYearDialog;
}

class ReportSellerPerYearDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReportSellerPerYearDialog(QWidget *parent = nullptr);
    ~ReportSellerPerYearDialog();

private slots:
    void on_pushButtonRun_clicked();

    void on_pushButtonClose_clicked();

private:
    Ui::ReportSellerPerYearDialog *ui;
};

#endif // REPORTSELLERPERYEARDIALOG_H
