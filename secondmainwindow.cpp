#include "secondmainwindow.h"
#include "ui_secondmainwindow.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QTextStream>
#include <string>
#include <sstream>

using namespace std;

SecondMainWindow::SecondMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SecondMainWindow)
{
    ui->setupUi(this);
}

SecondMainWindow::~SecondMainWindow()
{
    delete ui;
}

void SecondMainWindow::on_SignUpButton_clicked()
{
    string name , family , age , id , username , password;
    name = ui->lineEditName->text().toStdString();
    family = ui->lineEditFamily->text().toStdString();
    age = ui->lineEditAge->text().toStdString();
    id = ui->lineEditID->text().toStdString();
    username = ui->lineEditUsername->text().toStdString();
    password = ui->lineEditPassword->text().toStdString();

    if(name == "" || family == "" || age == "" || id == "" || username == "" || password == ""){
        QMessageBox::warning(this , "Error" , "You must fill all fields");
    }

    else{

        ifstream userInformation("User.txt");
        if (!userInformation.is_open())
            QMessageBox::warning(this , "Error" , "File not open");


        string line , u;
        bool exist = false;
        while(getline(userInformation , line)){
            istringstream x(line);
            getline(x , u , ',');
            if(username == u){
                exist = true;
                QMessageBox::warning(this , "Error" , "This username already exists");
                break;
            }
        }
        if(!exist){
            ofstream userInformation("User.txt" , ios::app);
            if (!userInformation.is_open()) {
                QMessageBox::warning(this , "Error" , "File not open");
            }

            userInformation <<  username << "," << password  << ","  << name << "," <<  family << "," << id << "," << age << "," << endl;
            userInformation.close();

            MainWindow * newPage = new MainWindow;
            newPage->show();
            this->close();
        }
    }
}
