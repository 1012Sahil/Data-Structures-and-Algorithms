/* QUES. Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between 
two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to 
be a descendant of itself).”*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if any one of our nodes is found, we return that node, or if if reach NULL, we return NULL
        if (root == NULL || root == p || q == root)
        return root;
        // search left and right parts
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        // We return a valid node if we have found either p or q, and only that, until we reach a node that has left and right both, as this must be the LCA, so we return this node!
        // if left is NULL, return right, even if it is NULL
        // if left is not NULL but right is NULL, return left,
        // But if both of them are not NULL, we have found our LCA
        if (left == NULL)
        return right;
        else if (right == NULL)
        return left;
        else
        return root;
    }
};