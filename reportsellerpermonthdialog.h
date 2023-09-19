#ifndef REPORTSELLERPERMONTHDIALOG_H
#define REPORTSELLERPERMONTHDIALOG_H

#include <QDialog>

namespace Ui {
class ReportSellerPerMonthDialog;
}

class ReportSellerPerMonthDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReportSellerPerMonthDialog(QWidget *parent = nullptr);
    ~ReportSellerPerMonthDialog();

private slots:
    void on_pushButtonRun_clicked();

    void on_pushButtonClose_clicked();

private:
    Ui::ReportSellerPerMonthDialog *ui;
};

#endif // REPORTSELLERPERMONTHDIALOG_H
