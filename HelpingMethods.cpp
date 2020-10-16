#include "HelpingMethods.h"

string HelpingMethods::getTheLine()
{
    string wejscie = "";
    getline(cin, wejscie);

    return wejscie;
}

char HelpingMethods::getTheChar()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "This is not a character. Please, try again." << endl;
    }
    return character;
}

string HelpingMethods::changeFirstLetterToUpperRestToLower(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int HelpingMethods::getTheInt()
{
    string input = "";
    int number = 0;

    while (true)
    {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "This is not a number. Please, type again: " << endl;
    }
    return number;
}

