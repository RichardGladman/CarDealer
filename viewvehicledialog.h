#ifndef VIEWVEHICLEDIALOG_H
#define VIEWVEHICLEDIALOG_H

#include <QDialog>

namespace Ui {
class ViewVehicleDialog;
}

class ViewVehicleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewVehicleDialog(int vehicleId, QWidget *parent = nullptr);
    ~ViewVehicleDialog();

private slots:
    void on_pushButtonClose_clicked();

private:
    Ui::ViewVehicleDialog *ui;
};

#endif // VIEWVEHICLEDIALOG_H
