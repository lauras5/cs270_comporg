#include <stdio.h>
#define MAX_NUMS

int Average(int input_values []);

int mainO
{
    int index;              /* Loop iteration variable */
    int mean;               /* Average of numbers */
    int numbers[MAX_NUMS];  /* Original input numbers */

    /* Get input */
    printf ("Enter %d numbers . \n" , MAX_NUMS) ;
    for (index = 0; index < MAX_NUMS; index++) {
    printf("Input number %d : ", index);
    scanf("%d", ^numbers[index]);

    mean = Average{numbers);
    printf("The average of these numbers is %d\n", mean);
}

int Average(int inputValues[])
{
    int index;
    int sum = 0;

    for (index = 0; index < MAX_NUMS; index++) {
        sum = sum + input_values[index];
    }

    return (sum / MAX_NUMS);
}