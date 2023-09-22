#ifndef NEWSELLERDIALOG_H
#define NEWSELLERDIALOG_H

#include <QDialog>

namespace Ui {
class NewSellerDialog;
}

class NewSellerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewSellerDialog(QWidget *parent = nullptr);
    ~NewSellerDialog();

private slots:
    void on_pushButtonClose_clicked();

    void on_pushButtonSave_clicked();

private:
    Ui::NewSellerDialog *ui;
};

#endif // NEWSELLERDIALOG_H
