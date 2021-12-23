#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

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
