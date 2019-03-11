#include "../include/TicTacToe.h"
#include <iostream>

using namespace std;

/** draw game field. */
void TicTacToe::drawField ()
{

    cout << "     |     |     " << endl;
    cout << "  " << field[0] << "  |  " << field[1] << "  |  " << field[2] << "  " << endl;
    cout << "     |     |     " << endl;
    cout << "-----------------" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << field[3] << "  |  " << field[4] << "  |  " << field[5] << "  " << endl;
    cout << "     |     |     " << endl;
    cout << "-----------------" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << field[6] << "  |  " << field[7] << "  |  " << field[8] << "  " << endl;
    cout << "     |     |     " << endl;

}

/** gets the move from the user */
void TicTacToe::userMove()
{
    int input;
    cout << "\nYour next move: ";
    cin >> input;
    --input;
    vector<int> v{0,1,2,3,4,5,6,7,8};

    if ((find (v.begin(), v.end(), input) != given.end() ) && (find (given.begin(), given.end(), input) == given.end() ) )
    {
        field[input] = 'O';
        drawField ();
        given.push_back (input);
    }
    else
    {
        cout << "This is not a valid move. Try again. ";
        userMove();
    }
    return;
}

/** generates random move of a computer. */
int TicTacToe::generateRandom()
{
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    uniform_int_distribution<std::mt19937::result_type> dist(0,8);
    int compMove = dist(gen);
    if (!(find (given.begin(), given.end(), compMove) == given.end() ) )
        compMove = generateRandom();
    return compMove;
}

/** simulate at least a little bit computer's intelligence. */
void TicTacToe::checkMove(int f1, int f2, int f3)
{
    if((field[f1]==field[f2]) && (find (given.begin(), given.end(), f3) == given.end()))
    {
        if (compMove<0)
            compMove = f3;
        else if(field[f1] == 'X')
            compMove = f3;
    }
    return;
}

/** makes computer move */
void TicTacToe::computerMove()
{
    compMove = -1;
    vector<vector<int>> moves{{1, 2, 0},{3, 6, 0},{4, 8, 0},{0, 1, 2},{4, 6, 2},{5, 8, 2},{7, 8, 6},{0, 3, 6},{0, 3, 6},{2, 4, 6},{6, 7, 8},
        {2, 5, 8},{0, 4, 8},{3, 5, 4},{1, 7, 4},{0, 8, 4},{2, 6, 4},{0, 2, 1},{4, 7, 1},{4, 5, 3},{0, 6, 3},{3, 6, 5},{2, 8, 5},{6, 8, 7},{1, 4, 7}};
    for(unsigned int i = 0; i<moves.size(); i++)
        checkMove(moves[i][0], moves[i][1], moves[i][2]);
    if (compMove<0)
        compMove = generateRandom();
    field[compMove] = 'X';
    cout << "\nComputer move is: " << compMove+1 <<endl;
    drawField();
    given.push_back(compMove);
    return;
}

/** checks if the game was won. */
bool TicTacToe::checkWin()
{
    return ((field[0]==field[1] && field[1] == field[2]) ||
            (field[3]==field[4] && field[4] == field[5]) ||
            (field[6]==field[7] && field[7] == field[8]) ||
            (field[0]==field[3] && field[3] == field[6]) ||
            (field[1]==field[4] && field[4] == field[7]) ||
            (field[2]==field[5] && field[5] == field[8]) ||
            (field[0]==field[4] && field[4] == field[8]) ||
            (field[2]==field[4] && field[4] == field[6])) ? true : false;
}

/** returns size of a vector. */
int TicTacToe::getGivenSize()
{
    return given.size();
}
