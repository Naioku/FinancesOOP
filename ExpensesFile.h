#ifndef EXPENSES_FILE_H
#define EXPENSES_FILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Transfer.h"
#include "HelpingMethods.h"
#include "DateOperations.h"
#include "Markup.h"

using namespace std;

class ExpensesFile
{
    const string EXPENSES_FILE_NAME;
    int lastExpenseId;
    DateOperations dateOperations;
    CMarkup xml;

    string getOneDataOfOneTransferFromFile(string data_type);
    void getLastExpenseIdFromFile();
    void removeAllInformationsAboutOneExpense();
    void readdExpenseToFile(Transfer expense);

public:
    ExpensesFile(string expensesFileName = "")
        : EXPENSES_FILE_NAME(expensesFileName) {
        lastExpenseId = 0;
    };

    int getTheLastExpenseId();
    void setTheLastExpenseId(int id);
    bool addExpenseToFile(Transfer expense);
    vector<Transfer> loadExpensesFromFile(int loggedUserId);
    bool deleteOneExpenseInFileById(int deletedExpenseId);
    void refreshLastExpenseIdAfterRemovingChosenExpense(int deletedExpenseId);
    void editExpenseInFile(Transfer expense);
};

#endif // EXPENSES_FILE_H
