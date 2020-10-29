#include "TransferManager.h"

// INCOMES ===========================================================

void TransferManager::addIncome()
{
    Transfer income;

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

Transfer TransferManager::passNewIncomeData()
{
    Transfer income;

    income.setId(incomesFile.getTheLastIncomeId() + 1);
    incomesFile.setTheLastIncomeId(incomesFile.getTheLastIncomeId() + 1);
    income.setUserId(LOGGED_USER_ID);

    while(true)
    {
        cout << "Do you want to add income with today (enter 'today') date or pass it manually (enter 'manual')?" << endl;
        string choice = HelpingMethods::getTheLine();
        if (choice == "today")
        {
            income.setDate(dateOperations.getPresentDateString());
            break;
        }
        else if (choice == "manual")
        {
            income.setDate(getDateFromUser());
            break;
        }
        else
        {
            cout << "Please choose the right option" << endl;
            system("pause");
            cout << endl;
        }

    }

    cout << "Write down item: ";
    income.setItem(HelpingMethods::getTheLine());
    income.setItem(HelpingMethods::changeFirstLetterToUpperRestToLower(income.getItem()));

    cout << "Write down amount: ";
    income.setAmount(HelpingMethods::getTheLine());

    return income;
}

void TransferManager::listIncomeData(Transfer income)
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
        cout << "             >>> INCOME(S) <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Transfer> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
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

void TransferManager::listIncomesBetweenProvidedDates(string providedDateFrom, string providedDateTo)
{
    if (!incomes.empty())
    {
        cout << endl << "             >>> INCOME(S) <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Transfer> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            if (dateOperations.isDateBetweenProvidedDates(providedDateFrom, providedDateTo, itr -> getDate()))
            {
                listIncomeData(*itr);
            }
        }
        cout << endl;
    }
    else
    {
        cout << endl << "There is not any income between provided dates." << endl << endl;
    }
}

