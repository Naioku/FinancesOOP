#ifndef TRANSFER_MANAGER_H
#define TRANSFER_MANAGER_H


#include <iostream>
#include <vector>

#include "Transfer.h"
#include "HelpingMethods.h"
#include "DateOperations.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"

using namespace std;

class TransferManager
{
    const int LOGGED_USER_ID;
    const string LOGGED_USER_NAME;
    const string LOGGED_USER_SURNAME;
    vector <Transfer> incomes;
    IncomesFile incomesFile;
    vector <Transfer> expenses;
    ExpensesFile expensesFile;

    DateOperations dateOperations;

    Transfer passNewIncomeData();
    Transfer passNewExpenseData();
    void listIncomeData(Transfer income);
    void listExpenseData(Transfer expense);
    int passChosenIncomeId();
    int passChosenExpenseId();
    char chooseTheOptionFromEditMenu();
    int passChosenTransferId();
    void updateChosenIncomeData(Transfer income);
    void updateChosenExpenseData(Transfer expense);
    int getDateFromUser();
    void listIncomesBetweenProvidedDates(int providedDateFrom, int providedDateTo);
    void listExpensesBetweenProvidedDates(int providedDateFrom, int providedDateTo);
    void calculateBalance(int providedDateFrom, int providedDateTo);
    char chooseTheOptionEditDeleteMenu();
    void deleteIncome();
    void deleteExpense();
    void editIncome();
    void editExpense();

public:
    TransferManager(string incomesFileName = "", string expensesFileName = "", int loggedUserId = 0, string loggedUserName = "", string loggedUserSurname = "")
        : incomesFile(incomesFileName), expensesFile(expensesFileName), LOGGED_USER_ID(loggedUserId), LOGGED_USER_NAME(loggedUserName), LOGGED_USER_SURNAME(loggedUserSurname)
    {
        incomes = incomesFile.loadIncomesFromFile(LOGGED_USER_ID);
        expenses = expensesFile.loadExpensesFromFile(LOGGED_USER_ID);
    };

    void addIncome();
    void addExpense();
    //void listAllIncomes(); Only in case of searching a bug
    //void listAllExpenses(); Only in case of searching a bug

    void listIncomesAndExpensesBetweenProvidedDateAndShowTheBalance();
    void listIncomesAndExpensesFromPresentMonthAndShowTheBalance();
    void listIncomesAndExpensesFromPreviousMonthAndShowTheBalance();
    void editOrDeleteTransfer();

    char chooseTheOptionFromUserMenu();
};

#endif // TRANSFER_MANAGER_H
