//
// Author:
//

//#include "reversi.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void printNewBoard(char board [][26], int n)
{
    int count = 0;
    printf("  "); //allignment
    while (count < n)
    {
        printf("%c", count+97); //prints 'a', then 'b' etc.
        if(count == n-1) //if its the last element print a new line for the grid spaces to start
        {
            printf("\n");
        }
        count++;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%c ", i+96);
        for (int j = 0; j < n; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    
}

int letterToInt (char letter) //converts a character to a number 
{
    int number;
    for (int i = 97; i <= 122; i++) //97 = 'a', 122 = 'z' in ASCII
    {
        if((int)letter == i) //converts charcter to ASCII value and sees if the current value we are checking matches
        {
            number = i - 97; //converts to friendlier number (a = 0, b = 1... z = 25)
        }
    }
    return number;
}

void printGamePartThrough (char board [][26], int n)
{
    int row, column;
    printf("Enter board configuration: ");
    char input [3], invalid[] = "!!!", black = 'B', white = 'W';
    do
    {
        scanf("%s", input);
        row = letterToInt(input[1]);
        column = letterToInt(input[2]);
        if(input[0] == 'B') //if the colour is black
        {
            board[row][column] = black;
        }
        else if(input[0] == 'W') //if the colour is white
        {
            board[row][column] = white;
        }
    } while (strcmp(input, invalid) != 0);

    printNewBoard(board, n);
}

void printBoard(char board[][26], int n) 
{
    //the code below including the while loop prints the column labels from a to letter(n)
    int count = 0;
    printf("  "); //allignment
    while (count < n)
    {
        printf("%c", count+97); //prints 'a', then 'b' etc.
        if(count == n-1) //if its the last element print a new line for the grid spaces to start
        {
            printf("\n");
        }
        count++;
    }

    //the nested for loops initalize the board array and prints as well
    for (int i = 1; i <= n; i++)
    {
        printf("%c ", i+96);
        for (int j = 1; j <= n; j++)
        {
            if((i == n/2 && j == n/2) || (i == (n/2) + 1 && j == (n/2) + 1)) //this is the top left or bottom right of the middle
            {
                board[i-1][j-1] = 'W';
            }
            else if((i == (n/2) && j == (n/2) + 1) || (i == (n/2) + 1 && j ==(n/2))) //this is the top right or bottom left of the middle, 
            {
                board[i-1][j-1] = 'B';
            }
            else //it is not in the middle 4 spaces so it is an empty spot at the beginning of the game
            {
                board[i-1][j-1] = 'U';
            }
            printf("%c", board[i-1][j-1]);
        }
        printf("\n"); //print a new line each row
    }
    printf("\n");
    printGamePartThrough(board, n);

}

/*
bool positionInBounds(int n, int row, int col) 
{

}

bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol) 
{

}
*/


int main(void) 
{
    int boardSize;
    printf("Enter the board dimension: ");
    scanf("%d", &boardSize);
    char board [boardSize][26];
    printBoard(board, boardSize);
    printGamePartThrough(board, boardSize);
    return 0;
}
