#include "wirewindow.h"
#include "ui_wirewindow.h"
#include "optionwindow.h"
#include "finalwirewindow.h"
#include <fstream>
#include <sstream>
#include <QMessageBox>

int fCredit;
Node<Account> * tmp;
string tUsername , tCardNumber , tCredit;

WireWindow::WireWindow(User & u , QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WireWindow)
    , user(u)
{
    ui->setupUi(this);
}

WireWindow::~WireWindow()
{
    delete ui;
}



void WireWindow::on_BackButton_clicked()
{
    OptionWindow * newPage = new OptionWindow(user);
    newPage->show();
    this->close();
}

void WireWindow::on_OkButton_2_clicked()
{

    //writing name in label

    ifstream cardsInformation("Cards.txt");
    if (!cardsInformation.is_open()) {
        QMessageBox::warning(this , "Error!" , "Can't open file");
    }

    string line , line2;
    bool find = false;
    while(getline(cardsInformation , line)){
        istringstream x(line);
        getline(x , tUsername , ',');
        getline(x , tCardNumber , ',');
        getline(x , tCredit , ',');
        if(tCardNumber == ui->TolineEdit->text().toStdString()){
            find = true;
            ifstream userInformation("User.txt");
            if (!userInformation.is_open()) {
                QMessageBox::warning(this , "Error!" , "Can't open file");
            }

            while(getline(userInformation , line2)){
                istringstream x(line2);
                string tUsername2 , tName , tPassword , tFamily;
                getline(x , tUsername2 , ',');
                if(tUsername == tUsername2){
                    getline(x , tPassword , ',');
                    getline(x , tName , ',');
                    getline(x , tFamily , ',');
                    ui->label->setText(QString::fromStdString(tName) + ' ' + QString::fromStdString(tFamily));
                    ui->OkButton->setEnabled(true);
                    break;
                }
            }
            break;
        }
    }
    if(find != true){
        QMessageBox::warning(this , "Error!" , "Invalid card number!!!");
        ui->OkButton->setEnabled(false);
    }

    //checking expiration

    tmp = user.accounts.getHead();
    int month , year;
    while(tmp != nullptr){
        if(ui->FromlineEdit->text().toStdString() == tmp->getData().getCardNumber()){
            month = tmp->getData().getExpirationMonth();
            year = tmp->getData().getExpirationYear();
            fCredit = tmp->getData().getCredit();
            break;
        }
        else
            tmp = tmp->getNext();
    }

    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    int currentMonth = aTime->tm_mon + 1;
    int currentYear = aTime->tm_year + 1900;

    if(!((year > currentYear) || (year == currentYear && month >= currentMonth))){
        QMessageBox::warning(this , "Error!" , "Your card has expired!!!");
        ui->OkButton->setEnabled(false);
    }

    else
        ui->OkButton->setEnabled(true);

}



void WireWindow::on_OkButton_clicked()
{
    int amount = stoi(ui->AmountlineEdit->text().toStdString());

    tm now = getCurrentTime();
    if(getHour(now) == 24 && getMinute(now) == 0 && getSecond(now) == 0){
        tmp->getData().setCapacity(0);
    }

    tmp->getData().setCapacity(tmp->getData().getCapacity() + amount);

    if(tmp->getData().getCapacity() > 6000000)
        QMessageBox::warning(this , "Error!" , "The card-to-card limit in 24 hours is 6 million dollars!!!");

    else{

        if(amount > 3000000)
            QMessageBox::warning(this , "Error!" , "The transaction limit is 3 million dollars!!!");

        else if(fCredit < amount)
            QMessageBox::warning(this , "Error!" , "Your account balance is insufficient!!!");

        else{
            finalWireWindow  * newpage = new finalWireWindow(user , tmp ,tmp->getData().getCardNumber(), amount , tUsername , tCardNumber , tCredit);
            newpage->show();
            this->close();
        }
    }
}

