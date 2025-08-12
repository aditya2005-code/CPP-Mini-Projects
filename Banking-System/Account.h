
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <fstream>

class Account {
private:
    int accountNumber;
    char name[50];
    int deposit;
    char type;

public:
    Account();
    void setAccountDetails(int, const char*, char, int);
    void showAccount() const;
    void depositAmount(int);
    bool withdrawAmount(int);
    void modifyAccount(const char*, char);

    int getAccountNumber() const;
    int getBalance() const;
    char getAccountType() const;

    void writeToFile(std::fstream&) const;
    void readFromFile(std::fstream&);
};

#endif
