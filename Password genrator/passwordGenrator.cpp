#include "passwordGenrator.h"
#include <iostream>

Password::Password() {
    characters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                  'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                  'u', 'v', 'w', 'x', 'y', 'z',
                  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                  'J', 'K', 'L', 'M', 'N', 'O', 'P',
                  'Q', 'R', 'S', 'T', 'U', 'V',
                  '@','!','#','$','%','^','&','*','(',')'};
}


void Password::welcome(){
    cout<<"==============================================================================";
    cout<<"======================WELCOME TO PASSWORD GENRATOR============================";
    cout<<"==============================================================================";   
    cout<<"====This program generates a random password based on the length you specify.====";
    cout<<"==== You can use it to create secure passwords for your accounts.===="<<endl;

}
string Password::genrate(int length) {
    password.clear();
    if (length <= 0) {
        return "Invalid length";
    }
    
    random_device rd;  
    mt19937 eng(rd()); 
    uniform_int_distribution<> distr(0, characters.size() - 1); 

    for (int i = 0; i < length; ++i) {
        password += characters[distr(eng)];
    }
    
    return password;
}

string Password::getPassword() {
    return password;
}

void Password::setPassword(string &newPass) {
    password = newPass;
}

void Password::printPassword() {
    std::cout << "Generated Password: " << password << std::endl;
}

// End of passwordGenrator.cpp
// This code defines the Password class methods for generating and managing passwords.