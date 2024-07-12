#ifndef CHANGINGWINDOW_H
#define CHANGINGWINDOW_H
#include "user.h"
#include <QMainWindow>

namespace Ui {
class ChangingWindow;
}

class ChangingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChangingWindow(User & u , QWidget *parent = nullptr);
    ~ChangingWindow();

private slots:
    void on_PWcheckBox_clicked();

    void on_SPWcheckBox_clicked();

    void on_BackButton_clicked();

    void on_OkButton_clicked();

private:
    Ui::ChangingWindow *ui;
    User user;
};

#endif // CHANGINGWINDOW_H
