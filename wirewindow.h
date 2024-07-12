#ifndef WIREWINDOW_H
#define WIREWINDOW_H

#include "user.h"
#include "functions.h"
#include <QMainWindow>

namespace Ui {
class WireWindow;
}

class WireWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WireWindow(User & u , QWidget *parent = nullptr);
    ~WireWindow();

private slots:

    void on_BackButton_clicked();

    void on_OkButton_clicked();

    void on_OkButton_2_clicked();


private:
    Ui::WireWindow *ui;
    User user;
};

#endif // WIREWINDOW_H
