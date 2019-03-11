#include "include/TicTacToe.h"
#include <iostream>
#include <cstdlib>


int main()
{
    TicTacToe ttt;
    std::string lastMoved;

    ttt.drawField();
    std::cout << "You are O. Where do you want to put your first move? \n" << std::endl;

    while (true)
    {
        if (ttt.getGivenSize() != 9 && !ttt.checkWin())
        {
            ttt.userMove();
            lastMoved = "\nYou";
        }
        else
            break;
        if (ttt.getGivenSize() != 9 && !ttt.checkWin())
        {
            ttt.computerMove();
            lastMoved = "\nComputer";
        }
        else
            break;
    }

    if (ttt.checkWin())
        std::cout<< lastMoved << " won!\n" << std::endl;
    else
        std::cout << "\nIt's a draw!\n" <<std::endl;

    return 0;
}
