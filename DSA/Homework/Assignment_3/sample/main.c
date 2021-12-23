#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hash.h"

//NOT working for large dictionaries.

int table_size = 100003;

char str[32];
int string[32] = {0};
Array_LP Array1;
char final_str[100003][32];

int probes = 0;

int main(void)
{
    int num_words;

    Array1 = (Array_LP)malloc(table_size * sizeof(HashTable_LP));
    assert(Array1 != NULL);
    initArray_LP(Array1, table_size);

    //taking input:
    // printf("Enter the number of words in the dictionary:\n");
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
        probes += Insert_LP(Array1, value, i + 1, table_size, str, &probes);
    }
    printf("Average collisions[p = 32] = %.3f\n", (double)probes / num_words);

    //searching for words:
    // printf("Enter the words you want to search:\n");
    // int num_words_2;
    // scanf("%d", &num_words_2);

    // int count = 0;
    // for (int i = 0; i < num_words_2; i++)
    // {
    //     //char str[32];
    //     scanf("%s", str);
    //     // int string[32] = {0};

    //     int strln = strlen(str);
    //     for (int j = 0; j < strln; j++)
    //     {
    //         if (str[j] >= 'a' && str[j] <= 'z')
    //             string[j] = str[j] - 'a';
    //         else
    //             string[j] = str[j] - 'A';
    //     }

    //     unsigned int value = Horner(string, strln, 43, table_size);
    //     int x = Find_LP(Array1, value, table_size, str);
    //     if (x == -1)
    //     {
    //         for (int z = 0; z < strln; z++)
    //         {
    //             final_str[count][z] = str[z];
    //         }
    //         count++;
    //     }
    // }
    // printf("%d\n", count);

    // for (int i = 0; i < count + 1; i++)
    // {
    //     for (int z = 0; z < 32; z++)
    //     {
    //         if (((char)final_str[i][z] >= 'a' && (char)final_str[i][z] <= 'z') || (char)final_str[i][z] >= 'A' && (char)final_str[i][z] <= 'Z')
    //             printf("%c", (char)final_str[i][z]);
    //     }
    //     printf("\n");
    // }

    deleteTable_LP(Array1);

    return 0;
}