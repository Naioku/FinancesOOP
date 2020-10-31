#include <iostream>

#include "Finances.h"

using namespace std;


int main()
{
    Finances finances("users.xml", "incomes.xml", "expenses.xml");
    int choice;
    while (true)
    {
        if (finances.getIdLoggedInUser() == 0)
        {
            choice = finances.chooseTheOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                finances.userLogIn();
                break;
            case '2':
                finances.userRegistration();
                break;
            case '0':
                exit(0);
                break;
            default:
                cout << endl << "There is no option you want to use." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = finances.chooseTheOptionFromUserMenu();

            switch (choice)
            {
            case '1':
                finances.addIncome();
                break;
            case '2':
                finances.addExpense();
                break;
            case '3':
                finances.listIncomesAndExpensesFromPresentMonthAndShowTheBalance();
                break;
            case '4':
                finances.listIncomesAndExpensesFromPreviousMonthAndShowTheBalance();
                break;
            case '5':
                finances.listIncomesAndExpensesBetweenProvidedDateAndShowTheBalance();
                break;
            case '6':
                finances.editOrDeleteTransfer();
                break;
            case '9':
                finances.changeLoggedInUserPassword();
                break;
            case '0':
                finances.userLogOut();
                break;
            default:
                cout << endl << "There is no option you want to use." << endl << endl;
                system("pause");
                break;
            }
        }
    }

    return 0;
}
/*
// TEST DATE_OPERATIONS
#include "DateOperations.h"

int dateOperations_main()
{
    DateOperations dateOperations;

    cout << dateOperations.getPresentDateString();
    return 0;
}

// TEST USER_MANAGER
#include "UserManager.h"

int UserManager_main()
{
    UserManager userManager("users.xml");
    char choice;

    while (true)
    {

        if (userManager.getIdLoggedInUser() == 0)
        {
            choice = userManager.chooseTheOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                userManager.userRegistration();
                break;
            case '2':
                userManager.userLogIn();
                break;
            case '3':
                userManager.listAllOfUsers();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no option you want to use." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            userManager.userLogOut();
        }
    }
    //userManager.userRegistration();


    //userManager.userLogIn();
    //cout << "Id: " << userManager.idLoggedInUser << endl;

    return 0;
}

// TEST TRANSFER_MANAGER
#include "TransferManager.h"

int TransferManager_main()
{
    TransferManager transferManager("incomes.xml", "expenses.xml", 1);
    char choice;

    while (true)
    {
        choice = transferManager.chooseTheOptionFromUserMenu();

        switch (choice)
        {
        case '1':
            transferManager.addIncome();
            break;
        case '2':
            transferManager.addExpense();
            break;
        case '3':
            transferManager.listIncomesAndExpensesFromPresentMonthAndShowTheBalance();
            break;
        case '4':
            transferManager.listIncomesAndExpensesFromPreviousMonthAndShowTheBalance();
            break;
        case '5':
            transferManager.listIncomesAndExpensesBetweenProvidedDateAndShowTheBalance();
            break;
        case '6':
            transferManager.editOrDeleteTransfer();
            break;
        case '0':
            exit(0);
            break;
        default:
            cout << endl << "There is no option you want to use." << endl << endl;
            system("pause");
            break;
        }
    }
    //userManager.userRegistration();


    //userManager.userLogIn();
    //cout << "Id: " << userManager.idLoggedInUser << endl;

    return 0;
}
*/
