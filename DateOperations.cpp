#include "DateOperations.h"

void DateOperations::setPresentDateString()
{
    time_t now = time (0);
    tm *ltm = localtime(&now);

    string year = to_string(1900 + ltm->tm_year);
    string month = to_string(ltm->tm_mon + 1);
    string monthday = to_string(ltm->tm_mday);

    presentDateString = year + "-" + month + "-" + monthday;
}

string DateOperations::getPresentDateString()
{
    return presentDateString;
}

void DateOperations::setPresentDateInt()
{
    presentDateInt = transcriptDateSplittedByACharacterFromStringToInt(presentDateString, '-');
}

bool DateOperations::isALeapYear(int year)
{
    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int DateOperations::getDayFromDateInt(int date)
{
    return date % 100;
}

int DateOperations::getMonthFromDateInt(int date)
{
    date /= 100;

    return date % 100;
}

int DateOperations::getYearFromDateInt(int date)
{
    return date / 10000;
}

int DateOperations::calculateAppropriateDaysQuantityInMonth(int date)
{
    int monthNumber = getMonthFromDateInt(date);
    int yearNumber = getYearFromDateInt(date);

    if (monthNumber < 8)
    {
        if (monthNumber == 2)
        {
            if (isALeapYear(yearNumber))   return 29;
            else                    return 28;
        }
        else if (monthNumber % 2 == 1) return 31;
        else                            return 30;
    }
    else if (8 <= monthNumber)
    {
        if (monthNumber % 2 == 1)  return 30;
        else                        return 31;
    }
}

int DateOperations::transcriptDateSplittedByACharacterFromStringToInt(string dateTextLineWithSeparator, char splittingCharacter)
{
    string dateTextLineWithoutSeparator = "";

    int characterPosition = 0;
    char character = dateTextLineWithSeparator[characterPosition];
    int textLineLength = dateTextLineWithSeparator.length();

    while (characterPosition < textLineLength)
    {
        if (character == splittingCharacter)
        {
            characterPosition++;
            if (characterPosition != textLineLength)
                character = dateTextLineWithSeparator[characterPosition];
        }
        dateTextLineWithoutSeparator += character;
        //character = '#0';
        characterPosition++;
        if (character != textLineLength)
            character = dateTextLineWithSeparator[characterPosition];
    }
    int dateInt = atoi(dateTextLineWithoutSeparator.c_str());

    return dateInt;
}

bool DateOperations::isDateBetweenProvidedDates(string dateFromInString, string dateToInString, string dateFromFileInString)
{
    int dateFromInInt = transcriptDateSplittedByACharacterFromStringToInt(dateFromInString, '-');
    int dateToInInt = transcriptDateSplittedByACharacterFromStringToInt(dateToInString, '-');
    int dateFromFileInInt = transcriptDateSplittedByACharacterFromStringToInt(dateFromFileInString, '-');

    if ((dateFromInInt <= dateFromFileInInt) && (dateFromFileInInt <= dateToInInt))
        return true;

    return false;
}

bool DateOperations::isDateCorrect(string dateInString)
{
    int dateInInt = transcriptDateSplittedByACharacterFromStringToInt(dateInString, '-');
    int day = getDayFromDateInt(dateInInt);
    int month = getMonthFromDateInt(dateInInt);

    if ((1 <= month) && (month <= 12))
    {
        if ((1 <= day) && (day <= calculateAppropriateDaysQuantityInMonth(dateInInt)))
            {
                return true;
            }
        else
            false;
    }
    else
        return false;
}

bool DateOperations::isPreviousMonthZero()
{
    if((getMonthFromDateInt(presentDateInt) - 1) % 100 == 0)
        return true;
    else
        return false;
}

bool DateOperations::isDateFromFileInProvidedMonth(string dateFromFileInString, string presentOrPreviousMonth = "present")
{
    int dateFromInInt;
    int dateToInInt;
    int dateFromFileInInt = transcriptDateSplittedByACharacterFromStringToInt(dateFromFileInString, '-');
    if (presentOrPreviousMonth == "present")
    {
        dateFromInInt = presentDateInt/100 * 100 + 1;
        dateToInInt = presentDateInt/100 * 100 + calculateAppropriateDaysQuantityInMonth(presentDateInt);
    }
    else
    {
        if(isPreviousMonthZero())
        {
            dateFromInInt = (presentDateInt/100 - 89) * 100 + 1;
            dateToInInt = (presentDateInt/100 - 89) * 100 + calculateAppropriateDaysQuantityInMonth(presentDateInt);
        }
        else
            dateFromInInt = (presentDateInt/100 - 1) * 100 + 1;
            dateToInInt = (presentDateInt/100 - 1) * 100 + calculateAppropriateDaysQuantityInMonth(presentDateInt);
    }

    if ((dateFromInInt <= dateFromFileInInt) && (dateFromFileInInt <= dateToInInt))
        return true;

    return false;
}
