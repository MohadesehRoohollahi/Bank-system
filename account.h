#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

using namespace std;
class Account
{
    friend class OpeningAccountWindow;
    friend class ChangingWindow;
    friend class MainWindow;
private:
    string kind;
    string cardNumber;
    string cardIBANNumber; //24
    string accountNumber; //13
    string cvv2;
    string password;
    string secondPassword;
    string OTP;
    int credit;
    int expirationMonth;
    int expirationYear;
    int capacity;

public:

    Account();

    void setRandomCardNumber();
    void setRandomIBANumber();
    void setAccountNumber();
    void setRandomCvv2();
    void setExpiration();
    void setOTP();
    void setCredit(int credit);
    void setPassword(string password);
    void setKind(string kind);
    void setSecondPassword(string second);
    void setCapacity(int capa);
    string getCardNumber();
    string getIBANNumber();
    string getAccountNumber();
    string getCvv2();
    string getKind();
    string getPassword();
    string getSecondPassword();
    string getOTP();
    int getCapacity();
    int getCredit();
    int getExpirationMonth();
    int getExpirationYear();

};

#endif // ACCOUNT_H
