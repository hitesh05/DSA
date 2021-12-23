#ifndef __BINTREE_H
#define __BINTREE_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

float Plot[4][4]; //for plotting the values of avgDepth.

typedef struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Node *SearchTree;
typedef SearchTree Position;

int Max(int height1, int height2);
int Min(int min1, int min2);
int max_value(SearchTree T);
int min_value(SearchTree T);
int finddepth_2(SearchTree T, SearchTree P, int depth);
int height_2(SearchTree T);
int isbst_2(SearchTree T);

Position Find(SearchTree T, int X);
SearchTree Insert(SearchTree T, int X);

void bstsort(SearchTree T);
void finddepth(SearchTree T, SearchTree P);
void height(SearchTree T);
void isbst(SearchTree T);
void inRange(Node *root, int k1, int k2);
SearchTree randomBST(int N);
void avgDepth();
int totalHeight(SearchTree T, SearchTree P);

#endif