#include "account.h"
#include <ctime>
#include <time.h>

Account::Account(){
    kind = "";
    cardNumber = "";
    cardIBANNumber = "";
    accountNumber = "";
    cvv2 = "";
    password = "";
    secondPassword = "";
    OTP = "";
    credit = 0;
    expirationMonth = 0;
    expirationYear = 0;
    capacity = 0;
}

void Account::setRandomCardNumber(){

    srand(time(0));
    this->cardNumber = "";
    this->cardNumber += "2005";
    for(int i = 0 ; i < 12 ; i++){
        int num = rand() % 10;
        this->cardNumber += to_string(num);
    }
}


void Account::setRandomIBANumber(){

    this->cardIBANNumber = "";
    for(int i = 0 ; i < 24 ; i++){
        int num = rand() % 10;
        this->cardIBANNumber += to_string(num);
    }
}


void Account::setAccountNumber(){

    this->accountNumber = "";
    for(int i = 11 ; i < 24 ; i++){
        this->accountNumber += this->cardIBANNumber[i];
    }
}

void Account::setRandomCvv2(){

    this->cvv2 = "";
    for(int i = 0 ; i < 4 ; i++){
        int num = rand() % 10;
        this->cvv2 += to_string(num);
    }
}

void Account::setExpiration(){

    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    this->expirationMonth = aTime->tm_mon + 1;
    this->expirationYear = aTime->tm_year + 1900 + 3;
}

void Account::setOTP(){

    this->OTP = "";
    for(int i = 0 ; i < 6 ; i++){
        int num = rand() % 10;
        this->OTP += to_string(num);
    }
}

void Account::setCredit(int credit){
    this->credit = credit;
}

void Account::setPassword(string password){
    this->password = password;
}

void Account::setKind(string kind){
    this->kind = kind;
}

void Account::setSecondPassword(string second){
    this->secondPassword = second;
}

void Account::setCapacity(int capa)
{
    this->capacity = capa;
}

string Account::getCardNumber(){
    return this->cardNumber;
}

string Account::getIBANNumber(){
    return this->cardIBANNumber;
}

string Account::getAccountNumber(){
    return this->accountNumber;
}

string Account::getCvv2(){
    return this->cvv2;
}

string Account::getKind(){
    return this->kind;
}

string Account::getPassword(){
    return this->password;
}

string Account::getSecondPassword(){
    return this->secondPassword;
}

string Account::getOTP(){
    return this->OTP;
}

int Account::getCapacity()
{
    return this->capacity;
}

int Account::getCredit(){
    return this->credit;
}

int Account::getExpirationMonth(){
    return this->expirationMonth;
}

int Account::getExpirationYear(){
    return this->expirationYear;
}

