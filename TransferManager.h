#ifndef TRANSFER_MANAGER_H
#define TRANSFER_MANAGER_H


#include <iostream>
#include <vector>

#include "Income.h"
#include "HelpingMethods.h"
#include "DateOperations.h"
//#include "PlikZAdresatami.h"

using namespace std;

class TransferManager
{
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    //IncomesFile incomesFile;
    DateOperations dateOperations;

    Income passNewIncomeData();
    void listIncomeData(Income income);
    int passChosenIncomeId();
    //char chooseTheOptionFromEditMenu();
    //void updateChosenIncomeData(Income income);
    //void showFoundIncomesQuantity(int incomesQuantity);

    int getLastIncomeId();// Temporary


public:
    //TransferManager(string incomesFileName = "", int loggedUserId = 0)
        //: incomesFile(passNewUserData), LOGGED_USER_ID(loggedUserId)
    TransferManager(int loggedUserId = 0)
        : LOGGED_USER_ID(loggedUserId)
    {
        //adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };

    void addIncome();
    void listAllIncomes();
    void deleteIncome();
    //void editIncome();

    // Ideas
    //void searchByItem();
    //void searchByDate();
    //void searchByAmount();

    char chooseTheOptionFromUserMenu();

};

#endif // TRANSFER_MANAGER_H
