#include "ExpensesFile.h"

int ExpensesFile::getTheLastExpenseId()
{
    return lastExpenseId;
}

void ExpensesFile::setTheLastExpenseId(int id)
{
    lastExpenseId = id;
}

bool ExpensesFile::addExpenseToFile(Expense expense)
{
    bool fileExists = xml.Load(EXPENSES_FILE_NAME);
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("Id", expense.getId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", expense.getDate());
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", expense.getAmount());

    xml.Save(EXPENSES_FILE_NAME);
    return true;
}

string ExpensesFile::getOneDataOfOneTransferFromFile(string data_type)
{
    xml.FindChildElem(data_type);
    return xml.GetChildData();
}

vector<Expense> ExpensesFile::loadExpensesFromFile(int loggedUserId)
{
    Expense expense;
    vector<Expense> expenses;
    int oneTransferUserId;

    xml.Load("expenses.xml");
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("Expense"))
    {
        oneTransferUserId = atoi(getOneDataOfOneTransferFromFile("UserId").c_str());
        if (oneTransferUserId == loggedUserId)
        {
            xml.ResetChildPos();
            lastExpenseId = atoi(getOneDataOfOneTransferFromFile("Id").c_str());
            expense.setId(lastExpenseId);
            expense.setUserId(oneTransferUserId);
            expense.setDate(getOneDataOfOneTransferFromFile("Date"));
            expense.setItem(getOneDataOfOneTransferFromFile("Item"));
            expense.setAmount(getOneDataOfOneTransferFromFile("Amount"));

            expenses.push_back(expense);
        }
    }

    return expenses;
}
/*
int IncomesFile::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = atoi(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata).c_str());
    return idAdresata;
}

string IncomesFile::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int IncomesFile::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = atoi(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika).c_str());

    return idUzytkownika;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                idOstatniegoAdresata = atoi(pojedynczaDanaAdresata.c_str());
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

void IncomesFile::usunWybranaLinieWPliku(int idUsuwanegoAdresata)
{
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int idWczytanegoAdresata;
    int numerWczytanejLinii = 1;
    bool czyLinieJuzUsunieto = false;

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWA.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true)
    {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {
            idWczytanegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia);
            // Tych przypadkow jest tyle, gdyz chcemy osiagnac taki efekt,
            // aby na koncu pliku nie bylo pustej linii
            if (idWczytanegoAdresata == idUsuwanegoAdresata)
                czyLinieJuzUsunieto = true;
            else if (numerWczytanejLinii == 1)
                tymczasowyPlikTekstowy << wczytanaLinia;
            else if (numerWczytanejLinii == 2 && czyLinieJuzUsunieto == true)
                tymczasowyPlikTekstowy << wczytanaLinia;
            else if (numerWczytanejLinii == 2 && czyLinieJuzUsunieto == false)
                tymczasowyPlikTekstowy << endl << wczytanaLinia;
            else if (numerWczytanejLinii > 2)
                tymczasowyPlikTekstowy << endl << wczytanaLinia;
            numerWczytanejLinii++;
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(NAZWA_PLIKU_Z_ADRESATAMI);
        zmienNazwePliku(NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWA, NAZWA_PLIKU_Z_ADRESATAMI);
    }
}

void IncomesFile::usunPlik(string nazwaPlikuZRozszerzeniem)
{
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void IncomesFile::zmienNazwePliku(string staraNazwa, string nowaNazwa)
{
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}

void IncomesFile::odswiezIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata)
{
    if (idUsuwanegoAdresata == idOstatniegoAdresata)
        pobierzZPlikuIdOstatniegoAdresata();
}

void IncomesFile::pobierzZPlikuIdOstatniegoAdresata()
{
    idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {}
            daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    plikTekstowy.close();
}

void IncomesFile::edytujWybranaLinieWPliku(Adresat adresat)
{
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string liniaZDanymiAdresataOddzielonymiPionowymiKreskami = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;
    int idEdytowanegoAdresata = adresat.pobierzId();
    int idWczytanegoAdresata = 0;

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWA.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true)
    {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {
            idWczytanegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia);
            if (idWczytanegoAdresata == idEdytowanegoAdresata)
            {
                if (numerWczytanejLinii == 1)
                {
                    tymczasowyPlikTekstowy << liniaZDanymiAdresataOddzielonymiPionowymiKreskami;
                }
                else if (numerWczytanejLinii > 1)
                {
                    tymczasowyPlikTekstowy << endl << liniaZDanymiAdresataOddzielonymiPionowymiKreskami;
                }
            }
            else
            {
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << wczytanaLinia;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << wczytanaLinia;
            }
            numerWczytanejLinii++;
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(NAZWA_PLIKU_Z_ADRESATAMI);
        zmienNazwePliku(NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWA, NAZWA_PLIKU_Z_ADRESATAMI);
    }
}
*/
