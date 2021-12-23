#include "complex.h"
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <math.h>

Complex InitComplex()
{
    Complex C = (Complex)malloc(sizeof(Cmp));
    assert(C != NULL);

    C->next = NULL;

    return C;
}

Complex EmptyComplex()
{
    Complex C = InitComplex();
    C->a = 0;
    C->next = NULL;

    return C;
}

void InsertAtFront(Complex C_head, double number)
{
    Complex C = InitComplex();

    if (C_head->next == NULL)
    {
        C_head->next = C;
        C->a = number;
    }
    else
    {
        C->next = C_head->next;
        C_head->next = C;
        C->a = number;
    }
}

void printComplex(Complex C_head)
{
    for (Complex cnode = C_head; cnode != NULL; cnode = cnode->next)
    {
        if (cnode == C_head)
        {
            continue;
        }
        else
        {
            printf("%.2lf ", cnode->a);
        }
    }
}

Complex Add(Complex C1_head, Complex C2_head)
{
    Complex C_Add_head = EmptyComplex();

    while (C1_head->next && C2_head->next)
    {
        Complex C_Add = InitComplex();

        if (C_Add_head->next == NULL)
        {
            C_Add_head->next = C_Add;
            C_Add->a = C1_head->next->a + C2_head->next->a;
        }
        else
        {
            C_Add->next = C_Add_head->next;
            C_Add_head->next = C_Add;
            C_Add->a = C1_head->next->a + C2_head->next->a;
        }

        C1_head = C1_head->next;
        C2_head = C2_head->next;
    }

    return C_Add_head;
}

Complex Subtract(Complex C1_head, Complex C2_head)
{
    Complex C_Sub_head = EmptyComplex();

    while (C1_head->next && C2_head->next)
    {
        Complex C_Sub = InitComplex();

        if (C_Sub_head->next == NULL)
        {
            C_Sub_head->next = C_Sub;
            C_Sub->a = C1_head->next->a - C2_head->next->a;
        }
        else
        {
            C_Sub->next = C_Sub_head->next;
            C_Sub_head->next = C_Sub;
            C_Sub->a = C1_head->next->a - C2_head->next->a;
        }

        C1_head = C1_head->next;
        C2_head = C2_head->next;
    }

    return C_Sub_head;
}

double Mod(Complex C1_head)
{
    double sum = 0, modulus;

    while (C1_head->next != NULL)
    {
        sum += pow(C1_head->a, 2);
        C1_head = C1_head->next;
    }

    if (C1_head->next == NULL)
    {
        sum += pow(C1_head->a, 2);
        C1_head = C1_head->next;
    }

    modulus = pow(sum, 0.5);

    return modulus;
}

double Dot_Product(Complex C1_head, Complex C2_head)
{
    double product = 0;

    while (C1_head != NULL && C2_head != NULL)
    {
        product += (C1_head->a) * (C2_head->a);
        C1_head = C1_head->next;
        C2_head = C2_head->next;
    }

    return product;
}

void deleteList(Complex head)
{
    Complex current, Next;

    while (head->next != NULL)
    {
        current = head;
        Next = head->next;

        current->next = Next->next;
        free(Next);
    }

    free(head);
}