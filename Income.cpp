#include "Income.h"

void Income::setId(int newId)
{
    id = newId;
}

void Income::setUserId(int newUserId)
{
    userId = newUserId;
}

void Income::setDate(string newDate)
{
    date = newDate;
}

void Income::setItem(string newItem)
{
    item = newItem;
}

void Income::setAmount(string newAmount)
{
    amount = newAmount;
}


int Income::getId()
{
    return id;
}

int Income::getUserId()
{
    return userId;
}

string Income::getDate()
{
    return date;
}

string Income::getItem()
{
    return item;
}

string Income::getAmount()
{
    return amount;
}
