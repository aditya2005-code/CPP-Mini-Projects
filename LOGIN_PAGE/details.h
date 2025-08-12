#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<algorithm>
using namespace std;
class Details{
    private:
    string username;
    string password;
    string email;
    fstream file;
    public:
    void login();
    void signup();
    void forgotPassword();
};