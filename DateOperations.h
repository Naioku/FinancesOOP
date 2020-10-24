#ifndef DATE_OPERATIONS_H
#define DATE_OPERATIONS_H

#include <iostream>
#include <ctime>
#include <vector>

#include "Income.h"

using namespace std;

class DateOperations
{
    int presentDateInt;
    string presentDateString;

    void setPresentDateInt();
    void setPresentDateString();
    bool isALeapYear(int year);
    int getDayFromDateInt(int date);
    int getMonthFromDateInt(int date);
    int getYearFromDateInt(int date);
    int calculateAppropriateDaysQuantityInMonth(int date);
    int transcriptDateSplittedByACharacterFromStringToInt(string dateTextLineWithSeparator, char splittingCharacter);
    bool isPreviousMonthZero();
    void quickSort(vector<Income> &transfers, int left, int right);

public:
    DateOperations()
    {
        setPresentDateInt();
        setPresentDateString();
    }
    bool isDateCorrect(string date);
    bool isDateBetweenProvidedDates(string dateFromInString, string dateToInString, string dateFromFileInString);
    bool isDateFromFileInProvidedMonth(string dateFromFileInString, string presentOrPreviousMonth);
    string getPresentDateString();
    vector<Income> sortByDate(vector<Income> transfers);

};

#endif // DATE_OPERATIONS_H
