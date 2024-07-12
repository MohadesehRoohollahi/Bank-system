#ifndef CHECKINGWINDOW_H
#define CHECKINGWINDOW_H

#include <QMainWindow>
#include "user.h"

namespace Ui {
class CheckingWindow;
}

class CheckingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CheckingWindow(User & u , QWidget *parent = nullptr);
    ~CheckingWindow();

private slots:
    void on_BackButton_clicked();

    void on_OkButton_clicked();

private:
    Ui::CheckingWindow *ui;
    User user;
};

#endif // CHECKINGWINDOW_H
