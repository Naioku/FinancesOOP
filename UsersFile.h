#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Markup.h"
#include "User.h"
#include "HelpingMethods.h"

using namespace std;

class UsersFile
{
    const string USERS_FILE_NAME;
    CMarkup xml;

    User getUserData();
    string getOneDataOfOneUserFromFile(string data_type);
    void removeAllInformationsAboutOneUser();
    void readdUserToFile(User user);

public:
    UsersFile(string usersFileName) : USERS_FILE_NAME(usersFileName) {};
    void addUserToFile(User user);
    vector<User> loadUsersFromFile();
    bool editUserInFile(User user);
};

#endif // USERSFILE_H
