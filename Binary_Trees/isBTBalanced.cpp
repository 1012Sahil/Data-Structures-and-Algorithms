#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

int height(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return (1 + max(height(root->left), height(root->right)));
}

// Naive approach with Time Complexity : O(n^2)
bool isBalanced(Node *root)
{
    if (root == NULL)
        return true;
    int lh = height(root->left);
    int rh = height(root->right);
    return (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right));
}

// Efficient approach with Time Complexity : O(n)
int e_isBalanced(Node *root)
{
    if (root == NULL)
        return 0;
    int lh = e_isBalanced(root->left);
    if (lh == -1)
        return -1;
    int rh = e_isBalanced(root->right);
    if (rh == -1)
        return -1;
        // check if difference of height of left and right subtree of every node is <= 1 or not
        // we can do this in O(N) by making sure that we return a positive height only if subtree is 
        // balanced, else return -1 to indicate unbalanced tree!
    if (abs(lh - rh) > 1)
        return -1;
    else
        return max(lh, rh) + 1;
}