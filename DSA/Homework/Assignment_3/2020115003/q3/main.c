#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../hash.h"

int main(void)
{
    char *str1 = (char *)malloc(100001 * sizeof(char));
    for (int i = 0; i < 100001; i++)
    {
        str1[i] = '\0';
    }
    char *str2 = (char *)malloc(100001 * sizeof(char));
    for (int i = 0; i < 100001; i++)
    {
        str2[i] = '\0';
    }
    char *temp_str = (char *)malloc(100001 * sizeof(char));
    for (int i = 0; i < 100001; i++)
    {
        temp_str[i] = '\0';
    }

    char first_letter;
    int count = 0;

    //printf("enter the first string:\n");
    scanf("%s", str1);
    //printf("enter the second string:\n");
    scanf("%s", str2);

    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);

    int flag;
    //we will perform our operations on the smaller string
    if (len_str1 > len_str2)
    {
        swap(str1, str2);
        len_str1 = strlen(str1);
        len_str2 = strlen(str2);
        flag = 1;
    }

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
            if (isGoodString(str1, temp_str, len_str1, len_temp_str)) //strcat
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