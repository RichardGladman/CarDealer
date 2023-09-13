#ifndef VEHICLESFRAME_H
#define VEHICLESFRAME_H

#include <QFrame>

namespace Ui {
class VehiclesFrame;
}

class VehiclesFrame : public QFrame
{
    Q_OBJECT

public:
    explicit VehiclesFrame(QWidget *parent = nullptr);
    ~VehiclesFrame();

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonEdit_clicked();

private:
    Ui::VehiclesFrame *ui;

    void loadData();
};

#endif // VEHICLESFRAME_H
