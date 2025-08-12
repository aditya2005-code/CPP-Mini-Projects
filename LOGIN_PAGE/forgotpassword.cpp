#include "details.h"

using namespace std;

void Details::forgotPassword(){
    cout<<"-------Forgot Password Page-------\n";
    cout<<"Enter username: ";
    getline(cin, username);
    cout<<"Enter email: ";
    getline(cin, email);
    file.open("login.txt", ios::in);
    if(!file){
        cout<<"File Not Found....!"<<endl;
        return;
    }
    string searchU, searchE, searchP;
    getline(file, searchU, '*');
    getline(file, searchP, '*');
    getline(file, searchE, '\n');
    while(!file.eof()){
        if(searchU == username && searchE == email){
            cout<<"Your Password is: "<<searchP<<endl;
            file.close();
            return;
        }
        getline(file, searchU, '*');
        getline(file, searchP, '*');
        getline(file, searchE, '\n');
    }
    file.close();
    cout<<"Username or Email Not Found...!"<<endl;
    cout<<"Please try again...!"<<endl;
    
}

