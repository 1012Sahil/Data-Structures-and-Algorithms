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

// Space optimized preOrder (iterative) with O(h)
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

// All traversals in one pass!
void allTraversal(Node* root)
{
    // Stores preorder traversal
    vector<int> pre;
 
    // Stores inorder traversal
    vector<int> post;
 
    // Stores postorder traversal
    vector<int> in;
 
    // Stores the nodes and the order
    // in which they are currently visited
    stack<pair<Node*, int> > s;
 
    // Push root node of the tree
    // into the stack
    s.push(make_pair(root, 1));
 
    // Traverse the stack while
    // the stack is not empty
    while (!s.empty()) {
 
        // Stores the top
        // element of the stack
        pair<Node*, int> p = s.top();
 
        // If the status of top node
        // of the stack is 1
        if (p.second == 1) {
 
            // Update the status
            // of top node
            s.top().second++;
 
            // Insert the current node
            // into preorder, pre[]
            pre.push_back(p.first->data);
 
            // If left child is not NULL
            if (p.first->left) {
 
                // Insert the left subtree
                // with status code 1
                s.push(make_pair(
                    p.first->left, 1));
            }
        }
 
        // If the status of top node
        // of the stack is 2
        else if (p.second == 2) {
 
            // Update the status
            // of top node
            s.top().second++;
 
            // Insert the current node
            // in inorder, in[]
            in.push_back(p.first->data);
 
            // If right child is not NULL
            if (p.first->right) {
 
                // Insert the right subtree into
                // the stack with status code 1
                s.push(make_pair(
                    p.first->right, 1));
            }
        }
 
        // If the status of top node
        // of the stack is 3
        else {
 
            // Push the current node
            // in post[]
            post.push_back(p.first->data);
 
            // Pop the top node
            s.pop();
        }
    }
 
    cout << "Preorder Traversal: ";
    for (int i = 0; i < pre.size(); i++) {
        cout << pre[i] << " ";
    }
    cout << "\n";
 
    // Printing Inorder
    cout << "Inorder Traversal: ";
 
    for (int i = 0; i < in.size(); i++) {
        cout << in[i] << " ";
    }
    cout << "\n";
 
    // Printing Postorder
    cout << "Postorder Traversal: ";
 
    for (int i = 0; i < post.size(); i++) {
        cout << post[i] << " ";
    }
    cout << "\n";
}
 

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
