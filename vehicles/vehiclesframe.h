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

    void on_pushButtonDelete_clicked();

    void on_pushButtonView_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButtonSearch_clicked();

private:
    Ui::VehiclesFrame *ui;

    QString searchFor;

    void loadData();
};

#endif // VEHICLESFRAME_H
