#include <stdio.h>
#include <stdbool.h>

//Lab 6 Part 2
//Feb 24 2022
//By: Matthew Grech
//This program will solve a 4x4 sudoko puzzle that has only 1 missing number after scanning a row and column ie. the program cannot
//choose between two numbers that are both possible 

int answer (bool one, bool two, bool three, bool four) //this function will compute the answer to the element being checked
{
    //check which of the 4 is false, this is the number that is missing, which is the number that will fill that element
    if (one == false)
    {
        return 1; //missing element is 1
    } 
    if (two == false)
    {
        return 2; //missing element is 2
    }
    if (three == false)
    {
        return 3; //missing element is 3
    }
    if (four == false)
    {
        return 4; //missing element is 4
    }
    else
    {
        return 0; //not needed, will always return a number 1-4 but is put here so no warning will show when compliling 
    }
    
}

void fillSudoko(const int Size, int sudoko [Size][Size])
{
    for (int i = 0; i < Size; i++) //loop throuh each row of sudoko
    {
        for (int j = 0; j < Size; j++) //loop through each coloumn of sudoko
        {
            if (sudoko[i][j] == 0) //if there is an empty element, run the code below to find the correct number
            {
                //create array with 4 elements representing if a 1,2,3 or 4 is included in a row or coluomn (included [0] means if a 1 is included). Will also reset to false each run 
                bool included [] = {false, false, false, false}; 
                for (int x = 0; x < Size; x++) //loop through from for each row and column of board
                {
                    //if any of the columns of the row with 0 in it has a 1 or any of the rows of the column with 0 in it has a 1, the number cannot be 1 and 1 is found in this sequence 
                    if(sudoko[i][x] == 1 || sudoko[x][j] == 1) 
                    {
                        included[0] = true;
                    }
                    //if any of the columns of the row with 0 in it has a 2 or any of the rows of the column with 0 in it has a 2, the number cannot be 2 and 2 is found in this sequence 
                    if (sudoko[i][x] == 2 || sudoko[x][j] == 2)
                    {
                        included[1] = true;
                    }
                    //if any of the columns of the row with 0 in it has a 3 or any of the rows of the column with 0 in it has a 3, the number cannot be 3 and 3 is found in this sequence 
                    if (sudoko[i][x] == 3 || sudoko[x][j] == 3)
                    {
                        included[2] = true;
                    }
                    //if any of the columns of the row with 0 in it has a 4 or any of the rows of the column with 0 in it has a 4, the number cannot be 4 and 4 is found in this sequence 
                    if (sudoko[i][x] == 4 || sudoko[x][j] == 4)
                    {
                        included[3] = true;
                    }
                }
                sudoko[i][j] = answer(included[0], included[1], included[2], included[3]); //call answer function to find the correct value for this element
            }
        }   
    }
}
