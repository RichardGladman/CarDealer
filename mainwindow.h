#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_actionSettings_triggered();

    void on_actionAbout_triggered();

    void on_actionAbout_Qt_triggered();

    void on_actionExit_triggered();

    void on_actionVehicles_triggered();

    void on_actionSellers_triggered();

    void on_actionCustomers_triggered();

    void on_actionSell_Vehicle_triggered();

    void on_actionSeller_By_Month_triggered();

    void on_actionSeller_By_Year_triggered();

    void on_actionCustomer_By_Year_triggered();

    void on_actionDealer_By_Year_triggered();

    void on_actionDealer_By_Month_triggered();

    void on_actionPart_Exchanges_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
