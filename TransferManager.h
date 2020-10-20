#ifndef TRANSFER_MANAGER_H
#define TRANSFER_MANAGER_H


#include <iostream>
#include <vector>

#include "Income.h"
#include "HelpingMethods.h"
#include "DateOperations.h"
#include "IncomesFile.h"

using namespace std;

class TransferManager
{
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    IncomesFile incomesFile;
    //vector <Expense> expenses;
    //IncomesFile incomesFile;

    DateOperations dateOperations;

    Income passNewIncomeData();
    void listIncomeData(Income income);
    int passChosenIncomeId();
    char chooseTheOptionFromEditMenu();
    void updateChosenIncomeData(Income income);
    //void showFoundIncomesQuantity(int incomesQuantity);

    int getLastIncomeId();// Temporary


public:

    TransferManager(string incomesFileName = "", int loggedUserId = 0)
        : incomesFile(incomesFileName), LOGGED_USER_ID(loggedUserId)
    {
        incomes = incomesFile.loadIncomesFromFile(LOGGED_USER_ID);
    };

    void addIncome();
    void listAllIncomes();
    void deleteIncome();
    void editIncome();


    // Ideas
    //void searchByItem();
    //void searchByDate();
    //void searchByAmount();

    char chooseTheOptionFromUserMenu();

};

#endif // TRANSFER_MANAGER_H
