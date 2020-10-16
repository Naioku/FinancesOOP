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
/*
void PlikZUzytkownikami::zapiszWszystkichUzytkownikowDoPliku(vector<Uzytkownik> &uzytkownicy)
{
    fstream xmlFile;
    string liniaZDanymiUzytkownika = "";
    vector <Uzytkownik>::iterator itrKoniec = --uzytkownicy.end();

    plikTekstowy.open(NAZWA_PLIKU_Z_UZYTKOWNIKAMI.c_str(), ios::out);

    if (plikTekstowy.good() == true)
    {
        for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
        {
            liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(*itr);

            if (itr == itrKoniec)
            {
               plikTekstowy << liniaZDanymiUzytkownika;
            }
            else
            {
                plikTekstowy << liniaZDanymiUzytkownika << endl;
            }
            liniaZDanymiUzytkownika = "";
        }
    }
    else
    {
        cout << "Nie mozna otworzyc pliku " << NAZWA_PLIKU_Z_UZYTKOWNIKAMI << endl;
    }
    plikTekstowy.close();
}
*/
