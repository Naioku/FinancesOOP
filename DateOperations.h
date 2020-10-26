#ifndef DATE_OPERATIONS_H
#define DATE_OPERATIONS_H

#include <iostream>
#include <ctime>
#include <vector>

#include "Transfer.h"

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
    string transcriptDateFromIndToStringSplittedByACharacter(int dateInt, char splittingCharacter);
    bool isPreviousMonthZero();
    void quickSort(vector<Transfer> &transfers, int left, int right);

public:
    DateOperations()
    {
        setPresentDateString();
        setPresentDateInt();
    };
    bool isDateCorrect(string date);
    bool isDateBetweenProvidedDates(string dateFromInString, string dateToInString, string dateFromFileInString);
    bool isDateFromFileInProvidedMonth(string dateFromFileInString, string presentOrPreviousMonth);
    string getPresentDateString();
    string getTheDateOfTheFirstDayOfPresentMonthInString();
    string getTheDateOfTheLastDayOfPresentMonthInString();
    string getTheDateOfTheFirstDayOfPreviousMonthInString();
    string getTheDateOfTheLastDayOfPreviousMonthInString();
    vector<Transfer> sortByDate(vector<Transfer> transfers);

};

#endif // DATE_OPERATIONS_H
