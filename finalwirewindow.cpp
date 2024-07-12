#include "finalwirewindow.h"
#include "ui_finalwirewindow.h"
#include "functions.h"
#include "optionwindow.h"
#include "wirewindow.h"
#include <QMessageBox>

Node<Account> * fAccount;

finalWireWindow::finalWireWindow(User & u , Node<Account> * account ,string fCardNumber , int amount , string username , string cardNumber , string credit ,  QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::finalWireWindow)
    , user(u)
    //, account(account)
    , fCardNumber(fCardNumber)
    , amount(amount)
    , tUsername(username)
    , tCardNumber(cardNumber)
    , tCredit(credit)
{
    ui->setupUi(this);
}

finalWireWindow::~finalWireWindow()
{
    delete ui;
}

void finalWireWindow::on_RequestButton_clicked()
{
    fAccount = user.accounts.getHead();
    while(fAccount != nullptr){
        if(fAccount->getData().getCardNumber() == fCardNumber){
            fAccount->getData().setOTP();
            ui->SPWlineEdit->setText("");
            ui->SPWlineEdit->setText(QString::fromStdString((fAccount->getData().getOTP())));
            break;
        }
        else
            fAccount = fAccount->getNext();
    }
}

void finalWireWindow::on_OkpushButton_clicked(){

    fAccount = user.accounts.getHead();

    while(fAccount != nullptr){
        if(fAccount->getData().getCardNumber() == fCardNumber){
            if(ui->cvv2lineEdit->text().toStdString() == fAccount->getData().getCvv2()){
                int fCredit = fAccount->getData().getCredit();
                if(amount > 100){
                    if(fAccount->getData().getOTP() != ui->SPWlineEdit->text().toStdString()){
                        QMessageBox::warning(this , "Error" , "For transactions above $100, you must use one-time password");
                    }
                    else{
                        fAccount->getData().setCredit(fAccount->getData().getCredit() - amount);
                        changingFile(user.username , fAccount->getData().getCardNumber() , to_string(fCredit) , to_string(fAccount->getData().getCredit()) , to_string(fCredit).length());
                        changingFile(tUsername , tCardNumber , tCredit , to_string(stoi(tCredit)+(amount * 0.99)) , tCredit.length());
                        QMessageBox::information(this , "Message" , "The transaction was completed successfully");
                        OptionWindow * newPage = new OptionWindow(user);
                        newPage->show();
                        this->close();
                    }
                }


                else{
                    if(ui->SPWlineEdit->text().toStdString() == fAccount->getData().getSecondPassword() || fAccount->getData().getOTP() == ui->SPWlineEdit->text().toStdString()){
                        fAccount->getData().setCredit(fAccount->getData().getCredit() - amount);
                        changingFile(user.username , fAccount->getData().getCardNumber() , ','+to_string(fCredit)+',' , ','+to_string(fAccount->getData().getCredit())+',' , to_string(fCredit).length()+2);
                        changingFile(tUsername , tCardNumber , ','+tCredit+',' , ','+to_string(stoi(tCredit)+(amount * 0.99))+',' , tCredit.length()+2);
                        QMessageBox::information(this , "Message" , "The transaction was completed successfully");
                        OptionWindow * newPage = new OptionWindow(user);
                        newPage->show();
                        this->close();
                    }
                    else
                        QMessageBox::warning(this , "Error" , "The password entered is incorrect");
                }
            }

            else
                QMessageBox::warning(this , "Error" , "The CVV2 is incorrect");
            break;
        }

        else
            fAccount = fAccount->getNext();
    }
}


