
#include "BankOperations.h"
#include <iostream>

int main() {
    char choice;
    int accNum;

    do {
        std::cout << "\n\n====== Bank Management System ======";
        std::cout << "\n1. Create Account";
        std::cout << "\n2. Deposit Money";
        std::cout << "\n3. Withdraw Money";
        std::cout << "\n4. Check Balance";
        std::cout << "\n5. Display All Accounts";
        std::cout << "\n6. Close Account";
        std::cout << "\n7. Modify Account";
        std::cout << "\n8. Exit";
        std::cout << "\nSelect option (1-8): ";
        std::cin >> choice;

        switch (choice) {
            case '1': createAccount(); break;
            case '2': std::cout << "Enter Account Number: "; std::cin >> accNum; depositWithdraw(accNum, 1); break;
            case '3': std::cout << "Enter Account Number: "; std::cin >> accNum; depositWithdraw(accNum, 2); break;
            case '4': std::cout << "Enter Account Number: "; std::cin >> accNum; displayAccount(accNum); break;
            case '5': displayAllAccounts(); break;
            case '6': std::cout << "Enter Account Number: "; std::cin >> accNum; deleteAccount(accNum); break;
            case '7': std::cout << "Enter Account Number: "; std::cin >> accNum; modifyAccount(accNum); break;
            case '8': std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != '8');

    return 0;
}
