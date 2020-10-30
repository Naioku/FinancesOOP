#ifndef FINANCES_H
#define FINANCES_H

#include <iostream>

#include "UserManager.h"
#include "HelpingMethods.h"
#include "UsersFile.h"
#include "TransferManager.h"

using namespace std;

class Finances
{
    UserManager userManager;
    TransferManager *transferManager;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

public:
    Finances(string usersFileName, string incomesFileName, string expensesFileName)
        : userManager(usersFileName), INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName)
        {
            transferManager = NULL;
        };

    ~Finances()
        {
            delete transferManager;
            transferManager = NULL;
        };

    void userRegistration();
    void userLogIn();
    void userLogOut();
    int getIdLoggedInUser();
    void changeLoggedInUserPassword();

    void addIncome();
    void addExpense();
    void editOrDeleteTransfer();
    void listIncomesAndExpensesBetweenProvidedDateAndShowTheBalance();
    void listIncomesAndExpensesFromPresentMonthAndShowTheBalance();
    void listIncomesAndExpensesFromPreviousMonthAndShowTheBalance();


    char chooseTheOptionFromMainMenu();
    char chooseTheOptionFromUserMenu();
};

#endif // FINANCES_H
