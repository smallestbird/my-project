// yesnt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int input();
void board(char tictactoe[3][3]);
int is_move_valid(char tictactoe[3][3], int row, int col);
int winner(char tictactoe[3][3]);

int main() {
    printf("Tic Tac Toe! X starts\n");
    char tictactoe[3][3];
    int x, y, row, col;
    int player = 1; 

    
    for (x = 0; x < 3; x++) 
    {
        for (y = 0; y < 3; y++) 
        {
            tictactoe[x][y] = '.';
        }
    }

    while (1) 
    {
        board(tictactoe);
        if (player == 1) 
        {
            printf("Player 1's turn. Enter row and column (0-2):\n ");
        }
        else 
        {
            printf("Player 2's turn. Enter row and column (0-2):\n ");
        }

        row = input();
        col = input();

        // Validate the move
        if (is_move_valid(tictactoe, row, col)) 
        {
            if (player == 1) 
            {
                tictactoe[row][col] = 'X';
                player = 2;
                
            }
            else 
            {
                tictactoe[row][col] = 'O';
                player = 1;
                
            }
        }
        else 
        {
            printf("Invalid move! Try again.\n");
        }

        if (winner(tictactoe) == 2)
        {
            board(tictactoe);
            printf("player 1 wins!");
            return(12);
        }
        else if (winner(tictactoe) == 3)
        {
            board(tictactoe);
            printf("player 2 wins!");
            return(13);
        }

    }

    return 0;
}

int input() 
{
    int a;
    scanf("%d", &a);
    while (a < 0 || a > 2) 
    {
        printf("Invalid input, please enter a number between 0 and 2: ");
        scanf("%d", &a);
    }
    return a;
}

void board(char tictactoe[3][3]) 
{
    int x, y;
    for (x = 0; x < 3; x++) 
    {
        for (y = 0; y < 3; y++) 
        {
            printf("%c ", tictactoe[x][y]);
        }
        putchar('\n');
    }
}

int is_move_valid(char tictactoe[3][3], int row, int col) 
{
    if (tictactoe[row][col] == '.') 
    {
        return 1;
    }
    return 0;
}

int winner(char tictactoe[3][3]) 
{
    if (tictactoe[0][0] == 'X' && tictactoe[0][1] == 'X' && tictactoe[0][2] == 'X') 
    {
        return 2;
    }
    else if (tictactoe[1][0] == 'X' && tictactoe[1][1] == 'X' && tictactoe[1][2] == 'X') 
    {
        return 2;
    }
    else if (tictactoe[2][0] == 'X' && tictactoe[2][1] == 'X' && tictactoe[2][2] == 'X')
    {
        return 2;
    }
    else if (tictactoe[0][0] == 'X' && tictactoe[1][0] == 'X' && tictactoe[2][0] == 'X')
    {
        return 2;
    }
    else if (tictactoe[0][1] == 'X' && tictactoe[1][1] == 'X' && tictactoe[2][1] == 'X')
    {
        return 2;
    }
    else if (tictactoe[0][2] == 'X' && tictactoe[1][2] == 'X' && tictactoe[2][2] == 'X')
    {
        return 2;
    }
    else if (tictactoe[0][0] == 'X' && tictactoe[1][1] == 'X' && tictactoe[2][2] == 'X')
    {
        return 2;
    }
    else if (tictactoe[0][2] == 'X' && tictactoe[1][1] == 'X' && tictactoe[2][0] == 'X')
    {
        return 2;
    }






    if (tictactoe[0][0] == 'O' && tictactoe[0][1] == 'O' && tictactoe[0][2] == 'O')
    {
       return 3;
    }
    else if (tictactoe[1][0] == 'O' && tictactoe[1][1] == 'O' && tictactoe[1][2] == 'O')
    {
        return 3;
    }
    else if (tictactoe[2][0] == 'O' && tictactoe[2][1] == 'O' && tictactoe[2][2] == 'O')
    {   
        return 3;
    }
    else if (tictactoe[0][0] == 'O' && tictactoe[1][0] == 'O' && tictactoe[2][0] == 'O')
    {
        return 3;
    }
    else if (tictactoe[0][1] == 'O' && tictactoe[1][1] == 'O' && tictactoe[2][1] == 'O')
    {
        return 3;
    }
    else if (tictactoe[0][2] == 'O' && tictactoe[1][2] == 'O' && tictactoe[2][2] == 'O')
    {
        return 3;
    }
    else if (tictactoe[0][0] == 'O' && tictactoe[1][1] == 'O' && tictactoe[2][2] == 'O')
    {
        return 3;
    }
    else if (tictactoe[0][2] == 'O' && tictactoe[1][1] == 'O' && tictactoe[2][0] == 'O')
    {
        return 3;
    }
    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file