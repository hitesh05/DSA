#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "complex.h"

int main()
{
    char c[10];
    int num_dimension;
    Complex C1_head = EmptyComplex(0);
    Complex C2_head = EmptyComplex(0);

    double number;

    printf("Enter operation you want to perform and dimension of the complex number(s):\n");
    scanf("%s %d", c, &num_dimension);

    if (c[0] == 'A' || c[0] == 'S' || c[0] == 'D')
    {
        printf("Enter the first complex number:\n");
        for (int i = 0; i < num_dimension; i++)
        {
            scanf("%lf", &number);
            InsertAtFront(C1_head, number);
        }

        printf("Enter the second complex number:\n");
        for (int i = 0; i < num_dimension; i++)
        {
            scanf("%lf", &number);
            InsertAtFront(C2_head, number);
        }
    }
    else
    {
        printf("Enter the complex number:\n");
        for (int i = 0; i < num_dimension; i++)
        {
            scanf("%lf", &number);
            InsertAtFront(C1_head, number);
        }
    }

    if (c[0] == 'A')
    {
        Complex C_Add = Add(C1_head, C2_head);
        printf("Complex number after addition:\n");
        printComplex(C_Add);
        printf("\n");
    }

    else if (c[0] == 'S')
    {
        Complex C_Sub = Subtract(C1_head, C2_head);
        printf("Complex number after subtraction:\n");
        printComplex(C_Sub);
        printf("\n");
    }

    else if (c[0] == 'D')
    {
        double product = Dot_Product(C1_head, C2_head);
        printf("Dot Product = %.3lf\n", product);
    }

    else
    {
        double modulus = Mod(C1_head);
        printf("Mod = %.3lf\n", modulus);
    }

    return 0;
}
