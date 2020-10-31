#include "ExpensesFile.h"

int ExpensesFile::getTheLastExpenseId()
{
    return lastExpenseId;
}

void ExpensesFile::setTheLastExpenseId(int id)
{
    lastExpenseId = id;
}

bool ExpensesFile::addExpenseToFile(Transfer expense)
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
    xml.AddElem("Date", dateOperations.transcriptDateFromIntToStringSplittedByACharacter(expense.getDate(), '-'));
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

vector<Transfer> ExpensesFile::loadExpensesFromFile(int loggedUserId)
{
    Transfer expense;
    vector<Transfer> expenses;
    int oneTransferUserId;

    xml.Load(EXPENSES_FILE_NAME);
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("Expense"))
    {
        lastExpenseId = atoi(getOneDataOfOneTransferFromFile("Id").c_str());
        oneTransferUserId = atoi(getOneDataOfOneTransferFromFile("UserId").c_str());
        if (oneTransferUserId == loggedUserId)
        {
            xml.ResetChildPos();
            expense.setId(lastExpenseId);
            expense.setUserId(oneTransferUserId);
            expense.setDate(dateOperations.transcriptDateSplittedByACharacterFromStringToInt(getOneDataOfOneTransferFromFile("Date"), '-'));
            expense.setItem(getOneDataOfOneTransferFromFile("Item"));
            expense.setAmount(getOneDataOfOneTransferFromFile("Amount"));

            expenses.push_back(expense);
        }
    }

    return expenses;
}

bool ExpensesFile::deleteOneExpenseInFileById(int deletedExpenseId)
{
    int oneTransferId;
    bool fileExists = xml.Load(EXPENSES_FILE_NAME);
    if (fileExists)
    {
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Expense"))
        {
            oneTransferId = atoi(getOneDataOfOneTransferFromFile("Id").c_str());
            if (oneTransferId == deletedExpenseId)
            {
                xml.RemoveElem();
            }
        }
        xml.Save(EXPENSES_FILE_NAME);
    }
    return fileExists;
}

void ExpensesFile::refreshLastExpenseIdAfterRemovingChosenExpense(int deletedExpenseId)
{
    if (deletedExpenseId == lastExpenseId)
        getLastExpenseIdFromFile();
}

void ExpensesFile::getLastExpenseIdFromFile()
{
    lastExpenseId = 0;

    bool fileExists = xml.Load(EXPENSES_FILE_NAME);
    if (fileExists)
    {
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Expense"))
        {
            lastExpenseId = atoi(getOneDataOfOneTransferFromFile("Id").c_str());
        }
    }
}

void ExpensesFile::editExpenseInFile(Transfer expense)
{
    int searchedExpenseId = expense.getId();
    int oneTransferId;
    bool fileExists = xml.Load(EXPENSES_FILE_NAME);
    if (fileExists)
    {
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Expense"))
        {
            oneTransferId = atoi(getOneDataOfOneTransferFromFile("Id").c_str());
            if (oneTransferId == searchedExpenseId)
            {
                removeAllInformationsAboutOneExpense();
                readdExpenseToFile(expense);
            }
        }
    }
    xml.Save(EXPENSES_FILE_NAME);
}

void ExpensesFile::removeAllInformationsAboutOneExpense()
{
    xml.ResetChildPos();
    while (xml.FindChildElem())
    {
        xml.RemoveChildElem();
    }
}

void ExpensesFile::readdExpenseToFile(Transfer expense)
{
    xml.IntoElem();
    xml.AddElem("Id", expense.getId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", dateOperations.transcriptDateFromIntToStringSplittedByACharacter(expense.getDate(), '-'));
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", expense.getAmount());
}
