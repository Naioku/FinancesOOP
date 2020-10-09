#include <iostream>
#include <ctime>

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

public:
    DateOperations()
    {
        setPresentDateInt();
        setPresentDateString();
    }
    bool isDateCorrect(string date);
    bool isDateBetweenProvidedDates(string dateFromInString, string dateToInString, string dateFromFileInString);
    bool isDateFromFileInProvidedMonth(string dateFromFileInString, string presentOrPreviousMonth);

};
