#include "UsersFile.h"

void UsersFile::addUserToFile(User user)
{
    bool fileExists = xml.Load("users.xml");
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());

    xml.Save("users.xml");
}

vector<User> UsersFile::loadUsersFromFile()
{
    vector<User> users;
    User user;

    xml.Load("users.xml");
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("User"))
    {
        user = getUserData();
        users.push_back(user);
    }


    return users;
}

User UsersFile::getUserData()
{
    User user;

    xml.FindChildElem("UserId");
    user.setId(atoi(xml.GetChildData().c_str()));
    xml.FindChildElem("Login");
    user.setLogin(xml.GetChildData());
    xml.FindChildElem("Password");
    user.setPassword(xml.GetChildData());
    xml.FindChildElem("Name");
    user.setName(xml.GetChildData());
    xml.FindChildElem("Surname");
    user.setSurname(xml.GetChildData());

    return user;
}

bool UsersFile::editUserInFile(User user)
{
    int searchedUserId = user.getId();
    int oneUserId;
    bool fileExists = xml.Load(USERS_FILE_NAME);
    if (fileExists)
    {
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("User"))
        {
            oneUserId = atoi(getOneDataOfOneUserFromFile("UserId").c_str());
            if (oneUserId == searchedUserId)
            {
                removeAllInformationsAboutOneUser();
                readdUserToFile(user);
                xml.Save(USERS_FILE_NAME);
                return true;
            }
        }
    }

    return false;
}

string UsersFile::getOneDataOfOneUserFromFile(string data_type)
{
    xml.FindChildElem(data_type);
    return xml.GetChildData();
}

void UsersFile::removeAllInformationsAboutOneUser()
{
    xml.ResetChildPos();
    while (xml.FindChildElem())
    {
        xml.RemoveChildElem();
    }
}

void UsersFile::readdUserToFile(User user)
{
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
}
