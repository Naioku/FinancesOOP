#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
#include "HelpingMethods.h"
#include "UsersFile.h"

using namespace std;

class UserManager
{
    User user;
    vector<User> users;
    int idLoggedInUser;
    UsersFile usersFile;

    User passNewUserData();
    int getNewIdOfTheNewUser();
    bool doesLoginExists(string login);
    void loadUsersFromFile();

public:
    UserManager(string usersFileName) : usersFile(usersFileName){
        loadUsersFromFile();
        idLoggedInUser = 0;
    };
    void userRegistration();
    void listAllOfUsers(); // to delete
    void userLogIn();
    void userLogOut();
    int getIdLoggedInUser();
    bool doesUserLoggedIn();
    void changeLoggedInUserPassword();
    char chooseTheOptionFromMainMenu();

};

#endif // USER_MANAGER_H
