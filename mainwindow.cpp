#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "secondmainwindow.h"
#include "optionwindow.h"
#include "user.h"
#include <QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SignInButton_clicked()
{
    SecondMainWindow * newPage = new SecondMainWindow;
    newPage->show();
    this->close();
}


void MainWindow::on_LogInButton_clicked()
{
    ifstream userInformation("User.txt");
    if (!userInformation.is_open()) {
        QMessageBox::warning(this , "Error!" , "Can't open file");
    }

    string line;
    User user;
    bool accept = false;

    while(getline(userInformation , line)){

        istringstream x(line);
        string username , password;
        getline(x ,username , ',');
        getline(x , password , ',');

        if(username == ui->lineEditName->text().toStdString() && password == ui->lineEditPassword->text().toStdString()){

            accept = true;
            user.setUserName(username);
            user.setPassword(password);

            string name , family , age , id;
            getline(x ,name , ',');
            getline(x , family , ',');
            getline(x ,id , ',');
            getline(x , age , ',');
            user.setName(name);
            user.setFamily(family);
            user.setID(id);
            user.setAge(stoi(age));

            ifstream cardsinformation("Cards.txt");
            if (!cardsinformation.is_open()) {
                QMessageBox::warning(this , "Error!" , "Can't open file");
            }

            string line;
            while(getline(cardsinformation , line)){

                istringstream x(line);
                getline(x , username , ',');

                if(username == ui->lineEditName->text().toStdString()){

                    Account account;
                    string  credit , month , year;
                    getline(x ,account.cardNumber , ',');
                    getline(x , credit , ',');
                    getline(x , account.password , ',');
                    getline(x , account.secondPassword , ',');
                    getline(x , month , ',');
                    getline(x , year , ',');
                    getline(x , account.kind , ',');
                    getline(x , account.cvv2 , ',');
                    getline(x , account.cardIBANNumber , ',');
                    getline(x , account.accountNumber , ',');
                    account.credit = stoi(credit);
                    account.expirationMonth = stoi(month);
                    account.expirationYear = stoi(year);
                    user.accounts.pushBack(account);
                }
            }
            break;
        }
    }


    if(accept){

        OptionWindow * newpage = new OptionWindow(user);
        newpage->show();
        this->close();
    }
    else{
        QMessageBox::information(this , "Error" , "You can't log in.Your username or password is wrong!");
    }
}

