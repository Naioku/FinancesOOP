#include "TransferManager.h"

// INCOMES ===========================================================

void TransferManager::addIncome()
{
    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = passNewIncomeData();

    incomes.push_back(income);

    if (incomesFile.addIncomeToFile(income))
        cout << "New income has been added successfully." << endl;
    else
        cout << "Error! We could not add new income." << endl;

    system("pause");
}

Income TransferManager::passNewIncomeData()
{
    Income income;

    income.setId(incomesFile.getTheLastIncomeId() + 1);
    incomesFile.setTheLastIncomeId(incomesFile.getTheLastIncomeId() + 1);
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
    cout << "Date:               " << income.getDate() << endl;
    cout << "Item:               " << income.getItem() << endl;
    cout << "Amount:             " << income.getAmount() << endl;
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

// EXPENSES ======================================================

void TransferManager::addExpense()
{
    Expense expense;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    expense = passNewExpenseData();

    expenses.push_back(expense);

    if (expensesFile.addExpenseToFile(expense))
        cout << "New expense has been added successfully." << endl;
    else
        cout << "Error! We could not add new expense." << endl;

    system("pause");
}

Expense TransferManager::passNewExpenseData()
{
    Expense expense;

    expense.setId(expensesFile.getTheLastExpenseId() + 1);
    expensesFile.setTheLastExpenseId(expensesFile.getTheLastExpenseId() + 1);
    expense.setUserId(LOGGED_USER_ID);

    string date;
    while (true)
    {
        cout << "Write down date: ";
        date = HelpingMethods::getTheLine();
        if (dateOperations.isDateCorrect(date))
            break;
        cout << "Date has incorrect format. Please, type again." << endl;
    }

    expense.setDate(date);

    cout << "Write down item: ";
    expense.setItem(HelpingMethods::getTheLine());
    expense.setItem(HelpingMethods::changeFirstLetterToUpperRestToLower(expense.getItem()));

    cout << "Write down amount: ";
    expense.setAmount(HelpingMethods::getTheLine());

    return expense;
}

void TransferManager::listExpenseData(Expense expense)
{
    cout << endl;
    cout << endl << "Id:                 " << expense.getId() << endl;
    cout << "Date:               " << expense.getDate() << endl;
    cout << "Item:               " << expense.getItem() << endl;
    cout << "Amount:             " << expense.getAmount() << endl;
    cout << endl;
}

void TransferManager::listAllExpenses()
{
    system("cls");
    if (!expenses.empty())
    {
        cout << "             >>> EXPENSES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            listExpenseData(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "There is not any expense." << endl << endl;
    }
    system("pause");
}

//=============================================================

char TransferManager::chooseTheOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add Income" << endl;
    cout << "2. List all incomes" << endl; // Add Expense
    cout << "3. List all expenses" << endl; // Show current month balance
    cout << "4. Add expense" << endl; // Show previous month balance
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
/*
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

void TransferManager::editIncome()
{
    system("cls");
    int editIncomeId = 0;
    //int numerLiniiEdytowanegoAdresata = 0;

    cout << ">>> INCOME EDITION <<<" << endl << endl;
    editIncomeId = passChosenIncomeId();

    char choice;
    bool doesIncomeExist = false;
    string date;
    for (int i = 0; i < incomes.size(); i++)
    {
        if (incomes[i].getId() == editIncomeId)
        {
            doesIncomeExist = true;
            choice = chooseTheOptionFromEditMenu();

            switch (choice)
            {
            case '1':
                while (true)
                {
                    cout << "Type new date: ";
                    date = HelpingMethods::getTheLine();
                    if (dateOperations.isDateCorrect(date))
                        break;
                    cout << "Date has incorrect format. Please, type again." << endl;
                }
                incomes[i].setDate(date);
                //updateChosenIncomeData(incomes[i]); IncomesFile
                break;
            case '2':
                cout << "Type new item: ";
                incomes[i].setItem(HelpingMethods::changeFirstLetterToUpperRestToLower(HelpingMethods::getTheLine()));
                //updateChosenIncomeData(incomes[i]); IncomesFile
                break;
            case '3':
                cout << "Type new amount: ";
                incomes[i].setAmount(HelpingMethods::getTheLine());
                //updateChosenIncomeData(incomes[i]); IncomesFile
                break;
            case '4':
                cout << endl << "Return to the USER MENU" << endl << endl;
                break;
            default:
                cout << endl << "There is not option you want to choose in that menu! Returning to the USER MENU." << endl << endl;
                break;
            }
        }
    }
    if (doesIncomeExist == false)
    {
        cout << endl << "There is not income you want to get." << endl << endl;
    }
    system("pause");
}

char TransferManager::chooseTheOptionFromEditMenu()
{
    char choice;

    cout << endl << "   >>> EDIT MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Which data you want to update: " << endl;
    cout << "1 - Date" << endl;
    cout << "2 - Item" << endl;
    cout << "3 - Amount" << endl;
    cout << "4 - Return " << endl;
    cout << endl << "Your choice: ";
    choice = HelpingMethods::getTheChar();

    return choice;
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
