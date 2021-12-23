#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Polynomial.h"

int main(void)
{
    Poly Polynomial[26];
    char c[30];
    char poly_name1, poly_name2, poly_name3;
    int index1, index2, index3;
    long unsigned int exponent;
    double coefficient;

    char c1[] = "AddTerm";
    char c2[] = "AddPolynomials";
    char c3[] = "SubtractPolynomials";
    char c4[] = "DeleteTermByExponent";
    char c5[] = "GetMiddle";
    char c6[] = "DeleteAllTerms";
    char c7[] = "DeletePoly";
    char c8[] = "PrintPoly";

    for (int i = 0; i < 26; i++)
    {
        Polynomial[i] = InitPoly();
    }

    while (scanf("%s", c) != EOF)
    {
        if (!strcasecmp(c, c1))
        {
            scanf(" %c", &poly_name1);
            index1 = (int)(poly_name1 - 'A');

            scanf(" %lu %lf", &exponent, &coefficient);
            AddTerm(Polynomial[index1], exponent, coefficient);
        }

        else if (!strcasecmp(c, c2))
        {
            scanf(" %c %c %c", &poly_name1, &poly_name2, &poly_name3);
            index1 = (int)(poly_name1 - 'A');
            index2 = (int)(poly_name2 - 'A');
            index3 = (int)(poly_name3 - 'A');

            AddPolynomials(Polynomial[index1], Polynomial[index2], Polynomial[index3]);
        }

        else if (!strcasecmp(c, c3))
        {
            scanf(" %c %c %c", &poly_name1, &poly_name2, &poly_name3);
            index1 = (int)(poly_name1 - 'A');
            index2 = (int)(poly_name2 - 'A');
            index3 = (int)(poly_name3 - 'A');

            SubtractPolynomials(Polynomial[index1], Polynomial[index2], Polynomial[index3]);
        }

        else if (!strcasecmp(c, c4))
        {
            scanf(" %c", &poly_name1);
            scanf(" %lu", &exponent);

            index1 = (int)(poly_name1 - 'A');

            DeleteTermByExponent(Polynomial[index1], exponent);
        }

        else if (!strcasecmp(c, c5))
        {
            scanf(" %c", &poly_name1);
            index1 = (int)(poly_name1 - 'A');

            Poly P_Mid = GetMiddle(Polynomial[index1]);
            printf(" %.2lfx^%lu ", P_Mid->coeff, P_Mid->expo);
            printf("\n");
        }

        else if (!strcasecmp(c, c6))
        {
            scanf(" %c", &poly_name1);
            index1 = (int)(poly_name1 - 'A');

            DeleteAllTerms(Polynomial[index1]);
        }

        else if (!strcasecmp(c, c7))
        {
            scanf(" %c", &poly_name1);
            index1 = (int)(poly_name1 - 'A');

            DeletePoly(Polynomial[index1]);
        }
        else if (!strcasecmp(c, c8))
        {
            scanf(" %c", &poly_name1);
            index1 = (int)(poly_name1 - 'A');

            PrintPoly(Polynomial[index1]);
            printf("\n");
        }
        else
            printf("Invalid Input.\n");
    }

    return 0;
}