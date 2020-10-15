#include "TransferManager.h"

// Temporary functions
int TransferManager::getLastIncomeId()
{
    int incomesSize = incomes.size();
    int id;
    for (int i = 0; i < incomesSize; i++)
    {
        id = incomes[i].getId();
    }

    return id;
}
//=========================

void TransferManager::addIncome()
{
    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = passNewIncomeData();

    incomes.push_back(income);
    /*
    if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
        cout << "Nowy adresat zostal dodany pomyslnie." << endl;
    else
        cout << "Blad! Nie udalo sie dodac adresata do pliku." << endl;
    */
    system("pause");
}

Income TransferManager::passNewIncomeData()
{
    Income income;

    income.setId(getLastIncomeId() + 1); // temporary
    //income.setId(plikZAdresatami.pobierzIdOstatniegoAdresata() + 1); - instead this above
    //plikZAdresatami.ustawIdOstatniegoAdresata(plikZAdresatami.pobierzIdOstatniegoAdresata() + 1);
    income.setUserId(LOGGED_USER_ID);

    string date;
    while (true)
    {
        cout << "Write down date: ";
        date = HelpingMethods::getTheLine();
        if (dateOperations.isDateCorrect(date))
            break;
        cout << "Date has incorrect format. Please, type again." << endl;
    }

    income.setDate(date);

    cout << "Write down item: ";
    income.setItem(HelpingMethods::getTheLine());
    income.setItem(HelpingMethods::changeFirstLetterToUpperRestToLower(income.getItem()));

    cout << "Write down amount: ";
    income.setAmount(HelpingMethods::getTheLine());

    return income;
}

void TransferManager::listIncomeData(Income income)
{
    cout << endl;
    cout << endl << "Id:                 " << income.getId() << endl;
    cout << "Imie:               " << income.getDate() << endl;
    cout << "Nazwisko:           " << income.getItem() << endl;
    cout << "Numer telefonu:     " << income.getAmount() << endl;
    cout << endl;
}

void TransferManager::listAllIncomes()
{
    system("cls");
    if (!incomes.empty())
    {
        cout << "             >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            listIncomeData(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "There is not any income." << endl << endl;
    }
    system("pause");
}

char TransferManager::chooseTheOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add Income" << endl;
    cout << "2. List all incomes" << endl; // Add Expense
    cout << "3. Show current month balance" << endl;
    cout << "4. Show previous month balance" << endl;
    cout << "5. Show balance of provided period" << endl;
    cout << "6. Edit Income" << endl;
    cout << "7. Delete Income" << endl;
    cout << "---------------------------" << endl;
    cout << "9. Change password" << endl;
    cout << "0. Log Out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your Choice: ";
    choice = HelpingMethods::getTheChar();

    return choice;
}

void TransferManager::deleteIncome()
{
    int deletingIncomeId = 0;
    int deletingIncomeLineNumber = 0;

    system("cls");
    cout << ">>> INCOME DELETING <<<" << endl << endl;
    deletingIncomeId = passChosenIncomeId();

    char character;
    bool doesIncomeExist = false;

    for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if (itr -> getId() == deletingIncomeId)
        {
            doesIncomeExist = true;
            cout << endl << "Confirm by typing 't': ";
            character = HelpingMethods::getTheChar();
            if (character == 't')
            {
                //plikZAdresatami.usunWybranaLinieWPliku(deletingIncomeId);
                incomes.erase(itr);
                cout << endl << endl << "Searched income has been deleted." << endl << endl;
                system("pause");
                //plikZAdresatami.odswiezIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(deletingIncomeId);
                return;
            }
            else
            {
                cout << endl << endl << "Chosen income has not been deleted." << endl << endl;
                system("pause");
                return;
            }
        }
    }
    if (doesIncomeExist == false)
    {
        cout << endl << "There is no income like this." << endl << endl;
        system("pause");
    }
    return;
}

int TransferManager::passChosenIncomeId()
{
    int chosenIncomeId = 0;
    cout << "Type income's ID number: ";
    chosenIncomeId  = HelpingMethods::getTheInt();
    return chosenIncomeId;
}
/*
void AdresatMenedzer::edytujAdresata()
{
    system("cls");
    int idEdytowanegoAdresata = 0;
    //int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = passChosenIncomeId();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;
            wybor = wybierzOpcjeZMenuEdycja();

            switch (wybor)
            {
            case '1':
                cout << "Podaj nowe imie: ";
                adresaci[i].ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze::wczytajLinie()));
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                adresaci[i].ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze::wczytajLinie()));
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                adresaci[i].ustawEmail(MetodyPomocnicze::wczytajLinie());
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustawAdres(MetodyPomocnicze::wczytajLinie());
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

char TransferManager::wybierzOpcjeZMenuEdycja()
{
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

void TransferManager::zaktualizujDaneWybranegoAdresata(Adresat adresat)
{
    plikZAdresatami.edytujWybranaLinieWPliku(adresat);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}

void TransferManager::wyszukajAdresatowPoImieniu()
{
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzImie() == imiePoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void TransferManager::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow)
{
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}

void TransferManager::wyszukajAdresatowPoNazwisku()
{
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}
*/
