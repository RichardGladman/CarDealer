#ifndef NEWSALEDIALOG_H
#define NEWSALEDIALOG_H

#include <QDialog>

namespace Ui {
class NewSaleDialog;
}

class NewSaleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewSaleDialog(QWidget *parent = nullptr);
    ~NewSaleDialog();

private slots:
    void on_pushButtonSubmit_clicked();

    void on_pushButtonClose_clicked();

private:
    Ui::NewSaleDialog *ui;
};

#endif // NEWSALEDIALOG_H
