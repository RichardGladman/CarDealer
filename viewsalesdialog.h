#ifndef VIEWSALESDIALOG_H
#define VIEWSALESDIALOG_H

#include <QDialog>

namespace Ui {
class ViewSalesDialog;
}

class ViewSalesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewSalesDialog(int id, QWidget *parent = nullptr);
    ~ViewSalesDialog();

private slots:
    void on_pushButtonClose_clicked();

private:
    Ui::ViewSalesDialog *ui;
};

#endif // VIEWSALESDIALOG_H
