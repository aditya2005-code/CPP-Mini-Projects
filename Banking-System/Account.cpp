
#include "Account.h"
#include <cstring>
#include <cctype>

Account::Account() : accountNumber(0), deposit(0), type(' ') {
    std::strcpy(name, "");
}

void Account::setAccountDetails(int accNum, const char* accName, char accType, int initialDeposit) {
    accountNumber = accNum;
    std::strncpy(name, accName, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
    type = std::toupper(accType);
    deposit = initialDeposit;
}

void Account::showAccount() const {
    std::cout << "\nAccount Number: " << accountNumber;
    std::cout << "\nAccount Holder: " << name;
    std::cout << "\nAccount Type: " << type;
    std::cout << "\nBalance: " << deposit << "\n";
}

void Account::depositAmount(int amount) {
    if (amount > 0) deposit += amount;
}

bool Account::withdrawAmount(int amount) {
    if (amount > 0 && deposit >= amount) {
        deposit -= amount;
        return true;
    }
    return false;
}

void Account::modifyAccount(const char* newName, char newType) {
    std::strncpy(name, newName, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
    type = std::toupper(newType);
}

int Account::getAccountNumber() const {
    return accountNumber;
}

int Account::getBalance() const {
    return deposit;
}

char Account::getAccountType() const {
    return type;
}

void Account::writeToFile(std::fstream& file) const {
    file.write(reinterpret_cast<const char*>(this), sizeof(Account));
}

void Account::readFromFile(std::fstream& file) {
    file.read(reinterpret_cast<char*>(this), sizeof(Account));
}
