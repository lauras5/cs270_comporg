#include <stdio.h>

int BinarySearch(int item, int list[], int start, int end);

int main()
{
    // call binary search
}

int BinarySearch(int item, int list[], int start, int end)
{
    int middle = (end + start) / 2;

    if (end < start)
        return -1;
    else if (list[middle] == item)
        return middle
    else if (item < list[middle])
        /* if item is less than middle, take front of array */
        return BinarySearch(item, list, start, middle - 1);
    else
        /* if item is larger than middle, take back of array */
        return BinarySearch(item, list, middle + 1, end);
}