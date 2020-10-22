#ifndef EXPENSES_FILE_H
#define EXPENSES_FILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Expense.h"
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
    //int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    //Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    //string pobierzLiczbe(string tekst, int pozycjaZnaku);
    //int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

    //void usunPlik(string nazwaPlikuZRozszerzeniem);
    //void zmienNazwePliku(string staraNazwa, string nowaNazwa);

public:
    ExpensesFile(string expensesFileName = "")
        : EXPENSES_FILE_NAME(expensesFileName) {
        lastExpenseId = 0;
    };

    int getTheLastExpenseId();
    void setTheLastExpenseId(int id);
    bool addExpenseToFile(Expense expense);
    vector<Expense> loadExpensesFromFile(int loggedUserId);
    bool deleteOneExpenseInFileById(int deletedExpenseId);
    void refreshLastIncomeIdAfterRemovingChosenIncome(int deletedExpenseId);
    //void usunWybranaLinieWPliku(int idUsuwanegoAdresata);
    //void odswiezIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata);
    //void pobierzZPlikuIdOstatniegoAdresata();
    //void edytujWybranaLinieWPliku(Adresat adresat);
};

#endif // EXPENSES_FILE_H
