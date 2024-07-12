#include "changingwindow.h"
#include "ui_changingwindow.h"
#include "optionwindow.h"
#include "linklist.h"
#include "functions.h"
ChangingWindow::ChangingWindow(User & u , QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChangingWindow)
    , user(u)
{
    ui->setupUi(this);
    ui->PWlineEdit->setEnabled(false);
    ui->SPWlineEdit->setEnabled(false);
}

ChangingWindow::~ChangingWindow()
{
    delete ui;
}

void ChangingWindow::on_PWcheckBox_clicked()
{
    if(ui->PWcheckBox->isChecked() == true){
        ui->PWlineEdit->setEnabled(true);
    }

    else
        ui->PWlineEdit->setEnabled(false);
}


void ChangingWindow::on_SPWcheckBox_clicked()
{

    if(ui->SPWcheckBox->isChecked() == true){
        ui->SPWlineEdit->setEnabled(true);
    }

    else
        ui->SPWlineEdit->setEnabled(false);

}


void ChangingWindow::on_BackButton_clicked()
{
    OptionWindow * newPage = new OptionWindow(user);
    newPage->show();
    this->close();
}



void ChangingWindow::on_OkButton_clicked()
{
    Node<Account> * tmp  = user.accounts.getHead();

    if(ui->PWlineEdit->text().length() > 0){
        while(tmp != nullptr){

            if(tmp->getData().cardNumber == ui->CardNumlineEdit->text().toStdString()){
                changingFile(user.username , tmp->getData().getCardNumber() , ',' + tmp->getData().password + ',' , ',' + ui->PWlineEdit->text().toStdString() + ',' , 6);
                tmp->getData().setPassword(ui->PWlineEdit->text().toStdString());
                break;  
            }

            else
                tmp = tmp->getNext();
        }
    }

    if(ui->SPWlineEdit->text().length() > 0){
        while(tmp != nullptr){

            if(tmp->getData().cardNumber == ui->CardNumlineEdit->text().toStdString()){
                changingFile(user.username , tmp->getData().getCardNumber() , ',' + tmp->getData().secondPassword + ',' , ',' + ui->SPWlineEdit->text().toStdString() + ',' , 8);
                tmp->getData().setSecondPassword(ui->SPWlineEdit->text().toStdString());
                break;
            }

            else
                tmp = tmp->getNext();
        }
    }

    OptionWindow * newPage = new OptionWindow(user);
    newPage->show();
    this->close();
}

