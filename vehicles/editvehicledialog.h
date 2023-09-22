#ifndef EDITVEHICLEDIALOG_H
#define EDITVEHICLEDIALOG_H

#include <QDialog>

namespace Ui {
class EditVehicleDialog;
}

class EditVehicleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditVehicleDialog(int vehicleId, QWidget *parent = nullptr);
    ~EditVehicleDialog();

private slots:
    void on_pushButtonSave_clicked();

    void on_pushButtonClose_clicked();

    void on_pushButtonChoose_clicked();

private:
    Ui::EditVehicleDialog *ui;

    int vehicleId;

};

#endif // EDITVEHICLEDIALOG_H
