#ifndef __3_H
#define __3_H

void swap(char str1[100001], char str2[100001]);
int isGoodString(char main_str[100001], char sec_str[100001], int len_main, int len_sec);

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "3.h"

void swap(char str1[100001], char str2[100001])
{
    char *temp = (char *)malloc(100001 * sizeof(char));

    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);

    free(temp);
}

int isGoodString(char main_str[100001], char sec_str[100001], int len_main, int len_sec)
{
    if ((len_main % len_sec) != 0)
        return 0;

    char *str3 = (char *)malloc(100001 * sizeof(char));

    int quotient = len_main / len_sec;

    for (int i = 0; i < quotient; i++)
    {
        strcat(str3, sec_str);
    }

    if (!strcmp(main_str, str3))
    {
        return 1;
    }

    free(str3);
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
//#include "3.h"

int main(void)
{
    char *str1 = (char *)malloc(100001 * sizeof(char));
    char *str2 = (char *)malloc(100001 * sizeof(char));
    char *temp_str = (char *)malloc(100001 * sizeof(char));

    char first_letter;
    int count = 0;

    //printf("enter the first string:\n");
    scanf("%s", str1);
    //printf("enter the second string:\n");
    scanf("%s", str2);

    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);

    //we will perform our operations on the smaller string
    if (len_str1 > len_str2)
        swap(str1, str2);

    first_letter = str1[0];

    for (int i = 1; i < len_str1; i++)
    {
        if (first_letter == str1[i])
        {
            for (int j = 0; j < i; j++)
            {
                temp_str[j] = str1[j];
            }

            int len_temp_str = strlen(temp_str);
            if (isGoodString(str1, temp_str, len_str1, len_temp_str))
            {
                if (isGoodString(str2, temp_str, len_str2, len_temp_str))
                    count++;
            }
        }
    }

    if (isGoodString(str2, str1, len_str2, len_str1))
        count++;

    printf("%d\n", count);

    free(str1);
    free(str2);
    free(temp_str);

    return 0;
}