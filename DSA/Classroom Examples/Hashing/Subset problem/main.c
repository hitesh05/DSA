#include <stdio.h>
#include <stdlib.h>
#include "subset.h"

int main(void)
{
    HashTable *Array1;
    HashTable *Array2;

    Array1 = malloc(10 * sizeof(Table));
    Array2 = malloc(10 * sizeof(Table));
    // printf("%ld\n",sizeof(Array));

    initArray(Array1);
    initArray(Array2);

    Insert(Array1, 54);
    printf("%d", Array1[4].NextPtr->value);

    return 0;
}