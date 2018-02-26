/* Carter Wahl // INFO 450-001 // Assignment #2 //
 This is a program that builds a game where the user guesses
 where the gold is hidden on an 8x8 gameboard.*/

#include "stdafx.h"
#include <iostream>

using namespace std;

#define Size 8

void initBoard(char gameBoard[Size][Size]);
void printBoard(char gameboard[Size][Size]);

int main()
{
    char gameBoard[Size][Size] = { 0 };
    char answer;
    /*declares the gameboard to be used for the game*/
    do
    {
        cout << "   1   2   3   4   5   6   7   8" << endl;
        for (int x = 0; x < Size; x++)
        {
            cout << x + 1 << '|' << " ";
            for (int y = 0; y < Size; y++)
            {
                cout << '?' << " | ";
            }
            cout << endl;
        }
        cout << endl;
        cout << "**********************************" << endl;
        cout << "***         Find Gold!         ***" << endl;
        cout << "***     You have 5 Guesses,    ***" << endl;
        cout << "***      5 pieces of Gold      ***" << endl;
        cout << "***         and 1 bomb         ***" << endl;
        cout << "***         Good Luck!         ***" << endl;
        cout << "***                            ***" << endl;
        cout << "**********************************" << endl;
        
        initBoard(gameBoard);
        cout << "Enter 'y' to play again: ";
        cin >> answer;
        cout << endl;
    } while ((answer == 'y') | (answer == 'Y'));
    /*a do while loop that allows the user to decide whether to
     play again or not. Here, initBoard is called and the game is
     started*/
    return 0;
}
void initBoard(char gameBoard[Size][Size])
{
    int bomb = 0;
    char x, y;
    int gold = 0;
    int guesses = 5;
    int points = 0;
    int yCoordinate;
    int xCoordinate;
    /*declaring variables to make the game work*/
    while (bomb = 0);
    {
        x = rand() % Size;
        y = rand() % Size;
        gameBoard[x][y] = 'B';
        bomb += 1;
    }
    /* a while loop that creates one bomb*/
    while (gold < 5)
    {
        do
        {
            x = rand() % Size;
            y = rand() % Size;
        } while (gameBoard[x][y] != 0);
        gameBoard[x][y] = 'G';
        gold++;
    }
    /*a while loop that creates 5 gold*/
    for (guesses; guesses > 0; guesses--)
    {
        cout << "Enter x coordinate: ";
        cin >> xCoordinate;
        cout << "Enter y coordinate: ";
        cin >> yCoordinate;
        if (gameBoard[(xCoordinate - 1)][(yCoordinate - 1)] == 'B')
        {
            cout << "Bomb! Game Over!" << endl;
            cout << endl;
            break;
        }
        else if (gameBoard[(xCoordinate - 1)][(yCoordinate - 1)] == 'G')
        {
            points++;
            guesses++;
            gameBoard[xCoordinate - 1][yCoordinate - 1] = 'F';
            cout << "You've found Gold! " << guesses - 1 << " more guesses!" << endl;
            cout << endl;
            
        }
        else
        {
            cout << "Too bad... You have " << guesses - 1 << " more guesses!" << endl;
            cout << endl;
        }
    }
    /*a for loop that allows the user to make 5 guesses (or more if they scores gold!) */
    cout << "You earned " << points << " points!" << endl;
    cout << "Better Luck Next Time!" << endl;
    cout << "Here's Your Board:" << endl;
    cout << "   1   2   3   4   5   6   7   8" << endl;
    
    printBoard(gameBoard);
    /*a call to print the board. the game is now completed. initBoard doubles as a function
     that initializes the board with 5 gold and a bomb, and the interface and rules for the game*/
    
}
void printBoard(char theArray[Size][Size])
{
    for (char x = 0; x < Size; x++)
    {
        cout << x + 1 << '|' << " ";
        for (char y = 0; y < Size; y++)
        {
            cout << theArray[x][y] << " | ";
        }
        cout << endl;
    }
}
/*printBoard is the final step in the game. after this, the game will ask the user if they want to
 play again.*/
