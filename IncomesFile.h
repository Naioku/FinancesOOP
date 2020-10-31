#ifndef INCOMES_FILE_H
#define INCOMES_FILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Transfer.h"
#include "HelpingMethods.h"
#include "DateOperations.h"
#include "Markup.h"

using namespace std;

class IncomesFile
{
    const string INCOMES_FILE_NAME;
    int lastIncomeId;
    DateOperations dateOperations;
    CMarkup xml;

    string getOneDataOfOneTransferFromFile(string data_type);
    void getLastIncomeIdFromFile();
    void removeAllInformationsAboutOneIncome();
    void readdIncomeToFile(Transfer income);

public:
    IncomesFile(string incomesFileName = "")
        : INCOMES_FILE_NAME(incomesFileName) {
        lastIncomeId = 0;
    };

    int getTheLastIncomeId();
    void setTheLastIncomeId(int id);
    bool addIncomeToFile(Transfer income);
    vector<Transfer> loadIncomesFromFile(int loggedUserId);
    bool deleteOneIncomeInFileById(int deletedIncomeId);
    void refreshLastIncomeIdAfterRemovingChosenIncome(int deletedIncomeId);
    void editIncomeInFile(Transfer income);
};

#endif // INCOMES_FILE_H
