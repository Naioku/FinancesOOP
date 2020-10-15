#ifndef USER_H
#define USER_H

#include <iostream>
#include <ctime>

using namespace std;

class User
{
    int id;
    string login;
    string password;
    string name;
    string surname;

public:
    void setId(int newId);
    void setLogin(string newLogin);
    void setPassword(string newPassword);
    void setName(string newName);
    void setSurname(string newSurname);

    int getId();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();


};

#endif // USER_H
