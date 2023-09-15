#ifndef CUSTOMERSFRAME_H
#define CUSTOMERSFRAME_H

#include <QFrame>

namespace Ui {
class CustomersFrame;
}

class CustomersFrame : public QFrame
{
    Q_OBJECT

public:
    explicit CustomersFrame(QWidget *parent = nullptr);
    ~CustomersFrame();

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonSearch_clicked();

private:
    Ui::CustomersFrame *ui;
    QString searchFor;

    void loadData();
};

#endif // CUSTOMERSFRAME_H
