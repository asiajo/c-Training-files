#include <iostream>
#include <algorithm>
#include <string>

int palindrome_check(const std::string &s)
{
    std::string scp = s;
    if(scp.size()==0)
        return 0;
    std::transform(std::begin(scp), std::end(scp), std::begin(scp), ::tolower);
    scp.erase(remove_if(std::begin(scp), std::end(scp), ::isspace), std::end(scp));
    std::string rscp = scp;
    reverse(rscp.rbegin(), rscp.rend());
    return rscp == scp ? scp.size() : 0;
}

int longest_palindrome(const std::string &s)
{
    int palMax = 0;
    for(unsigned int i=0; i<s.size(); i++)
        for(unsigned int j=1; j<s.size()+1; j++)
            palMax = std::max(palMax, palindrome_check(s.substr(i,j)));
    return palMax;
}

int main()
{
    std::string s{"ohRot ator La lala"};
    std::cout << "Longest palindrome in the given string has a length of: " << longest_palindrome(s) << std::endl;
    return 0;
}
