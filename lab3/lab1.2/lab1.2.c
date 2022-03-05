#include <stdio.h>

int main (void)
{
int days;
double rate;
int freeDays = 0;
double total;
printf("Enter the daily rate: Enter the rental period (in days): ");
scanf("%lf %d", &rate, &days);

freeDays = days/4;

printf("\nYour total free day(s) in this rental is: %d\n", freeDays);
total = ((days-freeDays) * rate) * 1.13;
printf("Your total charge including taxes is: %.2f", total);

return 0;
}