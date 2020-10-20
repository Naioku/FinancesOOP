#ifndef INCOMES_FILE_H
#define INCOMES_FILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Income.h"
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
    //int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    //Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    //string pobierzLiczbe(string tekst, int pozycjaZnaku);
    //int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

    //void usunPlik(string nazwaPlikuZRozszerzeniem);
    //void zmienNazwePliku(string staraNazwa, string nowaNazwa);

public:
    IncomesFile(string incomesFileName = "")
        : INCOMES_FILE_NAME(incomesFileName) {
        lastIncomeId = 0;
    };

    int getTheLastIncomeId();
    void setTheLastIncomeId(int id);
    bool addIncomeToFile(Income income);
    vector<Income> loadIncomesFromFile(int loggedUserId);
    //void usunWybranaLinieWPliku(int idUsuwanegoAdresata);
    //void odswiezIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata);
    //void pobierzZPlikuIdOstatniegoAdresata();
    //void edytujWybranaLinieWPliku(Adresat adresat);
};

#endif // INCOMES_FILE_H
