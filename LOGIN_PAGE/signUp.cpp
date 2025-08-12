#include "details.h"

void Details::signup(){
    cout<<"-------Sign Up Page-------\n";
    cout<<"Enter username:";
    getline(cin, username);
    cout<<"Enter password:";
    getline(cin, password); 
    cout<<"Enter email:";
    getline(cin, email);
    file.open("login.txt", ios::in);

    if(file){
        string searchU, searchP, searchE;
        getline(file, searchU, '*');
        getline(file, searchP, '*');
        getline(file, searchE, '\n');

        while(!file.eof()){
            if(searchU == username){
                cout<<"Username already exists...!"<<endl;
                file.close();
                return;
            }
            getline(file, searchU, '*');
            getline(file, searchP, '*');
            getline(file, searchE, '\n');
        }
        file.close();
    }
}