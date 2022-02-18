//NOT FINISHED
#include <stdio.h>

void longestSequence(int [], int);

int main ()
{
    int array[] = {0, 1, 2, 3, 4, 5};
    int sizeA = 6;
    longestSequence(array, sizeA);
}

void longestSequence(int a[], int sizeA)
{
    int lengthOfCurrent = 0, currentStartIndex = 0, currentEndIndex = 0, tempLength, j = 0;
    int *pCurrentStartIndex;
    for (int i = 0; i < sizeA-1; i++)
    {
        if (a[i] < a[i+1]) //if the sequence is increasing
        {
            currentStartIndex = i;
            pCurrentStartIndex = &currentStartIndex;
            lengthOfCurrent++;
        }

        tempLength = lengthOfCurrent;
        
        
        
       
    }
        printf("Longest start: %d Longest End: %d ", *pCurrentStartIndex, a[4]);
    
}
