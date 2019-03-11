#include <string>
#include <iostream>
#include <cmath>

class DigPow
{
public:
    static int digPow(int n, int p)
    {
        std::string str = std::to_string(n);
        int summy = 0;
        for(int i = 0; i< str.size(); i++)
        {
            int num = str[i] - '0';
            summy += pow(num,(p+i));
        }
        return (summy/n)*n == summy ? summy/n : -1;
    }
};


int main()
{
    DigPow dp;
    std::cout << dp.digPow(46288, 3)<< std::endl;
    return 0;
}
