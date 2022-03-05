#include <stdio.h>
#include <math.h>
int main(void)
{
    int currentStartIndex = 5; //int with 5 stored in it
    int* pCurrentStartIndex; //pointer inialization

    pCurrentStartIndex = &currentStartIndex; //in the varaible pCurrentStartIndex store the address of currentStartIndex

    printf("*pCurrentStartIndex: (using pointer to get value) %d\n", *pCurrentStartIndex); //go to the address of pCurrentStartIndex and get the value stored there
    printf("currentStartIndex: (printing int) %d\n", currentStartIndex); //print an int
    printf("pCurrentStartIndex:  (address) %d\n", pCurrentStartIndex); //print the address of currentStartIndex

}
