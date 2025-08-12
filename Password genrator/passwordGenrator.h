#include<iostream>
#include<vector>
#include<climits>
#include<random>
#include<string>
using namespace std;

class Password {
    public:
    int length;
    string password;
    vector<char> characters;
    Password();
    void welcome();
    string genrate(int length);
    string getPassword() ;
    void setPassword(string &newPass);
    void printPassword();

};