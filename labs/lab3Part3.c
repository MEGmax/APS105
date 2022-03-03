#include <stdio.h>
/*
This program returns the minimium number of coins needed to make up an amount of change (less than 100) specified by the user.
After this number of coins is presented, the program will prompt the user to enter another amount of change to repeat the process
until invalid input is entered (input less than 1 or greater than 99)
*/
int main (void)
{
int input, numOfTypesOfCoins = 0, valid = 1;
int numOfEachCoin [4]; // index 0 = num of quarters, index 1 num of dimes... ect
char coinName [4][10] = {"quarter", "dime", "nickel", "cent"};

do //runs once to get input
{
    numOfTypesOfCoins = 4; //reset the number of types of coins before new input is taken

    //prompt user for input and collect it
    printf("Please give an amount in cents less than 100: ");
    scanf("%d", &input);

    printf("%d cents: ", input); //print amount entered

    /*the if statement below checks if the input is valid. If it is not print message, set valid = 0 
    so do-while doesnt run again and break out of the loop*/
    if (input <= 0 || input >= 100)
    {
        printf("invalid amount.");
        valid = 0;
        break;
    }

    //calculate num of quarters
    numOfEachCoin[0] = input/25;
    input -= numOfEachCoin[0]*25;

    //calculate num of dimes
    numOfEachCoin[1] = input/10;
    input -= numOfEachCoin[1]*10;

    //calculate num of nickels
    numOfEachCoin[2] =input/5;
    input -= numOfEachCoin[2]*5;

    //calculate num of pennies
    numOfEachCoin[3] = input;

    //the for loop below counts backward from 4 to establish how many different types of coins there are
    for (int j = 0; j < 4; j++)
    {
        if (numOfEachCoin[j] == 0)
        {
            numOfTypesOfCoins -= 1;
        }
    }

    int numOfTypesOfCoins2 = numOfTypesOfCoins; //placeholder
    int numOfTypesOfCoins3 = numOfTypesOfCoins; //placeholder

    if (numOfTypesOfCoins > 1 && numOfTypesOfCoins != 2) //in this case commas and "and" is needed
    {
        for (int i = 0; i < 4; i++) //run this loop for each type of coin
        {
            if (numOfEachCoin[i] != 0) //as long the coin exists in the change run this block 
            {
                if(numOfTypesOfCoins2 == 1) //if the last type of coin is about to be displayed, "and" is needed in front of that type
                {
                    if (numOfEachCoin[i] > 1) //plural case
                    {
                        printf("and %d %ss", numOfEachCoin[i], coinName[i]);
                    }
                    else //singular case
                    {
                        printf("and %d %s", numOfEachCoin[i], coinName[i]);
                    }
                }
                else //this is the case that runs when "and" is not needed
                {
                    if (numOfEachCoin[i] > 1)
                    {
                        printf("%d %ss, ", numOfEachCoin[i], coinName[i]);
                    }
                    else 
                    {
                        printf("%d %s, ", numOfEachCoin[i], coinName[i]);
                    }
                }
                numOfTypesOfCoins2--;//decremente the number of types of coins since everything for the current type of coin has been outputed
            }
        }
        printf(".");
    }
    else if (numOfTypesOfCoins == 1) //in this case no commas or "and" is needed
    {
        for (int h = 0; h < 4; h++) //run this for loop for each type of coin
        {
            if(numOfEachCoin[h] != 0) //as long as a number of the type of coin exists in this change run this code
            {
                if (numOfEachCoin[h] > 1) //plural case 
                {
                    printf("%d %ss.", numOfEachCoin[h], coinName[h]);
                }
                else //singular case
                {
                    printf("%d %s.", numOfEachCoin[h], coinName[h]);
                }
            }
        }
    }
    else if (numOfTypesOfCoins == 2) //in this case only "and" is needed (no commas)
    {
        for (int g = 0; g < 4; g++) //run this for loop for each type of coin
        {
            if(numOfEachCoin[g] != 0) //as long as a number of the type of coin exists in this change run this code
            {
                if(numOfTypesOfCoins3 == 1) //if the last type of coin is about to be displayed run this code so "and" will be included
                {
                    if (numOfEachCoin[g] > 1) //plural case
                    {
                        printf(" and %d %ss.", numOfEachCoin[g], coinName[g]);
                    }
                    else //singular case
                    {
                        printf(" and %d %s.", numOfEachCoin[g], coinName[g]);
                    }
                }
                if (numOfEachCoin[g] > 1 && numOfTypesOfCoins3 != 1) //dont output "and", also plural case
                {
                    printf("%d %ss", numOfEachCoin[g], coinName[g]);
                }
                else if(numOfTypesOfCoins3 != 1) //dont ouput "and", also singular case 
                {
                    printf("%d %s", numOfEachCoin[g], coinName[g]);
                }
                numOfTypesOfCoins3--; //decremente the types of coins since everything for this type of coin has been outputed
            }
        }
    }
    printf("\n"); //advance to a new line each time input needs to be taken

}while (valid == 1); 

return 0;
}

