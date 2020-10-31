#ifndef HELPING_METHODS_H
#define HELPING_METHODS_H

#include <iostream>
#include <algorithm>
#include <sstream>



using namespace std;

class HelpingMethods
{
public:
    static string getTheLine();
    static char getTheChar();
    static int getTheInt();
    static string changeFirstLetterToUpperRestToLower(string text);
    static string truncStringfloatToTwoDigitsAfterPoint(string number);
    static float round(float var);
    static string changeCommaToPoint(string number);
};

#endif // HELPING_METHODS_H
