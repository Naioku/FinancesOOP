#ifndef TRANSFER_MANAGER_H
#define TRANSFER_MANAGER_H


#include <iostream>
#include <vector>

#include "Income.h"
#include "Expense.h"
#include "HelpingMethods.h"
#include "DateOperations.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"

using namespace std;

class TransferManager
{
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    IncomesFile incomesFile;
    vector <Expense> expenses;
    ExpensesFile expensesFile;

    DateOperations dateOperations;

    Income passNewIncomeData();
    Expense passNewExpenseData();
    void listIncomeData(Income income);
    void listExpenseData(Expense expense);
    int passChosenIncomeId();
    int passChosenExpenseId();
    char chooseTheOptionFromEditMenu();
    //void updateChosenIncomeData(Income income);
    //void showFoundIncomesQuantity(int incomesQuantity);

public:
    TransferManager(string incomesFileName = "", string expensesFileName = "", int loggedUserId = 0)
        : incomesFile(incomesFileName), expensesFile(expensesFileName), LOGGED_USER_ID(loggedUserId)
    {
        incomes = incomesFile.loadIncomesFromFile(LOGGED_USER_ID);
        expenses = expensesFile.loadExpensesFromFile(LOGGED_USER_ID);
    };

    void addIncome();
    void addExpense();
    void listAllIncomes();
    void listAllExpenses();
    void deleteIncome();
    void deleteExpense();
    void editExpense();


    // Ideas
    //void searchByItem();
    //void searchByDate();
    //void searchByAmount();

    char chooseTheOptionFromUserMenu();

};

#endif // TRANSFER_MANAGER_H
