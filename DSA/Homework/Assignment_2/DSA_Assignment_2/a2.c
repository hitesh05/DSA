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
int totalHeight(SearchTree T);

#endif
#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <stdlib.h>

Node* test_init_node(int data);

Node* test_bst_insert(Node* root, int data);

Node* test_findInBST(Node* root, int data);

Node* test_create_binarySearchTree();

Node* test_findInBT(Node* root, int data);

Node* test_bt_insert(Node* root, int data);

Node* test_create_binaryTree();

Node* test_bt_insertV(Node* root, int data, int l);

Node* test_create_binaryTreeV();

void test_bstsort();

void test_finddepth();

void test_height();

void test_isbst();

void test_inRange();

#endif


int main(){
    // test_bstsort();

    test_finddepth();

    // test_height();

   // test_isbst();

    // test_inRange();

    return 0;
}


int Max(int height1, int height2)
{
    if (height1 > height2)
        return height1;
    else if (height2 > height1)
        return height2;
    else
        return height2;
}

int Min(int min1, int min2)
{
    if (min1 < min2)
        return min1;
    else if (min2 < min1)
        return min2;
    else
        return min2;
}

int max_value(SearchTree T)
{
    if (T == NULL)
        return -1000000;

    int max1, max2, max, current;

    current = T->data;
    max1 = max_value(T->right);
    max2 = max_value(T->left);

    max = Max(max1, max2);

    if (current > max)
        return current;
    else
        return max;
}

int min_value(SearchTree T)
{
    if (T == NULL)
        return 1000000;

    int min1, min2, min, current;

    current = T->data;
    min1 = min_value(T->right);
    min2 = min_value(T->left);

    min = Min(min1, min2);

    if (current < min)
        return current;
    else
        return min;
}

Position MakeNode(int X)
{
    Position Temp = (Position)malloc(sizeof(Node));
    Temp->data = X;
    Temp->left = NULL;
    Temp->right = NULL;

    return Temp;
}

SearchTree Insert(SearchTree T, int X) //O(log n)
{
    if (T == NULL)
        return MakeNode(X);

    else if (X < T->data)
        T->left = Insert(T->left, X);
    else
        T->right = Insert(T->right, X);

    return T;
}

Position Find(SearchTree T, int X) //O(n)
{
    if (T == NULL)
    {
        return T;
    }
    else if (X == T->data)
    {
        return T;
    }
    else if (X < T->data)
    {
        return Find(T->left, X);
    }
    else
    {
        return Find(T->right, X);
    }
}

void bstsort(SearchTree T) //O(n)
{
    if (T != NULL)
    {
        bstsort(T->left);

        printf("%d ", T->data);

        bstsort(T->right);
    }
}

int finddepth_2(SearchTree T, SearchTree P, int depth) //O(n)
{
    int value = P->data;
    int depth2;

    if (T == NULL)
    {
        return 0;
    }
    if (value == T->data)
    {
        return depth;
    }

    depth2 = finddepth_2(T->left, P, depth + 1);
    if (depth2 != 0)
        return depth2;

    depth2 = finddepth_2(T->right, P, depth + 1);

    return depth2;
}

void finddepth(SearchTree T, SearchTree P)
{
    int depth = finddepth_2(T, P, 0);
    printf("%d\n", depth);
}

int height_2(SearchTree T) //O(n)
{
    int height_max, height_left, height_right;

    if (T == NULL)
        return -1;
    height_left = height_2(T->left);
    height_right = height_2(T->right);

    height_max = Max(height_left, height_right);

    return (height_max + 1);
}

void height(SearchTree T)
{
    int height = height_2(T);
    printf("%d\n", height);
}

int isbst_2(SearchTree T) //O(n)
{
    if (T == NULL)
        return 1;

    if (T->left)
    {
        if (T->data < max_value(T->left))
            return 0;
    }

    if (T->right)
    {
        if (T->data > min_value(T->right))
            return 0;
    }

    if (!isbst_2(T->left))
        return 0;

    else if (!isbst_2(T->right))
        return 0;

    return 1;
}

void isbst(SearchTree T)
{
    int x = isbst_2(T);
    printf("%d\n", x);
}

void inRange(Node *root, int k1, int k2) //O(n)
{
    if (root != NULL)
    {
        inRange(root->left, k1, k2);

        if (root->data >= k1 && root->data <= k2)
            printf("%d ", root->data);

        inRange(root->right, k1, k2);
    }
}

