#ifndef SETTINGSFRAME_H
#define SETTINGSFRAME_H

#include <QFrame>

namespace Ui {
class SettingsFrame;
}

class SettingsFrame : public QFrame
{
    Q_OBJECT

public:
    explicit SettingsFrame(QWidget *parent = nullptr);
    ~SettingsFrame();

private slots:
    void on_pushButtonSave_clicked();

private:
    Ui::SettingsFrame *ui;
};

#endif // SETTINGSFRAME_H
