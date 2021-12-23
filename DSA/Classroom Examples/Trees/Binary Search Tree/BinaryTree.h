#ifndef __BINTREE_H
#define __BINTREE_H

typedef int ElementType;
typedef struct TreeNode *SearchTree;
typedef SearchTree Position;

struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

SearchTree Insert(SearchTree T,ElementType X);
SearchTree Delete(SearchTree T, ElementType X);
Position minValue(Position Node);

Position Find(SearchTree T,ElementType X);

#endif