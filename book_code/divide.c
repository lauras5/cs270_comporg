#include <stdio.h>

int IntDivide(int x, int y, int *quoPtr, int *remPtr); // quotient and remainder ptr to update

int main()
{
    int dividend;
    int divisor;
    int quotient;
    int remainder;
    int error;

    printf("Input dividend: ");
    scanf("%d", &dividend);
    printf("Input divisor: ");
    scanf("%d", &divisor);

    error = IntDivide(dividend, divisor, &quotient, &remainder);

    if(!error)
        printf("Answer: %d remainder %d\n", quotient, remainder);
    else
        printf("IntDivide failed.\n");
}

int IntDivide(int x, int y, int *quoPtr, int *remPtr)
{
    if (y != 0) {
        *quoPtr = x / y;
        *remPtr = x % y;
        return 0;
    }

    return -1;
}