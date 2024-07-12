#include "optionwindow.h"
#include "ui_optionwindow.h"
#include "openingaccountwindow.h"
#include "wirewindow.h"
#include "mainwindow.h"
#include "changingwindow.h"
#include "checkingwindow.h"
#include <chrono>
#include <ctime>
#include <QMessageBox>

using namespace std;

OptionWindow::OptionWindow(User & u , QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OptionWindow)
    , user(u)
{
    ui->setupUi(this);

    auto start = chrono::system_clock::now();
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;
    time_t end_time = chrono::system_clock::to_time_t(end);
    ui->labelTime->setText(ctime(&end_time));

}

OptionWindow::~OptionWindow()
{
    delete ui;
}



void OptionWindow::on_pushButtonOpening_clicked()
{
    if(user.accounts.getSize() == 5){
        QMessageBox::warning(this , "Error" , "You can't have more than 5 accounts");
    }
    else{
    OpeningAccountWindow * newPage = new OpeningAccountWindow(user);
    newPage->show();
    this->close();
    }

}


void OptionWindow::on_pushButtonWiring_clicked()
{
    WireWindow * newPage = new WireWindow(user);
    newPage->show();
    this->close();
}


void OptionWindow::on_pushButton_4_clicked()
{
    user.accounts.clear();
    MainWindow * newPage = new MainWindow;
    newPage->show();
    this->close();

}



void OptionWindow::on_pushButtonChanging_clicked()
{
    ChangingWindow * newPage = new ChangingWindow(user);
    newPage->show();
    this->close();
}


void OptionWindow::on_pushButtonChecking_clicked()
{
    CheckingWindow * newPage = new CheckingWindow(user);
    newPage->show();
    this->close();
}

