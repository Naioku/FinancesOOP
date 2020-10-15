#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    int id;
    int userId;
    string date;
    string item;
    string amount;

public:
    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    int getId();
    int getUserId();
    string getDate();
    string getItem();
    string getAmount();
};

#endif // INCOME_H
