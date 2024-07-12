#include "openingaccountwindow.h"
#include "ui_openingaccountwindow.h"
#include "account.h"
#include <QMessageBox>
#include "optionwindow.h"

Account account;

OpeningAccountWindow::~OpeningAccountWindow()
{
    delete ui;

}

OpeningAccountWindow::OpeningAccountWindow(User & u , QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OpeningAccountWindow)
    , user(u)
{
    ui->setupUi(this);
    ui->lineEdit_3->setEnabled(false);
}

void OpeningAccountWindow::on_pushButtonOk_clicked()
{
    if(ui->radioButtonDeposit->isChecked() == true)
        account.setKind("Deposit");
    else if(ui->radioButtonSaving->isChecked() == true)
        account.setKind("Saving");
    else
        account.setKind("Current");


    if(stoi(ui->lineEdit->text().toStdString()) < 50){
        ui->lineEdit_2->setEnabled(false);
        QMessageBox::warning(this , "Error!" , "Your first credit must be more than $50");
    }
    else{
        ui->lineEdit_2->setEnabled(true);
        account.setCredit(stoi(ui->lineEdit->text().toStdString()));
    }
}

void OpeningAccountWindow::on_pushButtonOk_2_clicked()
{
    account.setPassword(ui->lineEdit_2->text().toStdString());
    account.setRandomCardNumber();
    account.setRandomCvv2();
    account.setRandomIBANumber();
    account.setAccountNumber();
    account.setExpiration();

    ui->labelCardNumber->setText(QString::fromStdString(account.getCardNumber()));
    ui->labelcvv2->setText(QString::fromStdString(account.getCvv2()));
    ui->labelmonth->setText(QString::fromStdString(to_string(account.getExpirationMonth())));
    ui->labelyear->setText(QString::fromStdString(to_string(account.getExpirationYear())));
    ui->label_iban->setText(QString::fromStdString(account.getIBANNumber()));
    ui->labelaccount->setText(QString::fromStdString(account.getAccountNumber()));

}

void OpeningAccountWindow::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked() == false)
        ui->lineEdit_3->setEnabled(false);

    else
        ui->lineEdit_3->setEnabled(true);
}

void OpeningAccountWindow::on_pushButtonOk_3_clicked()
{
   account.setSecondPassword(ui->lineEdit_3->text().toStdString());

   saveCardsInFile(user , account);

    user.accounts.pushBack(account);

    OptionWindow * newPage = new OptionWindow(user);
    newPage->show();
    this->close();
}


void OpeningAccountWindow::on_pushButton_2_clicked()
{
    OptionWindow * newPage = new OptionWindow(user);
    newPage->show();
    this->close();
}

