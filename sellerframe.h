#ifndef SELLERFRAME_H
#define SELLERFRAME_H

#include <QFrame>

namespace Ui {
class SellerFrame;
}

class SellerFrame : public QFrame
{
    Q_OBJECT

public:
    explicit SellerFrame(QWidget *parent = nullptr);
    ~SellerFrame();

private:
    Ui::SellerFrame *ui;
};

#endif // SELLERFRAME_H
