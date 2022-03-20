//
// This is a header file for your Lab 7 solutions, which includes all
// the required function prototypes.
//
// Date: February 2022
//
// Please note: this file should not be modified.

#ifndef REVERSI_H
#define REVERSI_H

#include <stdbool.h>

// Function prototypes for Lab 7
bool positionInBounds(int n, int row, int col);
void flipPieces (char board[][26], int rowPlaced, int colPlaced, char mover, int, int);
void makeAMove (char board[][26], int n);
bool opponentPieceBeside(char board[][26], int row, int col, char colour, int rowDir, int colDir, int n);
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);
void printAvailableMoves (char board[][26], int n);
void getGamePartThrough (char board [][26], int n);
void printBoard(char board[][26], int n);
bool legal (char board[][26], int row, int col, char colour, int n);


#endif
