#include <stdio.h>

//APS105 LAB 5 PART 3
//BY MATTHEW GRECH
//Friday Feb 18 2022
//This program finds the longest common sequence of 2 different arrays

void longestMutualSequence(int firstArr[], int secondArr[], int sizeA, int sizeB)
{
    int currentLength = 0, longestCommonSequence = 0, currentStartIndex = 0, startIndex = 0, endIndex = 0;
    for (int i = 0; i < sizeA; i++)
    {
        for (int j = 0; j < sizeB; j++)
        {
            if(firstArr[i] == secondArr[j]) //if its common
            {
                printf("i: %d j: %d\n", i ,j);
                if (firstArr[i] < firstArr[i+1] || secondArr[j] < secondArr[j+1]) //if it is increasing
                {
                    currentLength++;
                }

                else if(firstArr[i] > firstArr[i+1] || secondArr[j] > secondArr[j+1]) //if it is decreasing
                {
                    currentLength++;
                    if(currentLength > longestCommonSequence)
                    {
                        longestCommonSequence = currentLength;
                        startIndex = currentStartIndex;
                        endIndex = j;
                        longestCommonSequence = currentLength;
                    }
                    currentStartIndex = i+1;
                    currentLength = 0;
                //break;
                }
            }
        }
    }

    printf("Common sequence length: %d \n", currentLength);
    printf("Start Index: %d\n", startIndex);
    printf("End index: %d\n", endIndex);




    for (int k = startIndex; k != endIndex; k++)
    {
        printf("%d, ", firstArr[k]);
    }
    printf("%d.", firstArr[endIndex]);
    
}

int main ()
{
    int a[] = {1, 0, 3, 4, 1000, 90, 100, 110, 200, 202};
    int b[] = {1, 2, 3, 4, 1000, 90, 100, 110, 200, 202};
    longestMutualSequence(a, b, 10, 10);
    return 0;
    
}

