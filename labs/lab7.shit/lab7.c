//
// Author:
//

//#include "reversi.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "reversi.h"

//This program will not run in examfiy since the function prototypes are stored in the lab 7 folder in the "reversi.h" file. For it to run in examify
//copy the function protypes from the reversi.h file and paste them under this comment.

void printTheBoard(char board [][26], int n)
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

    for (int i = 0; i < n; i++) //loops through rows
    {
        printf("%c ", i+97); //prints vertical letters labelling the rows
        for (int j = 0; j < n; j++) //loops through columns
        {
            printf("%c", board[i][j]); //prints element
        }
        printf("\n"); //prints new line for each row
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
    return number; //returns nice number
}

bool positionInBounds(int n, int row, int col) 
{
    if (row > n || col > n || row < 0 || col < 0)
    {
        return false;
    }
    return true;
}

void flipPieces (char board[][26], int rowPlaced, int colPlaced, char mover, int n, int rowDir, int colDir)
{
    for (int s = 1; board[rowPlaced+(s*rowDir)][colPlaced+(s*colDir)] != mover; s++)
    {
        board[rowPlaced+(s*rowDir)][colPlaced+(s*colDir)] = mover;
    }

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

    for (int i = 0; i < n; i++) //loops through rows
    {
        printf("%c ", i+97); //prints vertical letters labelling the rows
        for (int j = 0; j < n; j++) //loops through columns
        {
            printf("%c", board[i][j]); //prints element
        }
        printf("\n"); //prints new line for each row
    }
    
}

void makeAMove (char board[][26], int n)
{   
    int size = n;
    int gridDirection[8][2] ={{1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}};
    char input [3]; 
    printf("Enter a move:\n");
    scanf("%s", input);
    char colour = input[0];
    int row = letterToInt(input[1]), col = letterToInt(input[2]), valid = 0;
    bool withinBoard = positionInBounds(n, row, col);

    if (board[row][col] != 'U'||withinBoard == false) //must make a move where there is a free space
    {
        printf("Invalid move.");
        printTheBoard(board, n);
    }

    for (int d = 0; d < 8; d++)
    {
        bool dir = opponentPieceBeside(board, row, col, colour, gridDirection[d][0], gridDirection[d][1], n);
        if (dir)
        {
            bool legal = checkLegalInDirection(board, n, row, col, colour, gridDirection[d][0], gridDirection[d][1]);  
            if (legal)
            {
                printf("Valid move.\n");
                valid = 1;
                board[row][col] = colour;
                flipPieces(board, row, col, colour, n, gridDirection[d][0], gridDirection[d][1]);
            }
        }
    }

    if (valid == 0)
    {
        printf("Invalid move.\n");
        printTheBoard(board, n);
    }

}
bool opponentPieceBeside(char board[][26], int row, int col, char colour, int rowDir, int colDir, int n)
{
    char opponent = 'W';
    bool withinBoard = positionInBounds(n, row+rowDir, col+colDir);
    if (colour == 'W')
    {
        opponent = 'B';
    }

    if(withinBoard == false)
    {
        return false;
    }

    if (board[row+rowDir][col+colDir] == opponent)
    {
        return true;
    }
    return false;
}

bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol) 
{
    bool inBounds;
    
    //establish opponents colour
    char opponent = 'W';
    if (colour == 'W')
    {
        opponent = 'B';
    }
    for (int i = 2; i < n; i++)
    {
        inBounds = positionInBounds(n, row+(deltaRow*i), col+(deltaCol*i));
        if (inBounds == false)
        {
            return false;
        }
        if(board[row+(deltaRow*i)][col+(deltaCol*i)] == 'U')//the first space after the opponents piece is also a space
        {
            return false;
        }
        else if (board[row+(deltaRow*i)][col+(deltaCol*i)] == colour)
        {
            return true; 
        }
        
    }
    return false;
}


void printAvailableMoves (char board[][26], int n)
{
                            //SOUTH     SW       WEST      NW      NORTH     NE      EAST     SE
    int gridDirection[8][2] ={{1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}};
    char colour[2] = {'W', 'B'};
    for(int c = 0; c < 2; c++)
    {
        if(colour[c] == 'W')
        {
            printf("Available moves for W:\n");
        }
        else if(colour[c] == 'B')
        {
            printf("Available moves for B:\n");
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(board[i][j] == 'U')
                {
                    for (int d = 0; d < 8; d++)
                    {
                        bool direction = opponentPieceBeside(board, i, j, colour[c], gridDirection[d][0], gridDirection[d][1], n);
                        if(direction)
                        {
                            bool legal = checkLegalInDirection(board, n, i, j, colour[c], gridDirection[d][0], gridDirection[d][1]);
                            if(legal)
                            {
                                if(i == 24 && j == 1)
                                {
                                    //printf("Row dir: %d Col dir: %d", gridDirection[d][0], gridDirection[d][1]);
                                }
                                printf("%c%c\n", i+97, j+97);
                            }
                        }
                    }
                }
            }   
        }
    }
    makeAMove(board, n); 
}

void getGamePartThrough (char board [][26], int n)
{
    int row, column, i = 0;
    char input [3] = {"111"};
    printf("Enter board configuration:\n"); //prompt user
    while(i < 5)
    {
        scanf("%s", input); //gets input
        if(strcmp(input, "!!!") == 0)
        {
            break;
        }
        row = letterToInt(input[1]); //the second letter represnts the row, which converted from a char to an int via a function 
        column = letterToInt(input[2]); // the third letter represents the column
        if(input[0] == 'B') //if the colour is black
        {
            board[row][column] = 'B';
        }
        else if(input[0] == 'W') //if the colour is white
        {
            board[row][column] = 'W';
        }
    }
    printTheBoard(board, n); //call function to print the updated board which represents the game part way through specified by the user
    printAvailableMoves(board, n);

}

void printBoard(char board[][26], int n) 
{
    //the code below including the while loop prints the column labels from a to letter(n)
    int count = 0;
    printf("  "); //allignment
    while (count < n)
    {
        printf("%c", count+97); //prints 'a', then 'b' etc. (via ASCII values)
        if(count == n-1) //if its the last element print a new line for the grid spaces to start
        {
            printf("\n");
        }
        count++;
    }

    //the nested for loops initalize the board array and prints as well (starts at 1 so comparrison is easier)
    for (int i = 1; i <= n; i++) //loop through rows 
    {
        printf("%c ", i+96); //prints via ASCII values, ex. 96+1 = 97 = 'a', this is the column labels going vertically
        for (int j = 1; j <= n; j++) //loop through coloumns
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
            printf("%c", board[i-1][j-1]); //prints current element
        }
        printf("\n"); //print a new line each row
    }
    getGamePartThrough(board, n); //calls function to print the game part way through with this starting board initalized
}


int main(void) 
{
    int boardSize;
    //prompt user for size and store
    printf("Enter the board dimension: ");
    scanf("%d", &boardSize);

    char board [boardSize][26]; //intalize board
    printBoard(board, boardSize); //call print board function to print the starting board with the pieces in the middle
    return 0;
}
