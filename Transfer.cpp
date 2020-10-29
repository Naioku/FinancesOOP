#include "Transfer.h"

void Transfer::setId(int newId)
{
    id = newId;
}

void Transfer::setUserId(int newUserId)
{
    userId = newUserId;
}

void Transfer::setDate(int newDate)
{
    date = newDate;
}

void Transfer::setItem(string newItem)
{
    item = newItem;
}

void Transfer::setAmount(string newAmount)
{
    amount = newAmount;
}


int Transfer::getId()
{
    return id;
}

int Transfer::getUserId()
{
    return userId;
}

int Transfer::getDate()
{
    return date;
}

string Transfer::getItem()
{
    return item;
}

string Transfer::getAmount()
{
    return amount;
}
