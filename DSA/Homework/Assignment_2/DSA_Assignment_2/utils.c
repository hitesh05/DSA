#include "utils.h"

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