#include <stdio.h>

int main()
{
    int * ptr;
    int i = 5;
    *ptr = i;
    printf("%p %d",(void *) ptr, i);

    return 0;
}