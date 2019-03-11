#ifndef CALCULATOR_H
#define CALCULATOR_H
#endif // CALCULATOR_H
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Calculator
{

private:
    double Add(double a, double b);
    double Substract(double a, double b);
    double Multiply(double a, double b);
    double Divide(double a, double b);

public:
    double result;

    Calculator(double res);

    Calculator& Add(double a);
    Calculator& Substract(double a);
    Calculator& Multiply(double a);
    Calculator& Divide(double a);

    void calculate(char a, double num);
    double GetResult();
    double calculateRPN(string a);

};
