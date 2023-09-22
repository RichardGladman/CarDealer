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

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonView_clicked();

    void on_pushButtonSearch_clicked();

private:
    Ui::SalesFrame *ui;
    QString searchFor;

    void loadData();
};

#endif // SALESFRAME_H
