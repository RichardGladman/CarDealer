#ifndef NEWVEHICLEFRAME_H
#define NEWVEHICLEFRAME_H

#include <QFrame>

namespace Ui {
class NewVehicleFrame;
}

class NewVehicleFrame : public QFrame
{
    Q_OBJECT

public:
    explicit NewVehicleFrame(QWidget *parent = nullptr);
    ~NewVehicleFrame();

private slots:
    void on_pushButtonChoose_clicked();

    void on_pushButtonSave_clicked();

private:
    Ui::NewVehicleFrame *ui;
};

#endif // NEWVEHICLEFRAME_H
