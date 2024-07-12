#include "functions.h"


void changingFile(string username, string cardNumber, string currentWord, string newWord, int length)
{
    ifstream cardsInformation("Cards.txt");
    vector<string> lines;
    string line;

    if (cardsInformation.is_open()) {
        while (getline(cardsInformation, line)) {
            lines.push_back(line);
        }
        cardsInformation.close();
    }

    else
        cerr <<  "Cannot open the file" << endl;


    for (string & line : lines) {
        istringstream x(line);
        string firstWord , secondWord;
        getline(x, firstWord, ',');
        getline(x , secondWord , ',');
        if (firstWord == username && secondWord == cardNumber){
            size_t position = line.find(currentWord);
            if (position != string::npos) {
                line.replace(position , length , newWord);
                break;
            }
        }
    }

    ofstream cardsInformation2("Cards.txt");
    if (cardsInformation2.is_open()) {
        for (string & line : lines) {
            cardsInformation2 << line << endl;
        }
        cardsInformation2.close();
    }

    else
        cerr << "Cannot open the file" << endl;

}

//-----------------------------------------------------------

void saveCardsInFile(User & user , Account & account) {
    ifstream cardsInformation("Cards.txt");
    string contents;
    if (cardsInformation.is_open()) {
        string line;
        while (getline(cardsInformation, line)) {
            contents += line + "\n";
        }
        cardsInformation.close();
    }

    contents += user.username + "," + account.getCardNumber() +  "," + to_string(account.getCredit()) + "," + account.getPassword() + "," + account.getSecondPassword() +
                "," + to_string(account.getExpirationMonth()) + "," + to_string(account.getExpirationYear()) + ","  + account.getKind() + "," + account.getCvv2() + "," +
                   account.getIBANNumber() + "," + account.getAccountNumber() + "," + "\n";

    ofstream cardsInformation2("Cards.txt");
    if (cardsInformation2.is_open()) {
        cardsInformation2 << contents;
        cardsInformation2.close();
    }
    else
        cerr << "Cannot open the file" << endl;
}


tm getCurrentTime() {
    time_t now = time(0);
    tm* localtm = localtime(&now);
    return *localtm;
}

int getHour(tm time) {
    return time.tm_hour;
}

int getMinute(tm time) {
    return time.tm_min;
}

int getSecond(tm time) {
    return time.tm_sec;
}



