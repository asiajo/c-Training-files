#include "calculator.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string rpn{"2 7 + 3 / 14 3 - 4 * + 2 /"};
    Calculator c(15.0);
    double result1 = c.Add(15).Divide(2).GetResult();
    double result2 = c.calculateRPN(rpn);
    cout << "The result of calculation is: " << result1 << endl;
    cout << "The result of RPN expression: \"" << rpn << "\" is: " <<   result2 << endl;
    return 0;
}

