#ifndef SALESFRAME_H
#define SALESFRAME_H

#include <QFrame>

namespace Ui {
class SalesFrame;
}

class SalesFrame : public QFrame
{
    Q_OBJECT

public:
    explicit SalesFrame(QWidget *parent = nullptr);
    ~SalesFrame();

private:
    Ui::SalesFrame *ui;
};

#endif // SALESFRAME_H
