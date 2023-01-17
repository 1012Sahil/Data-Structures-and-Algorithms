#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;

    Node(int k)
    {
        key = k;
        left = NULL;
        right = NULL;
    }
};

// Print nodes at k distance
void printKDist(Node *root, int k)
{
    if (root == NULL)
        return;

    if (k == 0)
    {
        cout << root->key << " ";
    }
    else
    {
        printKDist(root->left, k - 1);
        printKDist(root->right, k - 1);
    }
}

// Find size of binary tree
int sizeOfTree(Node *root)
{
    if (root == NULL)
        return 0;

    else
        return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
}

// Find max in binary tree
int maxInTree(Node *root)
{
    if (root == NULL)
        return INT_MIN;
    else
        return max(root->key, max(maxInTree(root->left), maxInTree(root->right)));
}