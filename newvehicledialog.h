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

private:
    Ui::NewVehicleDialog *ui;
};

#endif // NEWVEHICLEDIALOG_H
