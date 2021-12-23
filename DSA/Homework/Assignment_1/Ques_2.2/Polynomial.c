#include "Polynomial.h"
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

Poly InitPoly()
{
    Poly P = (Poly)malloc(sizeof(PTerm));
    assert(P != NULL);

    P->Next = NULL;

    return P;
}

void AddTerm(Poly P, unsigned long int exponent, double coefficient)
{
    Poly T; //name of new node
    while ((P->Next != NULL) && (P->Next->expo > exponent))
        P = P->Next;

    if ((P->Next == NULL) || (P->Next->expo < exponent)) //either we are at the end of the list or we have reached the desired position.
    {
        T = InitPoly(); // Create node
        T->coeff = coefficient;
        T->expo = exponent;
        T->Next = P->Next;
        P->Next = T;
    }
    else // P->Next->expo = exponent
    {
        //UpdateTerm(P,coefficient,exponent);
        P->Next->coeff += coefficient; //we are adding the prev nad new coeff. we may also replace them.
    }

    printf("Done\n");
}

Poly AddPolynomials(const Poly P1_head, const Poly P2_head, const Poly P3_head) //we are passing the header nodes
{
    Poly P1 = P1_head->Next; //now we're into the first real node
    Poly P2 = P2_head->Next;

    P3_head->Next = InitPoly();
    Poly P3 = P3_head->Next;

    while (P1 && P2)
    {
        if (P1->expo > P2->expo)
        {
            P3->expo = P1->expo;
            P3->coeff = P1->coeff;
            P1 = P1->Next;
        }

        else if (P1->expo < P2->expo)
        {
            P3->expo = P2->expo;
            P3->coeff = P2->coeff;
            P2 = P2->Next;
        }

        else
        {
            P3->expo = P1->expo;
            P3->coeff = P1->coeff + P2->coeff;

            P1 = P1->Next;
            P2 = P2->Next;
        }

        P3->Next = InitPoly();
        P3 = P3->Next;
    }

    //Now we are at the end of one of the polynomials (either P1->Next or P2->Next== NULL)
    //but one of the polynomials still has terms remaining, so now we are going to add them to P3.

    while (P1 || P2)
    {
        if (P1 != NULL)
        {
            P3->expo = P1->expo;
            P3->coeff = P1->coeff;
            P1 = P1->Next;
        }

        else if (P2 != NULL)
        {
            P3->expo = P2->expo;
            P3->coeff = P2->coeff;
            P2 = P2->Next;
        }

        P3->Next = InitPoly();
        P3 = P3->Next;
    }

    printf("Done\n");

    return P3_head;
}

Poly SubtractPolynomials(const Poly P1_head, const Poly P2_head, const Poly P3_head) //we are passing the header nodes
{
    Poly P1 = P1_head->Next; //now we're into the first real node
    Poly P2 = P2_head->Next;

    P3_head->Next = InitPoly();
    Poly P3 = P3_head->Next;

    while (P1 && P2)
    {
        if (P1->expo < P2->expo)
        {
            P3->expo = P1->expo;
            P3->coeff = P1->coeff;
            P1 = P1->Next;
        }

        else if (P1->expo > P2->expo)
        {
            P3->expo = P2->expo;
            P3->coeff = P2->coeff;
            P2 = P2->Next;
        }

        else
        {
            P3->expo = P1->expo;
            P3->coeff = P1->coeff - P2->coeff;
            P1 = P1->Next;
            P2 = P2->Next;
        }

        P3->Next = InitPoly();
        P3 = P3->Next;
    }

    while (P1 || P2)
    {
        if (P1)
        {
            P3->expo = P1->expo;
            P3->coeff = P1->coeff;
            P1 = P1->Next;
        }

        else if (P2)
        {
            P3->expo = P2->expo;
            P3->coeff = P2->coeff;
            P2 = P2->Next;
        }

        P3->Next = InitPoly();
        P3 = P3->Next;
    }

    printf("Done\n");

    return P3_head;
}

void DeleteTermByExponent(Poly P, unsigned long int exponent) //P is the header node
{
    Poly curr_node, delete_node;
    int flag = 0;

    while (P->Next)
    {
        if (P->Next->expo == exponent) //we match the exponent to locate the term.
        {
            flag = 1;
            curr_node = P;
            delete_node = P->Next;

            curr_node->Next = delete_node->Next;
            free(delete_node);
            break;
        }
        else
        {
            P = P->Next;
        }
    }

    if (flag == 0)
    {
        printf("The term does not exist.\n");
    }

    else
    {
        printf("Done\n");
    }
}

void DeleteAllTerms(Poly P_head)
{
    Poly P = P_head->Next;

    while (P)
    {
        P->coeff = 0;
        P = P->Next;
    }

    printf("Done\n");
}

void DeletePoly(Poly P) //P is the header node
{
    Poly curr_node, delete_node;

    while (P->Next)
    {
        curr_node = P;
        delete_node = P->Next;

        curr_node->Next = delete_node->Next;
        free(delete_node);

        //P = P->Next;
    }
    free(P);

    printf("Done\n");
}

Poly GetMiddle(Poly P)
{
    int count_1 = -1, count_2 = 0, count_req;
    Poly curr_node;

    for (Poly curr_node = P; curr_node != NULL; curr_node = curr_node->Next)
    {
        count_1++;
    }

    count_req = ceil((count_1 + 1) / 2);

    while (count_2 != count_req)
    {
        P = P->Next;
        count_2++;
    }

    if (count_2 == count_req)
    {
        return P;
    }
}

void PrintPoly(Poly P) //P is the header node.
{
    int flag = 0;

    if (P == NULL)
    {
        printf("The polynomial does not exist\n");
        return;
    }

    for (Poly cnode = P; cnode != NULL; cnode = cnode->Next)
    {
        if (cnode == P)
        {
            continue;
        }
        else
        {
            if (cnode->coeff == 0)
            {
                continue;
            }
            else
            {
                printf(" %.2lfx^%lu ", cnode->coeff, cnode->expo);
                flag = 1;
            }

            if (cnode->Next)
            {
                if (cnode->Next->coeff > 0)
                {
                    printf("+");
                }
            }
        }
    }
    if (flag == 0)
        printf("0\n");
    printf("\n");
}