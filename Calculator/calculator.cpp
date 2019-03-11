#include "calculator.h"

Calculator::Calculator(double res)
{
    result = res;
}
Calculator& Calculator::Add(double a)
{
    result = Add(result, a);
    return *this;
}
Calculator&  Calculator::Substract(double a)
{
    result = Substract(result, a);
    return *this;
}
Calculator&  Calculator::Multiply(double a)
{
    result = Multiply(result, a);
    return *this;
}
Calculator& Calculator::Divide(double a)
{
    result = Divide(result, a);
    return *this;
}
double Calculator::Add(double a, double b)
{
    return a+b;
}
double Calculator::Substract(double a, double b)
{
    return a-b;
}
double Calculator::Multiply(double a, double b)
{
    return a*b;
}
double Calculator::Divide(double a, double b)
{
    if(b != 0)
    {
        return a/b;
    }
    else
    {
        return 0;
    }
}
void Calculator::calculate(char a, double num)
{
    switch(a)
    {
    case '+':
        Add(num);
        break;
    case '-':
        Substract(num);
        break;
    case '/':
        Divide(num);
        break;
    case '*':
        Multiply(num);
        break;
    }
}
double Calculator::GetResult()
{
    return result;
}

double Calculator::calculateRPN(string str)
{
    vector<string> strs;
    string tmp = "";
    string pom;
    for(unsigned int i=0; i < str.length(); i++ )
    {
        if (string(" +-*/").find(str[i])==string::npos)
            tmp += str[i];
        else if ((str[i]==' ')&& tmp.length()>0)
        {
            strs.push_back(tmp);
            tmp = "";
        }
        else if (str[i]!=' ')
        {
            pom=str[i];
            strs.push_back(pom);
        }
    }
    if (tmp.length()>0)
        strs.push_back(tmp);

    stack < double > numbers_stack;
    double number;
    double x, y;
    for (vector<string>::iterator it = strs.begin() ; it != strs.end(); ++it)
    {
        if (numbers_stack.size()>=2 && string("+-*/").find(*it)!=string::npos)
        {
            x = numbers_stack.top();
            numbers_stack.pop();
            y = numbers_stack.top();
            numbers_stack.pop();
            switch((*it)[0])
            {
            case '+':
                number = Add(y, x);
                break;
            case '-':
                number = Substract(y, x);
                break;
            case '*':
                number = Multiply(y, x);
                break;
            case '/':
                number = Divide(y, x);
                break;
            }
            numbers_stack.push(number);
        }
        else
        {
            try
            {
                number = stoi( *it );
                numbers_stack.push(number);
            }
            catch (invalid_argument)
            {
                cout << "Invalid input" << endl;
            }
        }
    }
    return numbers_stack.top();
}
