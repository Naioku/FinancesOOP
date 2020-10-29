#ifndef TRANSFER_H
#define TRANSFER_H

#include <iostream>

using namespace std;

class Transfer
{
    int id;
    int userId;
    int date;
    string item;
    string amount;

public:
    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    int getId();
    int getUserId();
    int getDate();
    string getItem();
    string getAmount();
};

#endif // TRANSFER_H
