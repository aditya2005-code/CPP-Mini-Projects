#include "details.h"
using namespace std;
void Details :: login(){
    cout<<"-----------LOGIN PAGE-----------\n";
    cout<<"Enter Username: ";
    getline(cin, username);
    cout<<"Enter Password: ";
    getline(cin, password);
    file.open("login.txt", ios::in);
    if(!file){
        cout<<"File Not Found....!"<<endl;
        return;
    }
    string searchU , searchP;
    getline(file , searchU , '*');
    getline(file , searchP, '\n');

    while(!file.eof()){
        if(searchU == username && searchP == password){
            if(searchP == password){
                cout<<"Login Successful...!"<<endl;
                file.close();
                return;
            } else {
                cout<<"Incorrect Password...!"<<endl;
                file.close();
                return;
            }
        }
        getline(file, searchU, '*');
        getline(file, searchP, '\n');
    }
    file.close();
    cout<<"Username Not Found...!"<<endl;
}