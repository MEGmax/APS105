#include <stdio.h>

void swap (int * a, int * b)
{
    int temp;
    temp = *a; //get value of a and store it in temp
    *a = *b; //assign value of a to value of b
    *b = temp; //assign value of b to temp

    printf("Num1 is now: %d\nNum2 is now: %d", *a, *b);
}
int main ()
{
    int num1, num2;
    printf("Enter Number 1: Enter Number 2: ");
    scanf("%d %d", &num1, &num2);
    swap(&num1, &num2);

}