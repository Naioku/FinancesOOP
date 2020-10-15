#include "UserManager.h"

void UserManager::userRegistration()
{
    User user = passNewUserData();

    users.push_back(user);
    usersFile.addUserToFile(user);

    cout << endl << "Account has been created successfully!" << endl << endl;
    system("pause");
}

User UserManager::passNewUserData()
{
    User user;

    user.setId(getNewIdOfTheNewUser());

    do
    {
        cout << "Write down login: ";
        user.setLogin(HelpingMethods::getTheLine());
    } while (doesLoginExists(user.getLogin()) == true);

    cout << "Write down password: ";
    user.setPassword(HelpingMethods::getTheLine());
    cout << "Write down name: ";
    user.setName(HelpingMethods::getTheLine());
    cout << "Write down surname: ";
    user.setSurname(HelpingMethods::getTheLine());


    return user;
}

int UserManager::getNewIdOfTheNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::doesLoginExists(string login)
{
    int usersQuantity = users.size();
    for (int i = 0; i < usersQuantity; i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "User with that login exists. Please, choose another one" << endl;
            return true;
        }
    }

    return false;
}

void UserManager::listAllOfUsers()
{
    int userQuantity = users.size();
    for (int i = 0; i < userQuantity; i++)
    {
        cout << endl;
        cout << "Id: " << users[i].getId() << endl;
        cout << "Login: " << users[i].getLogin() << endl;
        cout << "Password: " << users[i].getPassword() << endl;
        cout << "Name: " << users[i].getName() << endl;
        cout << "Surname: " << users[i].getSurname() << endl;
        cout << endl;
    }
    system("pause");
}

void UserManager::userLogIn()
{
    User user;
    string login = "", password = "";

    cout << "Write down login: ";
    login = HelpingMethods::getTheLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int trialQuantity = 3; trialQuantity > 0; trialQuantity--)
            {
                cout << "Write down password. Left trials: " << trialQuantity << ": ";
                password = HelpingMethods::getTheLine();

                if (itr -> getPassword() == password)
                {
                    idLoggedInUser = itr -> getId();
                    cout << endl << "You have been logged in." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wrong password has been provided 3 times." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "There is no user with that login." << endl << endl;
    system("pause");
    return;
}

void UserManager::userLogOut()
{
    idLoggedInUser = 0;
}

int UserManager::getIdLoggedInUser()
{
    return idLoggedInUser;
}

bool UserManager::doesUserLoggedIn()
{
    if(idLoggedInUser > 0) return true;
    else                   return false;
}

void UserManager::changeLoggedInUserPassword()
{
    string newPassword = "";
    cout << "Write down new password: ";
    newPassword = HelpingMethods::getTheLine();

    for (vector <User>::iterator itr = users.begin(), itrEnd = users.end(); itr != itrEnd; itr++)
    {
        if (itr -> getId() == idLoggedInUser)
        {
            itr -> setPassword(newPassword);
            cout << "Password has been changed." << endl << endl;
            system("pause");
        }
    }
    //plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

void UserManager::loadUsersFromFile()
{
    users = usersFile.loadUsersFromFile();
}

char UserManager::chooseTheOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Log In" << endl;
    cout << "3. List all of users" << endl;
    cout << "9. Close program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = HelpingMethods::getTheChar();

    return choice;
}

