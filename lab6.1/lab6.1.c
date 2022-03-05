#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
    Lab 6 Part 1
    Feb 26 2022
    By: Matthew Grech
    This program will find a word in a grid of characters and the direction the word is in (in cardinal directions) 
    (This is a word search solver)
*/

//this function prints the location found
void printFoundLocation(int rowDir, int colDir) 
{
    //print direction based on the row and column direction
    if(rowDir == 1 && colDir == 0)
    {
        printf("south direction.");
    }
    else if(rowDir == 1 && colDir == -1)
    {
        printf("southwest direction.");
    }
    else if(rowDir == 0 && colDir == -1)
    {
        printf("west direction.");
    }
    else if(rowDir == -1 && colDir == -1)
    {
        printf("northwest direction.");
    }
    else if(rowDir == -1 && colDir == 0)
    {
        printf("north direction.");
    }
    else if(rowDir == -1 && colDir == 1)
    {
        printf("northeast direction.");
    }
    else if(rowDir == 0 && colDir == 1)
    {
        printf("east direction.");
    }
    else if(rowDir == 1 && colDir == 1)
    {
        printf("southeast direction.");
    }
}

//this function checks if the word is found in the direction passed to it
bool search1D(char word[], int wordSize, const int Size, char grid[Size][Size], int row, int col, int rowDir, int colDir) 
{
    int length = 0; //start length of current sequence at 0
    for (int h = 0; h < wordSize; h++) //loop through the length of the word we are looking for 
    {
        //if the letter we are checking is the same as we move in the direction we are checking, increase the length of the current sequence
        if(word[h] == grid[row+rowDir*h][col+colDir*h]) 
        {
            length++;
        }
    }

    //if the length of the current sequence is the same length as the word, this is the word
    if(length == wordSize)
    {
        return true;
    }   
    else
    {
        return false;
    } 
}

//primary function to find first letter of word and pass directions to be checked 
void search2D(char word[], int wordSize, const int Size, char grid[Size][Size])
{
    for (int i = 0; i < Size; i++) //loop through each row of word search grid
    {
        for (int j = 0; j < Size; j++) //loop through each column of word search grid
        {
            if(grid[i][j] == word[0]) //if the 1st letter of the word we are looking for is the index of the grid that we are currently on in the loop, run the code below
            {
                                        //SOUTH     SW       WEST      NW      NORTH     NE      EAST     SE
                int gridDirection[8][2] ={{1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}};
                for (int d = 0; d < 8; d++) //loop through each possible direction 
                {
                    //call a function to the check all the directions around the first letter and if the word is found
                    bool direction = search1D(word, wordSize, Size, grid, i, j, gridDirection[d][0], gridDirection[d][1]); //row found at [something][0] (first element of each "row"), column found at [something][1] (second element of each "row")
                    if (direction == true) //if direction is true, we found the word, print results 
                    {
                        printf("Word found at row %d and column %d in the ", i, j); //general results print statement 
                        printFoundLocation(gridDirection[d][0], gridDirection[d][1]); //this function prints the direction 
                        exit(0); //terminate program after word is found
                    }   
                }
            }
        }    
    }
    //if the direction is never true, nothing will print and the program will not be terminated, thus this is the only output needed
    printf("Word not found."); 
}

//main function not needed for examify, use to test code
int main ()
{
    char puzzle [5][5] = {{'T', 'A', 'T', 'T', 'A'},{'T', 'A', 'T', 'W', 'M'},{'A', 'A', 'T', 'N', 'Q'},{'M', 'U', 'Y', 'T', 'S'},{'P', 'T', 'T', 'A', 'F'}};

    //prints word search
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c ", puzzle[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    //define word to look for an call primary function
    char word[23] ="MATT";
    search2D(word, 4, 5, puzzle);

}



