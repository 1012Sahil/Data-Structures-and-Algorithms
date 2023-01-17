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

// FINDING HEIGHT OF THE TREE
int height(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return max(height(root->left), height(root->right)) + 1;

        // TIME COMPLEXITY : O(n)
        // SPACE COMPLEXITY : O(h)
}