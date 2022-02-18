#include <stdio.h>

void longestSequence(int [], int);

int main ()
{
    int array[] = {-1, 1, 2, -2, 4, 4, 111};
    int sizeA = 7;
    longestSequence(array, sizeA);
}

void longestSequence(int a[], int sizeA)
{
    int lengthOfCurrent = 0, currentStartIndex = 0, longestEndIndex = 0, longestLength = 0, startOfLongestIndex = 0;

    for (int i = 0; i < sizeA; i++) //loop through each index of array
    {
        if (a[i] >= a[i+1]) //if the sequence is decreasing or the same
        {
            lengthOfCurrent++;
            if (lengthOfCurrent > longestLength) //if the current length is the longest
            {
                longestLength = lengthOfCurrent;
                lengthOfCurrent = 0;
                startOfLongestIndex = currentStartIndex;
                longestEndIndex = i;
            }
            currentStartIndex = i+1;
            
        }
        else //increasing sequence
        {
            lengthOfCurrent++;
        }
        
        
       
    }

    printf("Longest sequence is ");

    for (int i = startOfLongestIndex; i != longestEndIndex; i++)
    { 
        printf("%d, ", a[i]);
    }
    printf("%d.", a[longestEndIndex]);
    
    
}
