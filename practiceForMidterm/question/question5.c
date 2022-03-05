#include <stdio.h>
#include <math.h>

int main(void) 
{
    int sieve[100] = {0}, i, p = 2; //initalize array of numbers with the first element being 0, i and the first prime number which is zero

    while (p < sqrt(100)) //run for as long p^2 is less than 100 (condition given) 
    {
        printf("%d ", p); //print p which is the prime number (starting at 2)
        i = 2; //start i at 2 always
        while (i * p < 100) //the first iteration will run 2*2, then 3*2, 4*2... 49*2, so for the first iteration it will run 50 times
        {
            sieve[i * p] = 1; //set 4th number equal to 1, 6th number, 8th number.... 98th number 
            i ++;
        } 
        p++; //check next p
        while (sieve[p] == 1) // for each not prime number, incremement p once 
        {
            p++;
        }   
    }

    //print results
    for (; p < 100; p++)
    {
        if (sieve[p] == 0)
        {
            printf("%d ", p);
        }
    }
    

    
}

