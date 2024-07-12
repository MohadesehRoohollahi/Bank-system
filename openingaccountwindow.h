#ifndef OPENINGACCOUNTWINDOW_H
#define OPENINGACCOUNTWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "account.h"
#include <fstream>
#include "functions.h"

namespace Ui {
class OpeningAccountWindow;
}

class OpeningAccountWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OpeningAccountWindow(User & u , QWidget *parent = nullptr);
    ~OpeningAccountWindow();

private slots:

    void on_pushButtonOk_clicked();

    void on_pushButtonOk_2_clicked();

    void on_checkBox_clicked();

    void on_pushButtonOk_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::OpeningAccountWindow *ui;
    User user;
};

#endif // OPENINGACCOUNTWINDOW_H
