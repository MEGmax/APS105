/*
    Lab 7
    March 14th 2022
    By: Matthew Grech
    This program will model the game "Othello" (aka Reversi), and prompt the user to configure the board
    to represent a situation part way through the game. The user can configure the board to whatever they like until
    "!!!" is entered. After the board is configured the program will display the move available to the 2 players. The user
    will then be prompted to enter a move in the format (colour('B' or 'W'), row(a-z), column (a-z)). If the move is legal the
    board will be printed with the piece place and the board updated, if the move is illegal then the same configured board will
    be printed and an invalid move message will be displayed to let the user know they made an illegal move. 
*/

/*
    UPDATED:
    After all 10 test cases for lab 7 came out, this program scored 7/10, the issues were printing available
    moves multiple times and terminating if there were no moves for either player. The errors are commented out and added in 
    the function printAvailableMoves.
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "reversi.h"

bool legal (char board[][26], int row, int col, char colour, int n)
{
                             //SOUTH    SW       WEST      NW      NORTH      NE     EAST     SE
    int gridDirection[8][2] ={{1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}}; //all 8 possible grid directions
    int rowValidDirections [8], colValidDirections [8], numOfValidMoves = 0;
    for (int d = 0; d < 8; d++) //loop through each 8 directions to check them all
    {
        bool dir = opponentPieceBeside(board, row, col, colour, gridDirection[d][0], gridDirection[d][1], n); //check if there is an opponent beside
        if (dir) //if there is an opponent beside, this is the direction we need to check
        {
            bool legal = checkLegalInDirection(board, n, row, col, colour, gridDirection[d][0], gridDirection[d][1]); //make sure the move is legal 
            if (legal) //if the move is legal, return true and flip the pieces (after the move is made from perivous function)
            {
                rowValidDirections[numOfValidMoves] = gridDirection[d][0]; //store the valid row direction
                colValidDirections[numOfValidMoves] = gridDirection[d][1]; //store the valid col direction
                numOfValidMoves++; //increment the number of legal moves
            }
        }
    }

    if (numOfValidMoves == 0) //if there were no legal moves 
    {
        return false; //if none of the 8 directions makes both of the 2 fuctions return true, return false as no move is legal for the space being tested
    }
    else //there was a legal move
    {
        for (int x = 0; x < numOfValidMoves; x++) //loop through each of the valid moves to flip all the pieces
        {
            flipPieces(board, row, col, colour, rowValidDirections[x], colValidDirections[x]); //pass the corresponding row and col directions
        }
        return true; //return true because its a legal move on this space 
    }
}

void printTheBoard(char board [][26], int n)
{
    int count = 0;
    printf("  "); //allignment
    while (count < n) //this while loop will print the horizontal character label at the top of the board
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
    if (row >= n || col >= n || row < 0 || col < 0) //if the row or the coloumn is greater than the number of rows or columns, or negative, this is not within the bounds of the board
    {
        return false;
    }
    return true; //returns true if the if statement above doesnt run 
}

void flipPieces (char board[][26], int rowPlaced, int colPlaced, char mover, int rowDir, int colDir)
{
    //this for loop will continue so long as the piece continues to be the opponents piece (not the piece taking the turn)
    for (int s = 1; board[rowPlaced+(s*rowDir)][colPlaced+(s*colDir)] != mover; s++) 
    {
        board[rowPlaced+(s*rowDir)][colPlaced+(s*colDir)] = mover; //each iteration turns whatever space we are at to the colour taking the turn
    }
}

void makeAMove (char board[][26], int n)
{   
    char input [4]; 
    printf("Enter a move:\n");
    scanf("%s", input);
    char colour = input[0]; //first letter entered is the colour
    int row = letterToInt(input[1]), col = letterToInt(input[2]); //second and third letter entered is the row and column respectivily
    bool withinBoard = positionInBounds(n, row, col), allowed = legal(board, row, col, colour, n); //2 bools, one to check if its within the board the other if the move is legal
    //within the function legal, the function flipPieces will be called where the board will be updated after the move is placed
    
    if(allowed && withinBoard && board[row][col] == 'U') //if the move is allowed
    {
        printf("Valid move.\n");
        board[row][col] = colour; //place piece where move is made
    }
    else //if the move isnt legal print invalid
    {
        printf("Invalid move.\n");
    }
        printTheBoard(board, n); //print the board after the move has been made and the pieces have been flipped appropiatley
}
bool opponentPieceBeside(char board[][26], int row, int col, char colour, int rowDir, int colDir, int n)
{
    //establish opponent
    char opponent = 'W';
    if (colour == 'W')
    {
        opponent = 'B';
    }

    bool withinBoard = positionInBounds(n, row+rowDir, col+colDir);
    if(withinBoard == false) //if the space being checked is outside the board, return false
    {
        return false;
    }

    if (board[row+rowDir][col+colDir] == opponent) //if there is an opponent beside the space being checked, return true
    {
        return true;
    }
    return false; //returns false unless the if statement above runs 
}

bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol) 
{
    for (int i = 2; i < n; i++) //start at 2 to check the space after the space where the opponent was found beside the free space
    {
        bool inBounds = positionInBounds(n, row+(deltaRow*i), col+(deltaCol*i));
        if (inBounds == false) //if at any point the space being checked is outside the bored, the move is not legal
        {
            return false;
        }
        if(board[row+(deltaRow*i)][col+(deltaCol*i)] == 'U') //the second there is a space, the move is not legal
        {
            return false;
        }
        else if (board[row+(deltaRow*i)][col+(deltaCol*i)] == colour) //if there is ever the colour whos turn it is, the move is legal since an opponent has already been found in the space before, or there are multiple opponents making a possible move
        {
            return true; 
        }
    }
    return false; //if nothing in the for loop is true, this means that the rest of the direction being checked is the opponent and there is no legal move to be made
}


void printAvailableMoves (char board[][26], int n)
{
                            //SOUTH     SW       WEST      NW      NORTH     NE      EAST     SE
    int gridDirection[8][2] ={{1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}}//, validMoves = 0;
    char colour[2] = {'W', 'B'};
    for(int c = 0; c < 2; c++) //check each colour
    {
        //print headers for white and black
        if(colour[c] == 'W')
        {
            printf("Available moves for W:\n");
        }
        else if(colour[c] == 'B')
        {
            printf("Available moves for B:\n");
        }
        for (int i = 0; i < n; i++) //loop through rows
        {
            for (int j = 0; j < n; j++) //loop through columns
            {
                if(board[i][j] == 'U') //if it is a free space
                {
                    for (int d = 0; d < 8; d++) //check each direction
                    {
                        if(opponentPieceBeside(board, i, j, colour[c], gridDirection[d][0], gridDirection[d][1], n)) //if there is an opponent beside the free space being checked
                        {
                            if(checkLegalInDirection(board, n, i, j, colour[c], gridDirection[d][0], gridDirection[d][1])) //if the move is legal
                            {
                                printf("%c%c\n", i+97, j+97); //print the coordinates of the legal move using ASCII
                                //validMoves++;
                                break;//needed a break statement in order to not print an avaiable moves multiple times if it is possible in multiple directions
                            }
                        }
                    }
                }
            }   
        }
    }
    /*if(validMoves == 0)
    {
        exit(0);
    }This is the stupidest thing ever. The program should (imo) terminate if theres no moves for either player 
    but examify wants the user to ask for input again, so leave this if statement commented out and get rid of validMoves */
}

void getGamePartThrough (char board [][26], int n)
{
    int row, column;
    char input [4]; //4 for space for \0
    printf("Enter board configuration:\n"); //prompt user
    do
    {
        scanf("%s", input); //gets input
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
    } while (strcmp(input, "!!!"));
    printTheBoard(board, n); //call function to print the updated board which represents the game part way through specified by the user
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
}

int main(void) 
{
    int boardSize;
    //prompt user for size and store
    printf("Enter the board dimension: ");
    scanf("%d", &boardSize);

    char board [boardSize][26]; //intalize board
    printBoard(board, boardSize); //call print board function to print the starting board with the pieces in the middle
    getGamePartThrough(board, boardSize); //calls function to print the game part way through with this starting board initalized
    printAvailableMoves(board, boardSize); //call function to print available moves
    makeAMove(board, boardSize); //call function to enable user to make a move
    return 0;
}
