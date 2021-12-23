#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hash.h"

//NOT working for large dictionaries.

char final_str[100001][33];
Array_SC_2 Array1;

int main(void)
{
    char *str = (char *)malloc(33 * sizeof(char));
    for (int i = 0; i < 33; i++)
    {
        str[i] = '\0';
    }
    int *string = (int *)calloc(33, sizeof(int));

    int table_size = 9973;

    int num_words;

    Array1 = (Array_SC_2)malloc(table_size * sizeof(HashTable_SC_2));
    assert(Array1 != NULL);
    initArray_SC_2(Array1, table_size);

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
        Insert_SC_2(Array1, value, i + 1, table_size, str);
    }

    //searching for words:
    // printf("Enter the words you want to search:\n");
    int num_words_2;
    scanf("%d", &num_words_2);

    long int count = 0;
    for (int i = 0; i < num_words_2; i++)
    {
        //char str[32];
        scanf("%s", str);
        // int string[32] = {0};

        int strln = strlen(str);
        for (int j = 0; j < strln; j++)
        {
            if (str[j] >= 'a' && str[j] <= 'z')
                string[j] = str[j] - 'a';
            else if (str[j] >= 'A' && str[j] <= 'Z')
                string[j] = str[j] - 'A';
        }

        unsigned int value = Horner(string, strln, 33, table_size);
        int x = Find_SC_2(Array1, value, table_size, str);
        if (x == -1)
        {
            for (int z = 0; z < strln; z++)
            {
                final_str[count][z] = str[z]; //ERROR
            }
            count++;
        }
    }
    printf("%ld\n", count);

    for (int i = 0; i < count + 1; i++)
    {
        for (int z = 0; z < 33; z++)
        {
            if (((char)final_str[i][z] >= 'a' && (char)final_str[i][z] <= 'z') || ((char)final_str[i][z] >= 'A' && (char)final_str[i][z] <= 'Z'))
                printf("%c", (char)final_str[i][z]);
        }
        printf("\n");
    }

    deleteTable_SC_2(Array1, table_size);

    return 0;

    // Array_SC_2 Array1;
    // int table_size = 9973; //max prime num less than 10k
    // int num_words;

    // Array1 = (Array_SC_2)malloc(table_size * sizeof(HashTable_SC_2));
    // assert(Array1 != NULL);
    // initArray_SC_2(Array1, table_size);

    // //taking input:
    // printf("Enter the number of words in the dictionary:\n");
    // scanf("%d", &num_words);

    // for (int i = 0; i < num_words; i++)
    // {
    //     char str[32]; //32 is the max len
    //     scanf("%s", str);
    //     int string[32] = {0};

    //     int strln = strlen(str);
    //     for (int j = 0; j < strln; j++)
    //     {
    //         if (str[j] >= 'a' && str[j] <= 'z')
    //             string[j] = str[j] - 'a';
    //         else
    //             string[j] = str[j] - 'A';
    //     }

    //     long long int value = Horner(string, strln, 33);
    //     Insert_SC_2(Array1, value, i + 1, table_size);
    // }

    // //searching for words:
    // printf("Enter the words you want to search:\n");
    // int num_words_2;
    // scanf("%d", &num_words_2);

    // for (int i = 0; i < num_words_2; i++)
    // {
    //     char str[32];
    //     scanf("%s", str);
    //     int string[32] = {0};

    //     int strln = strlen(str);
    //     for (int j = 0; j < strln; j++)
    //     {
    //         if (str[j] >= 'a' && str[j] <= 'z')
    //             string[j] = str[j] - 'a';
    //         else
    //             string[j] = str[j] - 'A';
    //     }

    //     long long int value = Horner(string, strln, 33);
    //     int x = Find_SC_2(Array1, value, table_size);
    //     if (x == -1)
    //         printf("%s\n", str);
    // }

    // deleteTable_SC_2(Array1, table_size);
}