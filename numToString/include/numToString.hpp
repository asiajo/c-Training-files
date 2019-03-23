#pragma once

#include <iosfwd>
#include <vector>
#include <string>
#include <math.h>
#include <iostream>
#include <fstream>
#include <algorithm>

namespace utils
{
    
class NumToString
{
    std::vector<std::string> singles {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::vector<std::string> teens {"ten", "eleven", "twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    std::vector<std::string> tens {"","", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    std::vector<std::string> bigs {" quadrillion"," trillion", " billion", " million", " thousand", ""};
    std::string getThree(int num) const;
public:

    std::string getWord(unsigned long long num) const;

};
    
} // namespace utils

