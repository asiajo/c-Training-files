#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <vector>
#include <algorithm>
#include <functional>
#include <chrono>
#include <random>


class TicTacToe
{
    int compMove;
    char field[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    std::vector<int> given;

    int generateRandom();
    void checkMove(int f1, int f2, int f3);
public:
    void drawField();
    bool checkWin();
    void userMove();
    void computerMove();
    int getGivenSize();
};

#endif // TICTACTOE_H
