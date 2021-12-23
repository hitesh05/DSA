#ifndef __COMPLEX_H
#define __COMPLEX_H

typedef struct complex Cmp;
typedef struct complex *Complex;

struct complex    //for a complex number.
{
    double a;
    Complex next;
};

Complex InitComplex();
Complex EmptyComplex();
void InsertAtFront(Complex C_head, double number);
void printComplex(Complex C_head);

Complex Add(Complex C1_head, Complex C2_head);
Complex Subtract(Complex C1_head, Complex C2_head);
double Mod(Complex C1_head);
double Dot_Product(Complex C1_head, Complex C2_head);

void deleteList(Complex head);

#endif