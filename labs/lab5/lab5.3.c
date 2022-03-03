//UNFINISHED

#include <stdio.h>


void longestMutualSequence(int firstArr[], int secondArr[], int sizeA, int sizeB)
{
    int commonSequenceLength = 0, longestCommonSequence = 0, currentStartIndex = 0, startIndex = 0, endIndex = 0;
    for (int i = 0; i < sizeA; i++)
    {
        for (int j = 0; j < sizeB; j++)
        {
            if(firstArr[i] == secondArr[j] && firstArr[i] < firstArr[i+1] && secondArr[j] < secondArr[j+1]) //if its common and increasing
            {
                commonSequenceLength++;
                //break;
            }
            if (firstArr[i] == secondArr[j])
            {
                if(firstArr[i] > firstArr[i+1] || secondArr[j] > secondArr[j+1])
                {
                    commonSequenceLength++;
                    if(commonSequenceLength > longestCommonSequence)
                    {
                        longestCommonSequence = commonSequenceLength;
                        startIndex = currentStartIndex;
                        endIndex = i;
                    }
                    commonSequenceLength = 0;
                    currentStartIndex = i+1;

                }

            }
        }
        
    }
    for (int k = startIndex; k != endIndex; k++)
    {
        printf("%d, ", firstArr[k]);
    }
    printf("%d.", firstArr[endIndex]);
    
}

int main ()
{
    int a[] = {1, 2, 3, 4, 1000, 90, 100, 110, 200, 202};
    int b[] = {1, 2, 3, 4, 1000, 90, 100, 110, 200, 202};
    longestMutualSequence(a, b, 10, 10);
    return 0;
    
}

