#include "Finances.h"

void Finances::userRegistration()
{
    userManager.userRegistration();
}

void Finances::userLogIn()
{
    userManager.userLogIn();
    if(userManager.doesUserLoggedIn())
    {
        transferManager = new TransferManager(INCOMES_FILE_NAME, EXPENSES_FILE_NAME, userManager.getIdLoggedInUser(), userManager.getNameLoggedInUser(), userManager.getSurnameLoggedInUser());
    }
}

void Finances::userLogOut()
{
    userManager.userLogOut();
    delete transferManager;
    transferManager = NULL;
}

int Finances::getIdLoggedInUser()
{
    return userManager.getIdLoggedInUser();
}

void Finances::changeLoggedInUserPassword()
{
    userManager.changeLoggedInUserPassword();
}

void Finances::addIncome()
{
    if(userManager.doesUserLoggedIn())
    {
        transferManager->addIncome();
    }
    else
    {
        cout << "To add new income, you must be logged in." << endl;
        system("pause");
    }
}

void Finances::addExpense()
{
    if(userManager.doesUserLoggedIn())
    {
        transferManager->addExpense();
    }
    else
    {
        cout << "To add new expense, you must be logged in." << endl;
        system("pause");
    }
}

void Finances::editOrDeleteTransfer()
{
    if(userManager.doesUserLoggedIn())
    {
        transferManager->editOrDeleteTransfer();
    }
    else
    {
        cout << "To edit income or expense, you must be logged in." << endl;
        system("pause");
    }
}

void Finances::listIncomesAndExpensesBetweenProvidedDateAndShowTheBalance()
{
    if(userManager.doesUserLoggedIn())
    {
        transferManager->listIncomesAndExpensesBetweenProvidedDateAndShowTheBalance();
    }
    else
    {
        cout << "To list income or expense, you must be logged in." << endl;
        system("pause");
    }
}
void Finances::listIncomesAndExpensesFromPresentMonthAndShowTheBalance()
{
    if(userManager.doesUserLoggedIn())
    {
        transferManager->listIncomesAndExpensesFromPresentMonthAndShowTheBalance();
    }
    else
    {
        cout << "To list income or expense, you must be logged in." << endl;
        system("pause");
    }
}
void Finances::listIncomesAndExpensesFromPreviousMonthAndShowTheBalance()
{
    if(userManager.doesUserLoggedIn())
    {
        transferManager->listIncomesAndExpensesFromPreviousMonthAndShowTheBalance();
    }
    else
    {
        cout << "To list income or expense, you must be logged in." << endl;
        system("pause");
    }
}

char Finances::chooseTheOptionFromMainMenu()
{
    return userManager.chooseTheOptionFromMainMenu();
}

char Finances::chooseTheOptionFromUserMenu()
{
    return transferManager->chooseTheOptionFromUserMenu();
}
