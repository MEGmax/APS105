#include <stdio.h>

//prototype declorations
void triangle (int); //prints pascales triangle
int choose (int, int); //calculates nCr
int factorial (int); //calculates the factorial of a number
void spacesNeededBeforeFirstEntry(int, int); //prints spaces before the first entry on each row

int main (void)
{   
    //main method given
    int rows;
    do 
    {
        printf("Enter the number of rows: ");
        scanf("%d", &rows);

        if (rows >= 0) 
        {
            triangle(rows);
        }
    }while (rows >= 0);

    return 0;
    
}

void triangle (int n)
{
    for (int currentRow = 1; currentRow <= n; currentRow++) //run this loop for each row (rows specified by the user)
    {
        spacesNeededBeforeFirstEntry(n, currentRow); 
        /*the for loop below begins at the value of the current row since the first entry of 
        each row is nCr where n == r. The next entry will be one less and follow the formula 
        nCr where r = n-1 and n is constant since it represents the row.*/
        for (int r = currentRow-1; r >= 0; r--)
        {
           printf("%-6d", choose(currentRow-1, r));//print current nCr
        }

        printf("\n");
    }

}


int choose (int n, int r)
{
    int entry = (factorial(n))/(factorial(r)*factorial(n-r)); //nCr formula
    return entry; //return the value for nCr which will be an entry in pascales triangle
}


int factorial (int n)
{
    for (int i = n-1; i >=1; i--)
    {
        n = n*i;
    }
    if (n == 0) //0! == 1, special case where the for loop will give an error since 0*1=0
    {
        n = 1;
    }
    return n;  
}

void spacesNeededBeforeFirstEntry(int numberOfRows, int currentRow)
{
    //The for loop below prints the spaces before the first entry on the row
    for (int i = 1; i <= numberOfRows-currentRow; i++)
    {
        printf("   ");
    }
    return;
}

