#include "../include/numToString.hpp"

namespace utils
{    
    
std::string NumToString::getWord(unsigned long long num) const
{
    std::string output;
    if (num == 0 && output.size() == 0) return singles.at(num);
    if (num >= pow(2,64)) return "Wrong input";
    int power = 15;
    int bigNum = 0;
    do
    {
        unsigned long long divisor = pow(10,power);
        output += getThree(num / divisor);
        if (num / divisor > 0)
        {
            output += bigs[bigNum];
            if (num / divisor > 1 && num >= 1000) output += "s";
            if (num % divisor > 0) output += " ";
        }
        num %= divisor;
        power -= 3;
        bigNum++;
    } while (num>=1);
     return output;
}

std::string NumToString::getThree(int num) const
{
    std::string output;
    if (num == 0) return "";
    if (num<10 && num > 0) return singles.at(num);
    if (num/100 >= 1)
    {
        output += singles[num/100];
        output += " hundred";
        if (num/100 > 1) output += "s";
        if (num%100 > 1) output += " and ";
    }
    if (num%100/10 > 1)
    {
        output += tens[num%100/10];
        if(num%10 != 0)
            output += "-" + singles.at(num%10);
    }
    else if (num%100/10 == 1) output += teens.at(num%10);
    return output;
}


    
} // namespace utils
