#ifndef USER_H
#define USER_H
#include <string>
#include "linklist.h"
#include "account.h"

using namespace std;

class User
{
    friend class OptionWindow;
    friend class OpeningAccountWindow;
    friend class ChangingWindow;
    friend class MainWindow;
    friend class CheckingWindow;
    friend class WireWindow;
    friend class finalWireWindow;
    friend void saveCardsInFile(User & user , Account & account);


private:
    string name;
    string family;
    string ID;
    string username;
    string password;
    int age;
    LinkList <Account> accounts;

public:
    User();
    void setName(string name);
    void setFamily(string family);
    void setID(string id);
    void setUserName(string username);
    void setPassword(string password);
    void setAge(int age);

};

#endif // USER_H
