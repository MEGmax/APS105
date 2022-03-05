#include <stdio.h>

//APS105 LAB 5 PART 2
//BY MATTHEW GRECH
//Friday Feb 18 2022
//This program (function) will take an array from the main method, given the elements and the size, and
//output the longest sequence of increasing numbers in that array

void longestSequence(int [], int); //prototype 

//main function is just for testing, will be provided on examify
int main ()
{
    int array[] = {1, 9, 9, 9};
    int sizeA = 2;
    longestSequence(array, sizeA);
}

void longestSequence(int a[], int sizeA)
{
    int currentLength = 0, longestLength = 0, currentStartIndex = 0, startOfLongestIndex = 0, endOfLongestIndex = 0;

    for (int i = 0; i < sizeA; i++) //loop through each index of array
    {
        if (a[i] >= a[i+1]) //if the sequence is decreasing or the same
        {
            currentLength++; //count the last element of the array before it starts decreasing
            if (currentLength > longestLength) //if the current length is the longest
            {
                longestLength = currentLength; //assign the longest length to the current length
                startOfLongestIndex = currentStartIndex; //assign the beginning of the longest increasing sequence index to the starting index marked 
                endOfLongestIndex = i; //the end of the increasing sequence is whatever i got up to 
            }
            currentStartIndex = i+1; //assume the next iteration will also be increasing and assign the new beginning of the next increasing sequence to i+1
            currentLength = 0; //reset the current length for the next iteration
        }
        else //increasing sequence
        {
            currentLength++; //keeps track of how long the current increasing sequence is 
        } 
    }

    //print results below
    printf("Longest sequence is ");
    for (int i = startOfLongestIndex; i != endOfLongestIndex; i++)
    { 
        printf("%d, ", a[i]); //prints until the second last elemt
    }
    printf("%d.", a[endOfLongestIndex]); //print last element (needs a period instead of a comma)
    
    
}
