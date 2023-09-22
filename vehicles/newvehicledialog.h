#ifndef NEWVEHICLEDIALOG_H
#define NEWVEHICLEDIALOG_H

#include <QDialog>

namespace Ui {
class NewVehicleDialog;
}

class NewVehicleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewVehicleDialog(QWidget *parent = nullptr);
    ~NewVehicleDialog();

private slots:
    void on_pushButtonSave_clicked();

    void on_pushButtonClose_clicked();

    void on_pushButtonChoose_clicked();

private:
    Ui::NewVehicleDialog *ui;

};

#endif // NEWVEHICLEDIALOG_H
