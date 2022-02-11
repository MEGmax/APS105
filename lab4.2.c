#include <stdio.h>

//prototypes
int gcd (int, int);
int checkErdos(int, int);

int main ()
{
    int kStart, kEnd, aStart, aEnd, eNumber;

    //The four do while loops below take input from the user
    do
    {
        printf("Enter the number to start searching for k (> 2, inclusive): ");
        scanf("%d", &kStart);
    } while (kStart <= 2);

    do
    {
        printf("Enter the number to stop searching for k (inclusive): ");
        scanf("%d", &kEnd);
    } while (kEnd <= kStart); 

     do
    {
        printf("Enter the number to start searching for a (> 0, inclusive): ");
        scanf("%d", &aStart);
    } while (aStart <= 0);

     do
    {
        printf("Enter the number to stop searching for a (inclusive): ");
        scanf("%d", &aEnd);
    } while (aEnd <= aStart);

    //The for loop below will iterate for each k
    for (int k = kStart; k <= kEnd; k++)
    {
        printf("Trying k = %d...\n", k);
        for (int a = aStart; a <= aEnd; a++) //This for loop will run for each value of a specified by the user
        {
            eNumber = checkErdos(a, k); //call function to check if its an erdos number passing the current a and k values
            if(eNumber == 1) //if its an erdos number output this number and cooresponding a value
            {
                printf("Erdos-Woods number: %d", k);
                printf("\na = %d", a);
                exit(0); //terminate
            }
        }
        
    }
    
}

int gcd(int a, int b)
{
    if (a == 0) 
    {
        return b; //once a is 0, return its corresponding b value
    }
    return gcd(b % a, a); //use recusion to call the same function excpect use the remainder of b/a and a as the new paramters
}

int checkErdos (int currentA, int currentK)
{
    for (int i = 1; i < currentK; i++) //check all i values for 0 < i < k
    {
        //if any numbers between a and a+k or a and a+i don't share prime factors, quit the function and return 0 (false) 
        if (gcd (currentA+i, currentA) <= 1 && gcd(currentA+currentK, currentA+i) <= 1) //if any numbers 
        {
            return 0;
        }

    }

    return 1; //if the if statment about does not run (and terminates the function), k is an erdos number
    
}
