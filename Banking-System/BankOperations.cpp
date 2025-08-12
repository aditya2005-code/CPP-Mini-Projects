// BankOperations.cpp
#include "Account.h"
#include "BankOperations.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

void createAccount() {
    Account acc;
    int accNum, initialDeposit;
    char accType, name[50];

    cout << "\nEnter Account Number: ";
    cin >> accNum;
    cin.ignore();

    cout << "Enter Account Holder Name: ";
    cin.getline(name, 50);

    cout << "Enter Account Type (C/S): ";
    cin >> accType;

    cout << "Enter Initial Deposit: ";
    cin >> initialDeposit;

    acc.setAccountDetails(accNum, name, accType, initialDeposit);

    fstream file("accounts.dat", ios::binary | ios::app);
    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    acc.writeToFile(file);
    file.close();

    cout << "Account Created Successfully.\n";
}

void displayAccount(int accNum) {
    Account acc;
    bool found = false;
    fstream file("accounts.dat", ios::binary | ios::in);

    if (!file) {
        cout << "File not found!\n";
        return;
    }

    while (file.read(reinterpret_cast<char*>(&acc), sizeof(Account))) {
        if (acc.getAccountNumber() == accNum) {
            acc.showAccount();
            found = true;
            break;
        }
    }
    file.close();

    if (!found)
        cout << "Account not found.\n";
}

void modifyAccount(int accNum) {
    Account acc;
    bool found = false;
    fstream file("accounts.dat", ios::binary | ios::in | ios::out);

    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    while (!file.eof() && !found) {
        streampos pos = file.tellg();
        if (file.read(reinterpret_cast<char*>(&acc), sizeof(Account))) {
            if (acc.getAccountNumber() == accNum) {
                cout << "\nCurrent Account Details:\n";
                acc.showAccount();

                char newName[50], newType;
                cout << "Enter New Name: ";
                cin.ignore();
                cin.getline(newName, 50);
                cout << "Enter New Type (C/S): ";
                cin >> newType;

                acc.modifyAccount(newName, newType);
                file.seekp(pos);
                acc.writeToFile(file);

                cout << "Account Modified.\n";
                found = true;
            }
        }
    }
    file.close();
    if (!found) cout << "Account not found.\n";
}

void deleteAccount(int accNum) {
    Account acc;
    fstream inFile("accounts.dat", ios::binary | ios::in);
    fstream outFile("temp.dat", ios::binary | ios::out);
    bool found = false;

    if (!inFile) {
        cout << "Error opening file.\n";
        return;
    }

    while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(Account))) {
        if (acc.getAccountNumber() != accNum) {
            outFile.write(reinterpret_cast<char*>(&acc), sizeof(Account));
        } else {
            found = true;
        }
    }

    inFile.close();
    outFile.close();
    remove("accounts.dat");
    rename("temp.dat", "accounts.dat");

    if (found)
        cout << "Account Deleted.\n";
    else
        cout << "Account not found.\n";
}

void displayAllAccounts() {
    Account acc;
    fstream file("accounts.dat", ios::binary | ios::in);

    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    cout << "\nAccount Holders List:\n";
    cout << left << setw(15) << "Acc No" << setw(20) << "Name"
         << setw(10) << "Type" << setw(10) << "Balance\n";
    cout << "----------------------------------------------------------\n";

    while (file.read(reinterpret_cast<char*>(&acc), sizeof(Account))) {
        cout << left << setw(15) << acc.getAccountNumber()
             << setw(20) << acc.getAccountType()
             << setw(10) << acc.getAccountType()
             << setw(10) << acc.getBalance() << "\n";
    }

    file.close();
}

void depositWithdraw(int accNum, int option) {
    Account acc;
    bool found = false;
    fstream file("accounts.dat", ios::binary | ios::in | ios::out);

    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    while (!file.eof() && !found) {
        streampos pos = file.tellg();
        if (file.read(reinterpret_cast<char*>(&acc), sizeof(Account))) {
            if (acc.getAccountNumber() == accNum) {
                int amount;
                acc.showAccount();
                if (option == 1) {
                    cout << "Enter deposit amount: ";
                    cin >> amount;
                    acc.depositAmount(amount);
                } else {
                    cout << "Enter withdrawal amount: ";
                    cin >> amount;
                    if (!acc.withdrawAmount(amount)) {
                        cout << "Insufficient balance!\n";
                        return;
                    }
                }
                file.seekp(pos);
                acc.writeToFile(file);
                cout << "Transaction Successful.\n";
                found = true;
            }
        }
    }

    file.close();
    if (!found)
        cout << "Account not found.\n";
}