void TransferManager::deleteIncome()
{
    int deletedIncomeId = 0;

    system("cls");
    cout << ">>> INCOME DELETING <<<" << endl << endl;
    deletedIncomeId = passChosenTransferId();

    char character;
    bool doesIncomeExist = false;

    for (vector <Transfer>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if (itr -> getId() == deletedIncomeId)
        {
            doesIncomeExist = true;
            cout << endl << "Confirm by typing 't': ";
            character = HelpingMethods::getTheChar();
            if (character == 't')
            {
                if (incomesFile.deleteOneIncomeInFileById(deletedIncomeId))
                {
                    incomes.erase(itr);
                    cout << endl << endl << "Searched income has been deleted." << endl << endl;
                    system("pause");
                    incomesFile.refreshLastIncomeIdAfterRemovingChosenIncome(deletedIncomeId);
                    return;
                }
                else
                {
                    cout << "File does not exist!" << endl;
                    return;
                }

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

void TransferManager::editIncome()
{
    system("cls");
    int editedIncomeId = 0;

    cout << ">>> INCOME EDITION <<<" << endl << endl;
    editedIncomeId = passChosenTransferId();

    char choice;
    bool doesIncomeExist = false;
    string date;
    for (int i = 0; i < incomes.size(); i++)
    {
        if (incomes[i].getId() == editedIncomeId)
        {
            doesIncomeExist = true;
            choice = chooseTheOptionFromEditMenu();

            switch (choice)
            {
            case '1':
                incomes[i].setDate(getDateFromUser());
                updateChosenIncomeData(incomes[i]);
                break;
            case '2':
                cout << "Type new item: ";
                incomes[i].setItem(HelpingMethods::changeFirstLetterToUpperRestToLower(HelpingMethods::getTheLine()));
                updateChosenIncomeData(incomes[i]);
                break;
            case '3':
                cout << "Type new amount: ";
                incomes[i].setAmount(HelpingMethods::getTheLine());
                updateChosenIncomeData(incomes[i]);
                break;
            case '0':
                cout << endl << "Returning to the USER MENU" << endl << endl;
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

void TransferManager::updateChosenIncomeData(Transfer income)
{
    incomesFile.editIncomeInFile(income);

    cout << endl << "Data has been updated." << endl << endl;
}

// EXPENSES ======================================================

void TransferManager::addExpense()
{
    Transfer expense;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    expense = passNewExpenseData();

    expenses.push_back(expense);

    if (expensesFile.addExpenseToFile(expense))
        cout << "New expense has been added successfully." << endl;
    else
        cout << "Error! We could not add new expense." << endl;

    system("pause");
}

Transfer TransferManager::passNewExpenseData()
{
    Transfer expense;

    expense.setId(expensesFile.getTheLastExpenseId() + 1);
    expensesFile.setTheLastExpenseId(expensesFile.getTheLastExpenseId() + 1);
    expense.setUserId(LOGGED_USER_ID);
    while(true)
    {
        cout << "Do you want to add expense with today (enter 'today') date or pass it manually (enter 'manual')?" << endl;
        string choice = HelpingMethods::getTheLine();
        if (choice == "today")
        {
            expense.setDate(dateOperations.getPresentDateString());
            break;
        }
        else if (choice == "manual")
        {
            expense.setDate(getDateFromUser());
            break;
        }
        else
        {
            cout << "Please choose the right option" << endl;
            system("pause");
        }

    }


    cout << "Write down item: ";
    expense.setItem(HelpingMethods::getTheLine());
    expense.setItem(HelpingMethods::changeFirstLetterToUpperRestToLower(expense.getItem()));

    cout << "Write down amount: ";
    expense.setAmount(HelpingMethods::getTheLine());

    return expense;
}

void TransferManager::listExpenseData(Transfer expense)
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
        cout << "             >>> EXPENSE(S) <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Transfer> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
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

void TransferManager::listExpensesBetweenProvidedDates(string providedDateFrom, string providedDateTo)
{
    if (!expenses.empty())
    {
        cout << endl << "             >>> EXPENSE(S) <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Transfer> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            if (dateOperations.isDateBetweenProvidedDates(providedDateFrom, providedDateTo, itr -> getDate()))
            {
                listExpenseData(*itr);
            }
        }
        cout << endl;
    }
    else
    {
        cout << endl << "There is not any expense between provided dates." << endl << endl;
    }
}

void TransferManager::deleteExpense()
{
    int deleteExpenseId = 0;

    system("cls");
    cout << ">>> EXPENSE DELETING <<<" << endl << endl;
    deleteExpenseId = passChosenTransferId();

    char character;
    bool doesExpenseExist = false;

    for (vector <Transfer>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        if (itr -> getId() == deleteExpenseId)
        {
            doesExpenseExist = true;
            cout << endl << "Confirm by typing 't': ";
            character = HelpingMethods::getTheChar();
            if (character == 't')
            {
                if (expensesFile.deleteOneExpenseInFileById(deleteExpenseId))
                {
                    expenses.erase(itr);
                    cout << endl << endl << "Searched expense has been deleted." << endl << endl;
                    system("pause");
                    expensesFile.refreshLastExpenseIdAfterRemovingChosenExpense(deleteExpenseId);
                    return;
                }
                else
                {
                    cout << "File does not exist!" << endl;
                    return;
                }

            }
            else
            {
                cout << endl << endl << "Chosen expense has not been deleted." << endl << endl;
                system("pause");
                return;
            }
        }
    }
    if (doesExpenseExist == false)
    {
        cout << endl << "There is no expense like this." << endl << endl;
        system("pause");
    }
    return;
}

void TransferManager::editExpense()
{
    system("cls");
    int editedExpenseId = 0;

    cout << ">>> EXPENSE EDITION <<<" << endl << endl;
    editedExpenseId = passChosenTransferId();

    char choice;
    bool doesExpenseExist = false;
    string date;
    for (int i = 0; i < expenses.size(); i++)
    {
        if (expenses[i].getId() == editedExpenseId)
        {
            doesExpenseExist = true;
            choice = chooseTheOptionFromEditMenu();

            switch (choice)
            {
            case '1':
                expenses[i].setDate(getDateFromUser());
                updateChosenExpenseData(expenses[i]);
                break;
            case '2':
                cout << "Type new item: ";
                expenses[i].setItem(HelpingMethods::changeFirstLetterToUpperRestToLower(HelpingMethods::getTheLine()));
                updateChosenExpenseData(expenses[i]);
                break;
            case '3':
                cout << "Type new amount: ";
                expenses[i].setAmount(HelpingMethods::getTheLine());
                updateChosenExpenseData(expenses[i]);
                break;
            case '0':
                cout << endl << "Returning to the USER MENU" << endl << endl;
                break;
            default:
                cout << endl << "There is not option you want to choose in that menu! Returning to the USER MENU." << endl << endl;
                break;
            }
        }
    }
    if (doesExpenseExist == false)
    {
        cout << endl << "There is not income you want to get." << endl << endl;
    }
    system("pause");
}

void TransferManager::updateChosenExpenseData(Transfer expense)
{
    expensesFile.editExpenseInFile(expense);

    cout << endl << "Data has been updated." << endl << endl;
}

//=============================================================

void TransferManager::editOrDeleteTransfer()
{
    char choice = chooseTheOptionEditDeleteMenu();
    switch (choice)
    {
    case '1':
        editIncome();
        break;
    case '2':
        editExpense();
        break;
    case '3':
        deleteIncome();
        break;
    case '4':
        deleteExpense();
        break;
    case '0':
        cout << endl << "Returning to the USER MENU" << endl << endl;
        break;
    default:
        cout << endl << "There is not option you want to choose in that menu! Returning to the USER MENU." << endl << endl;
        break;
    }
}

string TransferManager::getDateFromUser()
{
    string date = "";
    while (true)
    {
        cout << "Write down date: ";
        date = HelpingMethods::getTheLine();
        if (dateOperations.isDateCorrect(date))
            break;
        cout << "Date has incorrect format. Please, type again." << endl << endl;
    }
    return date;
}

char TransferManager::chooseTheOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl; // Add Expense
    cout << "3. Present month balance" << endl; // Show current month balance
    cout << "4. Previous month balance" << endl; // Show previous month balance
    cout << "5. Balance of provided period" << endl;
    cout << "6. Editing & Deleting" << endl;
    cout << "---------------------------" << endl;
    cout << "9. Change password" << endl;
    cout << "0. Log Out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your Choice: ";
    choice = HelpingMethods::getTheChar();

    return choice;
}

char TransferManager::chooseTheOptionEditDeleteMenu()
{
    char choice;

    system("cls");
    cout << " >>> EDIT & DELETE MENU <<<" << endl;
    cout << "------------------------------" << endl;
    cout << "1. Edit income" << endl;
    cout << "2. Edit expense" << endl;
    cout << "3. Delete income" << endl;
    cout << "4. Delete expense" << endl;
    cout << "------------------------------" << endl;
    cout << "0. Return" << endl;
    cout << "------------------------------" << endl;
    cout << "Your Choice: ";
    choice = HelpingMethods::getTheChar();

    return choice;
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
    cout << "---------------------------" << endl;
    cout << "0 - Return " << endl;
    cout << endl << "Your choice: ";
    choice = HelpingMethods::getTheChar();

    return choice;
}

int TransferManager::passChosenTransferId()
{
    int chosenTransferId = 0;
    cout << "Type income's ID number: ";
    chosenTransferId  = HelpingMethods::getTheInt();
    return chosenTransferId;
}

void TransferManager::listIncomesAndExpensesBetweenProvidedDateAndShowTheBalance()
{
    system("cls");

    cout << "Type date from." << endl;
    string providedDateFrom = getDateFromUser();

    cout << "Type date to." << endl;
    string providedDateTo = getDateFromUser();

    incomes = dateOperations.sortByDate(incomes);
    listIncomesBetweenProvidedDates(providedDateFrom, providedDateTo);
    expenses = dateOperations.sortByDate(expenses);
    listExpensesBetweenProvidedDates(providedDateFrom, providedDateTo);
    calculateBalance(providedDateFrom, providedDateTo);
    system("pause");
}

void TransferManager::listIncomesAndExpensesFromPresentMonthAndShowTheBalance()
{
    system("cls");

    string dateFrom = dateOperations.getTheDateOfTheFirstDayOfPresentMonthInString();
    string dateTo = dateOperations.getTheDateOfTheLastDayOfPresentMonthInString();

    incomes = dateOperations.sortByDate(incomes);
    listIncomesBetweenProvidedDates(dateFrom, dateTo);
    expenses = dateOperations.sortByDate(expenses);
    listExpensesBetweenProvidedDates(dateFrom, dateTo);
    calculateBalance(dateFrom, dateTo);
    system("pause");
}

void TransferManager::listIncomesAndExpensesFromPreviousMonthAndShowTheBalance()
{
    system("cls");

    string dateFrom = dateOperations.getTheDateOfTheFirstDayOfPreviousMonthInString();
    string dateTo = dateOperations.getTheDateOfTheLastDayOfPreviousMonthInString();

    incomes = dateOperations.sortByDate(incomes);
    listIncomesBetweenProvidedDates(dateFrom, dateTo);
    expenses = dateOperations.sortByDate(expenses);
    listExpensesBetweenProvidedDates(dateFrom, dateTo);
    calculateBalance(dateFrom, dateTo);
    system("pause");
}

void TransferManager::calculateBalance(string providedDateFrom, string providedDateTo)
{
    float incomesValue = 0;
    for (vector <Transfer>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if (dateOperations.isDateBetweenProvidedDates(providedDateFrom, providedDateTo, itr -> getDate()))
        incomesValue += atof((itr -> getAmount()).c_str());
    }

    float expensesValue = 0;
    for (vector <Transfer>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        if (dateOperations.isDateBetweenProvidedDates(providedDateFrom, providedDateTo, itr -> getDate()))
        expensesValue += atof((itr -> getAmount()).c_str());
    }

    float balance = incomesValue - expensesValue;

    cout << "Your balance from provided period: " << balance << endl << endl;
}
