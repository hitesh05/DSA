#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "3.h"

void swap(char str1[100000], char str2[100000])
{
    char *temp = (char *)malloc(100000 * sizeof(char));

    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);

    free(temp);
}

int isGoodString(char main_str[100000], char sec_str[100000], long int len_main, long int len_sec)
{
    if ((len_main % len_sec) != 0)
        return 0;

    char *str3 = (char *)malloc(len_main * sizeof(char));

    long int quotient = len_main / len_sec;
    int z = 0;

    for (long int i = 0; i < quotient; i++)
    {
        strcat(str3, sec_str);
        //for (int j = 0; j < len_sec; j++)
        // {
        //     str3[z] = sec_str[j];
        //     z++;
        // }
    }

    if (!strcmp(main_str, str3))
    {
        free(str3);
        return 1;
    }

    return 0;
}