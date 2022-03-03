#include <stdio.h>
#include <math.h>

double median(int[], int[], int, int);

int main()
{
    int a[] = {1, 2, 10, 12, 100};
    int b[] = {1, 11, 20, 500, 600};
    int sizeA = 5;
    int sizeB = 5;

    median(a, b, sizeA, sizeB);

}

double median(int a[], int b[], int sizeA, int sizeB)
{
    double median;
    int size = sizeA + sizeB, combinedArray[size], temp;

    //this for loop puts array a into the first indexs of the combined array
    for (int i = 0; i < sizeA ; i++)
    {
        combinedArray[i] = a[i]; 
    }

    //this for loop puts array b into the remaining indexs
    for (int j = 0; j < sizeB; j++)
    {
        combinedArray[j+sizeA] = b[j]; //array index starts at the size of array a  
    }


    //the nested for loop below sorts the combined array in order (least to greatest)
    for (int q = 0; q < size; q++) //run for each index of the combined array
    {
        for (int b = q+1; b < size; b++) //loop through each index to the right of the index we are testing
        {
            if(combinedArray[q] > combinedArray[b]) //if any number is to the right of the index we are testing and it is smaller, swap those elements
            {
                temp = combinedArray[q];
                combinedArray[q] = combinedArray[b];
                combinedArray[b] = temp;
            }
        }  
    }

    if (size % 2 == 0)//if the array is even, add the 2 middle numbers and find the average
    {
        int indexOfFirstMiddle = floor((size/2)-1);
        int indexOfSecondMiddle = floor(size/2);
        median = (double)((combinedArray[indexOfFirstMiddle]+combinedArray[indexOfSecondMiddle]))/2;
    }
    
    else // if the array is odd, find the middle number and use it as the median
    {
        int indexOfMiddle = floor(size/2);
        median = combinedArray[indexOfMiddle];
    }

    //print results
    return median;

}

