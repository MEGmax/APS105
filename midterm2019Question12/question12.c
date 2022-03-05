#include <stdio.h>
#include <math.h>

void getInput(int *outFeet, int *outInches);
void printOutput(int feet, int inches, int metres, int centimetres);
void convert(int feet, int inches, int *outMetres, int *outCentimetres);
const double METRESPERFOOT = 0.3048, CENTIPERMETER = 100, INCHESPERFEET = 12;

int main ()
{
    int feet, inches;
    getInput(&feet, &inches);
    int centi, metres;
    convert (feet, inches, &metres, &centi);
    printOutput(feet, inches, metres, centi);
}

void getInput(int *outFeet, int *outInches)
{
    printf("Please enter the feet and inchs to convert: ");
    scanf("%d %d", outFeet, outInches);
}

void printOutput(int feet, int inches, int metres, int centimetres)
{
    printf("%d feet %d inches is %d metres and %d centimetres.", feet, inches, metres, centimetres);
}
void convert(int feet, int inches, int *outMetres, int *outCentimetres)
{
    double actualMetres = (METRESPERFOOT*feet) + ((inches/INCHESPERFEET)*METRESPERFOOT);
    *outMetres =  floor(actualMetres);
    *outCentimetres = (actualMetres - *outMetres)* CENTIPERMETER;
}




