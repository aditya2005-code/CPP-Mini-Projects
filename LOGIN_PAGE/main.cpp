#include "details.h"
using namespace std;
Details obj;
int main() {
    char choice;
    cout << "\n1- Login";
    cout << "\n2- Sign-Up";
    cout << "\n3- Forgot Password";
    cout << "\n4- Exit";
    cout << "\nEnter Your Choice :: ";
    cin >> choice;

    switch (choice) {
        case '1':
            cin.ignore();
            obj.login();
            break;
        case '2':
            cin.ignore();
            obj.signup();
            break;
        case '3':
            cin.ignore();
            obj.forgotPassword();
            break;
        case '4':
            return 0;
        default:
            cout << "Invalid Selection...!";
    }
    return 0;
}