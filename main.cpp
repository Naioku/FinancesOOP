#include <iostream>

using namespace std;


int main()
{
    cout << "Ok." endl;

    return 0;
}

// TEST DATE_OPERATIONS
#include "DateOperations.h"

int dateOperations_main()
{
    DateOperations dateOperations;

    cout << dateOperations.isDateCorrect("2000-03-");
    return 0;
}
