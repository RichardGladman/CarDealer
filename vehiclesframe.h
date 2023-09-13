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

private:
    Ui::VehiclesFrame *ui;
};

#endif // VEHICLESFRAME_H
