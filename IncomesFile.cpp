#include "IncomesFile.h"

int IncomesFile::getTheLastIncomeId()
{
    return lastIncomeId;
}

void IncomesFile::setTheLastIncomeId(int id)
{
    lastIncomeId = id;
}

bool IncomesFile::addIncomeToFile(Transfer income)
{
    bool fileExists = xml.Load(INCOMES_FILE_NAME);
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("Id", income.getId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", dateOperations.transcriptDateFromIntToStringSplittedByACharacter(income.getDate(), '-'));
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", income.getAmount());

    xml.Save(INCOMES_FILE_NAME);
    return true;
}

string IncomesFile::getOneDataOfOneTransferFromFile(string data_type)
{
    xml.FindChildElem(data_type);
    return xml.GetChildData();
}

vector<Transfer> IncomesFile::loadIncomesFromFile(int loggedUserId)
{
    Transfer income;
    vector<Transfer> incomes;
    int oneTransferUserId;

    xml.Load(INCOMES_FILE_NAME);
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("Income"))
    {
        lastIncomeId = atoi(getOneDataOfOneTransferFromFile("Id").c_str());
        oneTransferUserId = atoi(getOneDataOfOneTransferFromFile("UserId").c_str());
        if (oneTransferUserId == loggedUserId)
        {
            xml.ResetChildPos();
            income.setId(lastIncomeId);
            income.setUserId(oneTransferUserId);
            income.setDate(dateOperations.transcriptDateSplittedByACharacterFromStringToInt(getOneDataOfOneTransferFromFile("Date"), '-'));
            income.setItem(getOneDataOfOneTransferFromFile("Item"));
            income.setAmount(getOneDataOfOneTransferFromFile("Amount"));

            incomes.push_back(income);
        }
    }

    return incomes;
}

bool IncomesFile::deleteOneIncomeInFileById(int deletedIncomeId)
{
    int oneTransferId;
    bool fileExists = xml.Load(INCOMES_FILE_NAME);
    if (fileExists)
    {
        xml.Load("incomes.xml");
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Income"))
        {
            oneTransferId = atoi(getOneDataOfOneTransferFromFile("Id").c_str());
            if (oneTransferId == deletedIncomeId)
            {
                xml.RemoveElem();
            }
        }
        xml.Save(INCOMES_FILE_NAME);
    }
    return fileExists;
}

void IncomesFile::refreshLastIncomeIdAfterRemovingChosenIncome(int deletedIncomeId)
{
    if (deletedIncomeId == lastIncomeId)
        getLastIncomeIdFromFile();
}

void IncomesFile::getLastIncomeIdFromFile()
{
    lastIncomeId = 0;

    bool fileExists = xml.Load(INCOMES_FILE_NAME);
    if (fileExists)
    {
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Income"))
        {
            lastIncomeId = atoi(getOneDataOfOneTransferFromFile("Id").c_str());
        }
    }
}

void IncomesFile::editIncomeInFile(Transfer income)
{
    int searchedIncomeId = income.getId();
    int oneTransferId;
    bool fileExists = xml.Load(INCOMES_FILE_NAME);
    if (fileExists)
    {
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Income"))
        {
            oneTransferId = atoi(getOneDataOfOneTransferFromFile("Id").c_str());
            if (oneTransferId == searchedIncomeId)
            {
                removeAllInformationsAboutOneIncome();
                readdIncomeToFile(income);
            }
        }
    }
    xml.Save(INCOMES_FILE_NAME);
}

void IncomesFile::removeAllInformationsAboutOneIncome()
{
    xml.ResetChildPos();
    while (xml.FindChildElem())
    {
        xml.RemoveChildElem();
    }
}

void IncomesFile::readdIncomeToFile(Transfer income)
{
    xml.IntoElem();
    xml.AddElem("Id", income.getId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", dateOperations.transcriptDateFromIntToStringSplittedByACharacter(income.getDate(), '-'));
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", income.getAmount());
}
