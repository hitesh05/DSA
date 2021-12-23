#ifndef __POLY_H
#define __POLY_H

#include "Polyterm.h" 

Poly InitPoly();

void AddTerm(Poly P, unsigned long int exponent, double coefficient);
void DeleteTermByExponent(Poly P,unsigned long int exponent);

Poly AddPolynomials(const Poly P1_head,const Poly P2_head,const Poly P3_head);
Poly SubtractPolynomials(const Poly P1_head,const Poly P2_head,const Poly P3_head);
Poly GetMiddle(Poly P);

void DeleteAllTerms(Poly P_head); 
void DeletePoly(Poly P); // deletes header node also

void PrintPoly(Poly P);

#endif