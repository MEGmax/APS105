#include <stdio.h>
#include <math.h>
void longestSequence(int a[], int sizeA);

int main (void)
{
    int ar1[] = { 1};
    

  longestSequence(ar1,1);


    return 0;
}

void longestSequence(int a[], int sizeA){
int startIndex,numElem=0, highestIndex,highestCount=0;
    for(int i=0;i<(sizeA-1);i++)//this loop repeats from index zero to the second last index 
    {
            if(a[i+1]>a[i]) 
            //this 'if' is true if the next elem is greater than the value at the current index, 
            //thus counting this as one instance of increase, saving the index we began increasing 
            //and incrementing the instance counter
            {
              
                if(numElem>0) 
                // if the instances of increase are greater than 0 then it only increments 
                //the increase instance counter, not reestablishing the start index
                {
                    numElem++;
                }

                else
                //if the number of increases was zero then start index is saved aswell as the instance of increase incremented
                {
                    startIndex=i;
                    numElem++;
                }
            }

           else
           //if the following value is not greater than the current at a[i] then increasign has stopped, 
           //requiriing us to reset the counter, and letting the start index be overwritten
           { 
               if(highestCount<numElem)  //if number of elements in this sequence just broken is higher than any previous sequence then 
               //the starting index and largest sequence count are stored in highestIndex and highestCount, respectively, and increase instant 
               //counter is reset to zero
               {
                   highestCount = numElem;
                   highestIndex=startIndex;
                   numElem=0;
               } 
               else // if the current sequence is shorter than a previous sequence then the counter is reset and the index will be overwritten
               {            
                   numElem=0;
               } 
            }

    }

    if (highestCount==0&&numElem>0) // if the array had only one sequence of increase and never decreased before the end of the array then the 
    //highestCount would still equal zero but the numElements counter would be greater than zero, so we will then set the staring index and instance 
    //counter to highest index and counter respectively
    {
        highestCount=numElem;
        highestIndex=startIndex;
    }


if (highestCount>0) // if the number of repetitions is greater than zero then there is atleast one instance of increase, printing them
{
    printf("Longest sequence is");
    for(int i=highestIndex;i<=(highestIndex+highestCount);i++)// this loop will repeat over the section of the array which contains the longest sequence, using a sequence floor and the number of elements in the sequence
    {
        printf(" %d",a[i]);

            if(i<(highestIndex+highestCount)) // there are more numbers in the sequence still to be printed, thus a comma must seperate the preceding from the following number
            {printf(",");}
            else // i must equal (highestIndex+highestCount), thus it has printed the last number in the list and now needs a period
            {printf(".");}
       
    }
}
else //no instances of increase
{printf("no increasing numbers");}
    
    
}