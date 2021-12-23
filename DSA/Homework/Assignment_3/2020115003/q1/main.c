#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../hash.h"

int table_size, tests;
char b3;

int main(void)
{
    char c1[] = "linear-probing";
    char c2[] = "quadratic-probing";
    char c3[] = "separate-chaining";

    char b1[] = "+";
    char b2[] = "?";

    //printf("%s",b1);

    char c4[20];
    scanf("%s", c4);

    if (!strcasecmp(c3, c4))
    {
        //separate chaining
        Array_OC_1 Array1;

        scanf("%d", &table_size);
        scanf("%d", &tests);
        int num_elems = 0;

        Array1 = (Array_OC_1)malloc(table_size * sizeof(HashTable_OC_1));
        initArray_OC_1(Array1, table_size);

        for (int k = 0; k < tests; k++)
        {
            //char b3;
            scanf("%s", &b3);

            if (!strcasecmp(b1, &b3))
            {
                int n;
                scanf("%d", &n);
                num_elems++;
                Insert_OC_1(Array1, n, num_elems, table_size);
            }

            //printf("Separting chaining probes = %d\n", probes_OC_1);
            else if (!strcasecmp(b2, &b3))
            {
                int n;
                scanf("%d", &n);
                int count = Find_OC_1(Array1, n, table_size);
                printf("%d\n", count);
            }
        }
        deleteTable_OC_1(Array1, table_size);
    }

    if (!strcasecmp(c1, c4))
    {
        //separate chaining
        Array_LP Array2;

        scanf("%d", &table_size);
        scanf("%d", &tests);
        int num_elems = 0;

        Array2 = (Array_LP)malloc(table_size * sizeof(HashTable_LP));
        initArray_LP(Array2, table_size);

        for (int k = 0; k < tests; k++)
        {
            //char b3;
            scanf("%s", &b3);

            if (!strcasecmp(b1, &b3))
            {
                int n;
                scanf("%d", &n);
                num_elems++;
                Insert_LP(Array2, n, num_elems, table_size);
            }

            //printf("Separting chaining probes = %d\n", probes_OC_1);
            else if (!strcasecmp(b2, &b3))
            {
                int n;
                scanf("%d", &n);
                int count = Find_LP(Array2, n, table_size);
                printf("%d\n", count);
            }
        }
        deleteTable_LP(Array2);
    }

    if (!strcasecmp(c2, c4))
    {
        //separate chaining
        Array_QP_1 Array3;

        scanf("%d", &table_size);
        scanf("%d", &tests);
        int num_elems = 0;

        Array3 = (Array_QP_1)malloc(table_size * sizeof(HashTable_QP_1));
        initArray_QP_1(Array3, table_size);

        for (int k = 0; k < tests; k++)
        {
            //char b3;
            scanf("%s", &b3);

            if (!strcasecmp(b1, &b3))
            {
                int n;
                scanf("%d", &n);
                num_elems++;
                Insert_QP_1(Array3, n, num_elems, table_size);
            }

            //printf("Separting chaining probes = %d\n", probes_OC_1);
            else if (!strcasecmp(b2, &b3))
            {
                int n;
                scanf("%d", &n);
                int count = Find_QP_1(Array3, n, table_size);
                printf("%d\n", count);
            }
        }
        deleteTable_QP_1(Array3);
    }
    //Linear probing
    // Array_LP Array2;
    // double probes_LP_1 = 0;

    // Array2 = (Array_LP)malloc(table_size * sizeof(HashTable_LP));
    // initArray_LP(Array2, table_size);

    // int iteration = 0;
    // for (int i = 1; i < 100; i += 10)
    // {
    //     iteration++;
    //     Insert_LP_1(Array2, i, iteration, table_size);
    // }

    // printf("Linear probing average probes = %.2lf\n", (double)probes_LP_1 / iteration);
    // deleteTable_LP_1(Array2);

    // //Quadratic probing:
    // Array_QP_1 *Array3;
    // double probes_QP_1 = 0;

    // *Array3 = (Array_QP_1)malloc(table_size * sizeof(HashTable_QP_1));
    // initArray_QP_1(Array3, table_size);

    // int iteration2 = 0;
    // for (int i = 1; i < 100; i += 10)
    // {
    //     iteration2++;
    //     probes_QP_1 += Insert_QP_1(Array3, i, iteration, table_size);
    // }

    // printf("Quadratic probing average probes = %.2lf\n", (double)probes_QP_1 / iteration);
    // deleteTable_QP_1(Array3);

    return 0;
}