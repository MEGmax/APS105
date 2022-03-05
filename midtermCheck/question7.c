#include <stdio.h>
#include <math.h>

/*
APS105 2022 Midterm Question 7?
By Matthew Grech
This program rotates an integer counterclockwise a number of times specified by the user (moves all numbers over right one spot with the
last digit going to the front ex. 123->231).
*/

int main()
{
    int digits, numOfTurns, tempDigits, length = 0, lastDigit, newDigits; //intitalize variables

    //prompt user for input and scan
    printf("Please enter a digit: ");
    scanf("%d", &digits);
    printf("How many times? ");
    scanf("%d", &numOfTurns);

    //use temp digits and while loop below to count how manyu digits are in the integer entered by the user
    tempDigits = digits;

    while(tempDigits > 0)
    {
        length++;
        tempDigits /= 10;
    }

    //run this for loop once for each number of turns specified by the user
    for (int i = 0; i < numOfTurns; i++)
    {
        lastDigit = digits % 10; //gets last digit of integer ex. 123 %10 = 3, which is the last digit
        newDigits = digits / 10; //take away last digit by dividing by 10, which rounds since this is integar divison
        digits = (lastDigit*pow(10, length-1)) + newDigits; //rewrite digits to the last digit times 10^the length-1 plus the remaining digits
        //an example of the last line would be 
        /*
        digits = 1203
        digits = 3*10^(4(length)-1) + 120
        digits = 300 + 120 = 3120, which is one turn counterclockwise
        This process repeats for each number of turns specified by the user
        */
    }

    //print output
    printf("Digits reworked: %d", digits);
}
