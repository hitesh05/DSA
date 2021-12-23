#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

typedef Node *Position;

int Max(int m, int n)
{
    if (m > n)
        return m;
    else
        return n;
}

Position makeNode(int data)
{
    Position root = (Position)malloc(sizeof(Node));

    root->data = data;
    root->height = 1;
    root->left = NULL;
    root->right = NULL;

    return root;
}

Position rightRotate(Position z) //right rotating tree rooted at right
{
    Position y = z->left;
    Position T3 = y->right;

    //swapping pointers
    y->right = z;
    z->left = T3;

    //update heights
    z->height = Max(height(z->left), (z->right)) + 1;
    y->height = Max(height(y->left), (y->right)) + 1;

    return y; //new root of Avl tree
}

Position leftRotate(Position z) //left rotating tree rooted at right
{
    Position y = z->right;
    Position T3 = y->left;

    //swapping pointers
    y->left = z;
    z->right = T3;

    //update heights
    z->height = Max(height(z->left), (z->right)) + 1;
    y->height = Max(height(y->left), (y->right)) + 1;

    return y; //new root of Avl tree
}

int getBalance(Position N)
{
    if (N == NULL)
        return 0;

    int balance = height(N->left) - height(N->right);
    return balance;
}

Position Insert(Position root, int key)
{
    if (root == NULL)
        return makeNode(key);
    else if (key < root->data)
        Insert(root->left, key);
    else if (key > root->data)
        Insert(root->right, key);
    else
        return root; //only unique elements are allowed.

    int balance = getBalance(root);

    //balancing the tree:

    //left left
    if (balance > 1 && root->left->key > key)
        return rightRotate(root);

    //right right
    if (balance < -1 && root->right->key < key)
        return leftRotate(root);

    //left right
    if (balance > 1 && key > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    //right left
    if (balance < -1 && key < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

//for deletion, we perform the standard BST delete anf then balance the tree as done in insert
struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            struct Node *temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            struct Node *temp = minValueNode(root->right);

            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main()
{
    struct Node *root = NULL;
}