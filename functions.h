#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include "user.h"
#include "account.h"

using namespace std;

void changingFile(string username  , string cardNumber , string currentWord , string newWord ,  int length);

void saveCardsInFile(User & user , Account & account);

tm getCurrentTime();

int getHour(tm time);

int getMinute(tm time);

int getSecond(tm time);

#endif // FUNCTIONS_H
