
#include <stdio.h>
#include <math.h>
//APS105 LAB 5 PART 3
//BY MATTHEW GRECH
//Friday Feb 18 2022
//This program finds the longest common sequence of 2 different arrays
void longestMutualSequence(int firstArr[], int secondArr[], int sizeA, int sizeB);
int lengthOfCommonSequence(int a[], int b[],int i,int k,int maxLength,int* startIndex);
int main (void)
{
    int ar1[] = {1, 2, 3, 500, 600, 100 };
    int ar2[] = { 1, 2, 3, 500, 600 };

   longestMutualSequence(ar1,ar2,6,5);

    return 0;
}

int lengthOfCommonSequence(int a[], int b[], int i, int j, int length, int *startingIndex) 
{
    int count = 0;

    for(int p = 0; p < length; p++)
    {
        if (a[i+p] == b[j+p]) //check if the elements continue to be the same  
        {
            if (count == 0) //used only if this is the first instance of 2 elements being the same, this will be the starting index
            {
                *startingIndex = i+p;
            }
            count++;
        }
        else
        {
            return count;
        }
    }
    return count;  
}

void longestMutualSequence(int firstArr[], int secondArr[], int sizeA, int sizeB)
{
    int startIndex, currentSize = 0, outputStartingIndex, largestSize = 0;

    //find the largest array 
    int shortestLength = sizeA; 
    if (shortestLength > sizeB)
    {
        shortestLength = sizeB;
    }

    for(int i = 0; i < sizeA; i++) //loop through all elements of a
    {
        for (int j = 0; j < sizeB; j++) //loop through all elements of b
        {
            if(firstArr[i] == secondArr[j]) //if they are the same
            {
                currentSize = lengthOfCommonSequence(firstArr, secondArr, i, j, shortestLength, &startIndex); //call function to find current size of a common sequence
                if (largestSize < currentSize) //reasign output array if the current sequence is longer than the previous longest
                {
                    largestSize = currentSize; 
                    outputStartingIndex = startIndex;
                }
            }
                
        }
    }
    int endIndex = largestSize+outputStartingIndex-1; //end index of output array
    int lastNum;
    //output longest commmon sequence
    printf("Longest common sequence is "); 
    for(int i = startIndex; i<(largestSize+outputStartingIndex); i++) // this loop will filter through the section of the first array which encloses the sequence
{ 
    

     printf(" %d",firstArr[i]); // printing the numbers

                //the below decsion structure prints appropriate commas and periods
            if(i<(largestSize+outputStartingIndex-1)&&i!=sizeA-1) // there are more numbers in the sequence still to be printed, thus a comma must seperate the preceding from the following number
            {
                printf(",");
            }
            else // i must equal (highestIndex+highestCount), thus it has printed the last number in the list and now needs a period
            {
                printf(".");
                    
            }

            if(i==sizeA-1)// there is an issue with printing, if the sequence reaches the end of the first array, the array we are using to print, it will print a zero at the end of it, so this solves that
                    {break;}
       
}
    


}


