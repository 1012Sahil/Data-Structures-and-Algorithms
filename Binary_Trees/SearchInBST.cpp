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

// Recursive solution
bool search(Node *root, int x)
{
    if (root == NULL)
        return false;
    if (root->key == x)
        return true;
    else if (root->key > x)
    {
        return search(root->left, x);
    }
    else
    {
        return search(root->right, x);
    }
}

// Iterative Solution
bool i_search(Node *root, int x)
{
    while (root != NULL)
    {
        if (root->key == x)
            return true;
        else if (root->key < x)
            root = root->right;
        else
            root = root->left;
    }
    return false;
}

// Finding floor of a number in BST - greatest smaller value
Node *floor(Node *root, int x){
    Node *res=NULL;
    while(root!=NULL){
        if(root->key==x)
            return root;
        else if(root->key>x)
            root=root->left;
        else{
            res=root;
            root=root->right;
        }
    }
    return res;
}

// Finding ceil of a number in BST - least greater value
Node *ceil(Node *root, int x){
    Node *res=NULL;
    while(root!=NULL){
        if(root->key==x)
            return root;
        else if(root->key<x)
            root=root->right;
        else{
            res=root;
            root=root->left;
        }
    }
    return res;
}