SearchTree randomBST(int N) //N = 10,50,100,1000 //O(N)
{
    SearchTree Y = NULL;
    int x;
    // time_t t;
    // srand((unsigned)time(&t));
    x = rand();

    for (int i = 0; i < N; i++)
    {

        Y = Insert(Y, x % N);
        x += 23; //confirm
    }
    return Y;
}

int totalHeight(SearchTree T)
{
    if (T == NULL)
        return 0;

    return (totalHeight(T->left) + height_2(T) + (totalHeight(T->right)));
}

void avgDepth()
{
    int M[] = {10, 50, 100, 1000}; //values of m
    int N[] = {10, 50, 100, 1000}; //values of n
    static int p = 0, q = 0;

    for (int i = 0; i < 4; i++)
    {
        int n = N[i];

        for (int j = 0; j < 4; j++) //iterating for each value of m
        {
            int m = M[j]; //initialising m
            int total_height = 0;

            for (int k = 0; k < m; k++) //running 'm' times
            {
                SearchTree Y = randomBST(n);
                total_height += totalHeight(Y);
            }
            Plot[p % 4][q] = (double)total_height / (m * n);
            p++;
        }
        q++;
    }

    FILE *fp = fopen("output.txt", "w");

    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            fprintf(fp, "%.2f ", Plot[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}


Node* test_init_node(int data){
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* test_bst_insert(Node* root, int data){
    if(root == NULL) return test_init_node(data);
    if(data < root->data) root->left = test_bst_insert(root->left, data);
    else root->right = test_bst_insert(root->right, data);
    return root;
}

Node* test_findInBST(Node* root, int data){
    if(root == NULL) return NULL;
    if(data == root->data) return root;
    if(data < root->data) return test_findInBST(root->left, data);
    return test_findInBST(root->right, data);
}

Node* test_create_binarySearchTree(){
    Node* root = NULL;
    int n;
    scanf("%d", &n);
    for(int i = 0, data; i < n; i++){
        scanf("%d", &data);
        root = test_bst_insert(root, data);
    }
    return root;
}

Node* test_findInBT(Node* root, int data){
    if(root == NULL) return NULL;
    if(data == root->data) return root;
    Node* p = test_findInBT(root->left, data);
    if(p == NULL){
        p = test_findInBT(root->right, data);
    }
    return p;
}

Node* test_bt_insert(Node* root, int data){
    if(root == NULL) return test_init_node(data);
    if(root->data == data) return root;
    if(root->left == NULL){
        root->left = test_init_node(data);
        return root->left;
    }
    root->right = test_init_node(data);
    return root->right;
}

Node* test_create_binaryTree(){
    int n;
    scanf("%d", &n);
    Node* pointers[n + 1];
    for(int i = 1; i <= n; i++){
        pointers[i] = NULL;
    }
    pointers[1] = test_bt_insert(pointers[1], 1);
    for(int i = 0, u, v; i < n - 1; i++){
        scanf("%d%d", &u, &v);
        pointers[u] = test_bt_insert(pointers[u], u);
        pointers[v] = test_bt_insert(pointers[u], v);
    }
    return pointers[1];
}

Node* test_bt_insertV(Node* root, int data, int l){
    if(root == NULL) return test_init_node(data);
    if(root->data == data) return root;
    if(!l){
        root->left = test_init_node(data);
        return root->left;
    }
    root->right = test_init_node(data);
    return root->right;
}

Node* test_create_binaryTreeV(){
    int n;
    scanf("%d", &n);
    int data[n + 1];
    Node* pointers[n + 1];
    for(int i = 1; i <= n; i++){
        scanf("%d", data + i);
        pointers[i] = NULL;
    }
    pointers[1] = test_bt_insertV(pointers[1], data[1], 0);
    for(int i = 0, u, v, l; i < n - 1; i++){
        scanf("%d%d%d", &u, &v, &l);
        pointers[u] = test_bt_insertV(pointers[u], data[u], 0);
        pointers[v] = test_bt_insertV(pointers[u], data[v], l);
    }
    return pointers[1];
}

void test_bstsort(){
    Node* root = test_create_binarySearchTree();
    bstsort(root);
}

void test_finddepth(){
    Node* root = test_create_binaryTree();
    int data;
    scanf("%d", &data);
    Node* p = test_findInBT(root, data);
    finddepth(root, p);
}

void test_height(){
    Node* root = test_create_binaryTree();
    height(root);
}

void test_isbst(){
    Node* root = test_create_binaryTreeV();
    isbst(root);
}

void test_inRange(){
    Node* root = test_create_binarySearchTree();
    int k1, k2;
    scanf("%d%d", &k1, &k2);
    inRange(root, k1, k2);
}