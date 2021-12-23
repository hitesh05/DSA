#include "Polynomial.h"
#include <assert.h>
#include <stdlib.h>

Poly InitPoly()
{
    Poly P = (Poly)malloc(sizeof(PTerm));
    assert(P != NULL);

    P->Next = NULL;

    return P;
}

void AddTerm(Poly P, double coefficient, unsigned long int exponent)
{
    Poly T; //name of new node
    while ((P->Next != NULL) && (P->Next->expo < exponent))
        P = P->Next;

    if ((P->Next == NULL) || (P->Next->expo > exponent))
    {
        T = InitPoly(); // Create node
        T->coeff = coefficient;
        T->expo = exponent;
        //T->Next = NULL;
        T->Next = P->Next;
        P->Next = T;
    }
    else // P->Next->expo = exponent
    {
        //UpdateTerm(P,coefficient,exponent);
        P->Next->coeff += coefficient; //we are adding the prev nad new coeff. we may also replace them.
    }
}

Poly PolyAdd(const Poly P1, const Poly P2) //incomplete
{
    Poly P_Add;

    while (P1->Next != NULL && P2->Next != NULL)
    {
        if (P1->Next > P2->Next)
        {
            P_Add->expo = P1->expo;
            P_Add->coeff = P1->coeff;
            P1 = P1->Next;
        }

        else if (P1->Next < P2->Next)
        {
            P_Add->expo = P2->expo;
            P_Add->coeff = P2->coeff;
            P2 = P2->Next;
        }
    }
    // P_Add->expo = P1->expo;
    // P_Add->coeff = P1->coeff + P2->coeff;

    return P_Add;
}
