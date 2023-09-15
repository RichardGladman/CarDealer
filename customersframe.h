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

private:
    Ui::CustomersFrame *ui;
};

#endif // CUSTOMERSFRAME_H
