#include <bits/stdc++.h>
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

// Tree Traversals

// Depth First Traversals
// FOR ALL THREE CASES :
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(h)

// INORDER
void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

// PREORDER
void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// POSTORDER
void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}

// ITERATIVE INORDER
void i_inOrder(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->key << " ";
        curr = curr->right;
    }
}

// ITERATIVE PREORDER
void i_preOrder(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s;
    s.push(root);

    while (!s.empty())
    {
        Node *curr = s.top();
        s.pop();
        cout << curr->key << " ";

        // We want to print left first so we push right first
        if (curr->right != NULL)
            s.push(curr->right);

        if (curr->left != NULL)
            s.push(curr->left);
    }
}

// Space optimised preOrder (iterative) with O(h)
void iterativePreorder(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            cout << curr->key << " ";
            if (curr->right != NULL)
                s.push(curr->right);
            curr = curr->left;
        }

        if (!s.empty())
        {
            curr = s.top();
            s.pop();
        }
    }
}

// ITERATIVE POSTORDER
/*void i_postOrder(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s;
    Node *curr = root;

    while (!s.empty() || curr != NULL)
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        cout << curr->key << " ";
        s.pop();
        curr = s.top();
        cout << curr->key << " ";
        curr = curr->right;
    }
}*/

// Breadth First Traversal
// LEVEL ORDER
// TIME COMPLEXITY : Θ(n)
// Auxiliary Space : O(n) or to be more precise Θ(w) where w is the width of binary tree
void levelOrder(Node *root)
{
    if (root == NULL)

        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->key << " ";

        if (curr->left != NULL)
            q.push(curr->left);

        if (curr->right != NULL)
            q.push(curr->right);
    }
}

// Printing level order line by line
// METHOD 1
void printLevel1(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            cout << "\n";
            q.push(NULL);
            continue;
        }
        cout << curr->key << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}

// METHOD 2
void printLevel2(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->key << " ";
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        cout << "\n";
    }
}

// Printing Left View of Binary tree
// Recursive approach using Preorder Traversal

int maxLevel = 0;
void printLeft(Node *root, int level)
{
    if (root == NULL)
        return;
    if (maxLevel < level)
    {
        cout << root->key << " ";
        maxLevel = level;
    }
    printLeft(root->left, level + 1);
    printLeft(root->right, level + 1);
}

void printLeftView(Node *root)
{
    printLeft(root, 1);
}

// Method 2 Using Iterative Level Order (similar to method 2 of line by line level order)
void printLeft(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == 0)
                cout << curr->key << " ";
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
}