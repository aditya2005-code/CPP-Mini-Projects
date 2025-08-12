#include "passwordGenrator.h"
using namespace std;

int main(){
    Password pass;
    pass.welcome();
    int length;
    X:
    cout<<"Enter the length of the password :";
    cin>>length;
    if(length <= 0){
        cout<<"Please enter a valid length greater than 0."<<endl;
        goto X;
    }
    string password = pass.genrate(length);
    if(password == "Invalid length"){
        cout<<"Please enter a valid length greater than 0."<<endl;
    }
    else{
        pass.setPassword(password);
        pass.printPassword();
        cout<<"===============Password genrated succesfully!==============="<<endl;
    }
    return 0;
}