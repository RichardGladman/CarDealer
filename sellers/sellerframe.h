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

private slots:
    void on_pushButtonSearch_clicked();

    void on_pushButtonAdd_clicked();

    void on_pushButtonEdit_clicked();

    void on_pushButtonDelete_clicked();

private:
    Ui::SellerFrame *ui;
    QString searchFor;

    void loadData();
};

#endif // SELLERFRAME_H
