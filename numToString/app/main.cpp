#include <iostream>

#include "../include/numToString.hpp"

int main(int argc, char* argv[])
{
    utils::NumToString nts;
    int number;
    std::cout << "Give the number you would like to convert to words: " << std::endl;
    std::cin >> number;
    std::cout << nts.getWord(number) << std::endl;
    return 0;
}
