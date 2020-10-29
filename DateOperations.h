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
    vector<Transfer> quickSort(vector<Transfer> transfers, int left, int right);

public:
    DateOperations()
    {
        setPresentDateString();
        setPresentDateInt();
    };
    bool isDateCorrect(int date);
    bool isDateBetweenProvidedDates(int dateFromInString, int dateToInString, int dateFromFileInString);
    string getPresentDateString();
    int getPresentDateInt();
    int getTheDateOfTheFirstDayOfPresentMonthInString();
    int getTheDateOfTheLastDayOfPresentMonthInString();
    int getTheDateOfTheFirstDayOfPreviousMonthInString();
    int getTheDateOfTheLastDayOfPreviousMonthInString();
    vector<Transfer> sortByDate(vector<Transfer> transfers);

    int transcriptDateSplittedByACharacterFromStringToInt(string dateTextLineWithSeparator, char splittingCharacter);
    string transcriptDateFromIntToStringSplittedByACharacter(int dateInt, char splittingCharacter);

};

#endif // DATE_OPERATIONS_H
