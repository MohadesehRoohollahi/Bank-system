#ifndef FINALWIREWINDOW_H
#define FINALWIREWINDOW_H

#include <QMainWindow>
#include "user.h"

namespace Ui {
class finalWireWindow;
}

class finalWireWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit finalWireWindow(User & u , Node<Account> * account , string fCardNumber , int amount , string username , string cardNumber, string credit , QWidget *parent = nullptr);
    ~finalWireWindow();

private slots:
    void on_RequestButton_clicked();

    void on_OkpushButton_clicked();

private:
    Ui::finalWireWindow *ui;
    User user;
    Node<Account> * account;
    int amount;
    string fCardNumber , tUsername , tCardNumber , tCredit;
};

#endif // FINALWIREWINDOW_H
