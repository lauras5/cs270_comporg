#include <stdio.h>
#define MAX_NUMS 10

void InsertionSort(int list[]);

int main()
{
    int index;
    int numbers[MAX_NUMS];

    printf("Enter %d numbers.\n", MAX_NUMS);
    for (int index = 0; index < MAX_NUMS; index++) {
        printf("Input number %d: ", index);
        scanf("%d", &numbers[index]);
    }

    InsertionSort(numbers);         /* call sorting routine */

    /* print sorted list */
    printf("\nThe input set, in ascending order: \n");
    for (index = 0; index < MAX_NUMS; index++)
        printf("%d\n", numbers[index]);
}

void InsertionSort(int list[])
{
    int unsorted;
    int sorted;
    int unsortedItem;

    /* 1 --> MAX_NUMS */
    for (unsorted = 1; unsorted < MAX_NUMS; unsorted++) {
        unsortedItem = list[unsorted];
        /* loops until we hit a smaller item, unsorted --> 0 */
        for (sorted = unsorted - 1; (sorted >= 0) && (list[sorted] > unsortedItem); sorted--)
            list[sorted + 1] = list[sorted];

        list[sorted + 1] = unsortedItem;    /* insert item */
     }
}

/*  2 16 69 92 15 37 92 38 82 19
    2 16 69 92 [92] 37 92 38 82 19
    2 16 69 [69] 92 37 92 38 82 19
    2 16 [16] 69 92 37 92 38 82 19
    2 [15] 16 69 92 37 92 38 82 19