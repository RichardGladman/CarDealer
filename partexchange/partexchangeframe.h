#ifndef PARTEXCHANGEFRAME_H
#define PARTEXCHANGEFRAME_H

#include <QFrame>

namespace Ui {
class PartExchangeFrame;
}

class PartExchangeFrame : public QFrame
{
    Q_OBJECT

public:
    explicit PartExchangeFrame(QWidget *parent = nullptr);
    ~PartExchangeFrame();

private slots:
    void on_pushButtonSearch_clicked();

    void on_pushButtonView_clicked();

    void on_pushButtonStock_clicked();

    void on_pushButtonAuction_clicked();

private:
    QString searchFor;
    Ui::PartExchangeFrame *ui;

    void loadData();
};

#endif // PARTEXCHANGEFRAME_H
