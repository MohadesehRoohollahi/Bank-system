#include "checkingwindow.h"
#include "ui_checkingwindow.h"
#include "optionwindow.h"

CheckingWindow::CheckingWindow(User & u , QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CheckingWindow)
    , user(u)
{
    ui->setupUi(this);
}

CheckingWindow::~CheckingWindow()
{
    delete ui;
}

void CheckingWindow::on_BackButton_clicked()
{
    OptionWindow * newPage = new OptionWindow(user);
    newPage->show();
    this->close();
}


void CheckingWindow::on_OkButton_clicked()
{
    Node<Account> * tmp  = user.accounts.getHead();

        while(tmp != nullptr){
            if(ui->CardNumlineEdit->text().toStdString() == tmp->getData().getCardNumber()){
                ui->Creditlabel->setText('$' + QString::fromStdString(to_string(tmp->getData().getCredit())));
                break;
            }
            else{
                tmp = tmp->getNext();
            }
        }
}

