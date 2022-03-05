#include <stdio.h>

void triangle (int);
int choose (int, int);
int factorial (int);


int main (void)
{   
    //main method given
    int rows;
    do {
        printf("Enter the number of rows: ");
        scanf("%d", &rows);

        if (rows >= 0) {
            triangle(rows);
        }
    } while (rows >= 0);

  return 0;
    
}

int choose(int num, int r) {
  int c = factorial(num)/(factorial(r)*factorial(num-r));
  return c;
}

  int factorial(int num) {
    for(int i=num-1;i>0;i--) {
      num=num*i;
    }
    if (num==0) {
      num=1;
    }
    return num;
  }

  void triangle (int totalNumberOfRows) {
    for (int rowON = 1; rowON <= totalNumberOfRows; rowON++){    
      for (int spaces=1; spaces <= totalNumberOfRows-rowON; spaces++) {
        printf("   "); 
        }

        for (int r = rowON-1; r >= 0; r--){
           printf("%-6d", choose(rowON-1, r));
        }

        printf("\n");
    }

}