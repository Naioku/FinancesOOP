#include "DateOperations.h"

void DateOperations::setPresentDateString()
{
    time_t now = time (0);
    tm *ltm = localtime(&now);

    string year = to_string(1900 + ltm->tm_year);
    int monthInt = ltm->tm_mon + 1;
    int monthdayInt = ltm->tm_mday;
    string month = HelpingMethods::changeIntToStringInDoubleDiditFormat(monthInt);
    string monthday = HelpingMethods::changeIntToStringInDoubleDiditFormat(monthdayInt);

    presentDateString = year + "-" + month + "-" + monthday;
}

string DateOperations::getPresentDateString()
{
    return presentDateString;
}

int DateOperations::getPresentDateInt()
{
    return presentDateInt;
}

int DateOperations::getTheDateOfTheFirstDayOfPresentMonthInString()
{
    return (presentDateInt / 100 * 100 + 1);
}

int DateOperations::getTheDateOfTheLastDayOfPresentMonthInString()
{
    return (presentDateInt / 100 * 100 + calculateAppropriateDaysQuantityInMonth(presentDateInt));
}

int DateOperations::getTheDateOfTheFirstDayOfPreviousMonthInString()
{
    return ((presentDateInt / 100 - 1)* 100 + 1);
}

int DateOperations::getTheDateOfTheLastDayOfPreviousMonthInString()
{
    return ((presentDateInt / 100 - 1) * 100 + calculateAppropriateDaysQuantityInMonth(presentDateInt));
}

string DateOperations::transcriptDateFromIntToStringSplittedByACharacter(int dateInt, char splittingCharacter)
{
    string year = to_string(dateInt/10000);
    int monthInt = (dateInt/100) % 100;
    int monthdayInt = dateInt % 100;
    string month = HelpingMethods::changeIntToStringInDoubleDiditFormat(monthInt);
    string monthday = HelpingMethods::changeIntToStringInDoubleDiditFormat(monthdayInt);

    string dateString = year + splittingCharacter + month + splittingCharacter + monthday;

    return dateString;
}

void DateOperations::setPresentDateInt()
{
    presentDateInt = transcriptDateSplittedByACharacterFromStringToInt(presentDateString, '-');
}

bool DateOperations::isALeapYear(int year)
{
    return ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) ? true : false;
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
            else                           return 28;
        }
        else if (monthNumber % 2 == 1) return 31;
        else                           return 30;
    }
    else if (8 <= monthNumber)
    {
        if (monthNumber % 2 == 1)  return 30;
        else                       return 31;
    }
}

string DateOperations::transcriptDateSplittedByACharacterFromStringToString(string dateTextLineWithSeparator, char splittingCharacter)
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

    return dateTextLineWithoutSeparator;
}

int DateOperations::transcriptDateSplittedByACharacterFromStringToInt(string dateTextLineWithSeparator, char splittingCharacter)
{
    return atoi(transcriptDateSplittedByACharacterFromStringToString(dateTextLineWithSeparator, splittingCharacter).c_str());
}

bool DateOperations::isDateBetweenProvidedDates(int dateFromInInt, int dateToInInt, int dateFromFileInInt)
{
    return ((dateFromInInt <= dateFromFileInInt) && (dateFromFileInInt <= dateToInInt)) ? true : false;
}

bool DateOperations::isDateCorrect(int dateInInt)
{
    int day = getDayFromDateInt(dateInInt);
    int month = getMonthFromDateInt(dateInInt);

    if ((1 <= month) && (month <= 12))
    {
        if ((1 <= day) && (day <= calculateAppropriateDaysQuantityInMonth(dateInInt)))
            {
                return true;
            }
    }

    return false;
}

bool DateOperations::checkDateFormat(string date)
{
    string dateWithoutSeparator = transcriptDateSplittedByACharacterFromStringToString(date, '-');

    return (dateWithoutSeparator.length() != 8) ? false : true;
}

vector<Transfer> DateOperations::quickSort(vector<Transfer> transfers, int left, int right)
{
    if(right <= left) return transfers;

	int i = left - 1, j = right + 1;
	Transfer pivot = transfers[(left+right)/2];

	while(true)
	{
		while(pivot.getDate() > transfers[++i].getDate());
		while(pivot.getDate() < transfers[--j].getDate());

		if( i <= j) swap(transfers[i],transfers[j]);
		else    	break;
	}

	if(j > left) return quickSort(transfers, left, j);
	if(i < right) return quickSort(transfers, i, right);
	return transfers;
}

vector<Transfer> DateOperations::sortByDate(vector<Transfer> transfers)
{
    int left = 0;
    int right = transfers.size() - 1;

    return quickSort(transfers, left, right);
}
