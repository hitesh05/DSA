#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hash.h"

Array_SC_2 Array1;
Array_SC_2 Array2;

int main(void)
{
    char *str = (char *)malloc(33 * sizeof(char));
    for (int i = 0; i < 33; i++)
    {
        str[i] = '\0';
    }
    int *string = (int *)calloc(33, sizeof(int));
    int table_size = 4003;
    int num_words;
    double collisions_33 = 0;
    double collisions_32 = 0;

    Array1 = (Array_SC_2)malloc(table_size * sizeof(HashTable_SC_2));
    assert(Array1 != NULL);
    initArray_SC_2(Array1, table_size);

    printf("Enter num of words:\n");
    scanf("%d", &num_words);

    for (int i = 0; i < num_words; i++)
    {
        scanf("%s", str);

        int strln = strlen(str);
        for (int j = 0; j < strln; j++)
        {
            if (str[j] >= 'a' && str[j] <= 'z')
                string[j] = str[j] - 'a';
            else
                string[j] = str[j] - 'A';
        }

        unsigned int value = Horner(string, strln, 33, table_size);
        collisions_33 += Insert_SC_2(Array1, value, i + 1, table_size, str);
    }

    deleteTable_SC_2(Array1, table_size);

    printf("Average collisions[p = 33] = %.3f\n", (double)collisions_33 / num_words);

    Array2 = (Array_SC_2)malloc(table_size * sizeof(HashTable_SC_2));
    assert(Array2 != NULL);
    initArray_SC_2(Array2, table_size);

    printf("Enter num of words:\n");
    scanf("%d", &num_words);

    for (int i = 0; i < num_words; i++)
    {
        scanf("%s", str);

        int strln = strlen(str);
        for (int j = 0; j < strln; j++)
        {
            if (str[j] >= 'a' && str[j] <= 'z')
                string[j] = str[j] - 'a';
            else
                string[j] = str[j] - 'A';
        }

        unsigned int value = Horner(string, strln, 32, table_size);
        collisions_32 += Insert_SC_2(Array1, value, i + 1, table_size, str);
    }

    printf("Average collisions[p = 32] = %.3f", (double)collisions_32 / num_words);

    deleteTable_SC_2(Array2, table_size);
    free(str);
    free(string);

    return 0;
}