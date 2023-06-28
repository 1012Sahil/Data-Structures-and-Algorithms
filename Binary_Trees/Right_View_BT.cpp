/* QUES Given the root of a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.

Similarly, left view, bottom view and top view can be solved.*/ 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode *root, int level, vector<int> &ans)
 {
     if (root == NULL)
     return;
     
     if (level == ans.size())
     {
         ans.push_back(root->val);
     }
     solve(root->right, level + 1, ans);
     solve(root->left, level + 1, ans);
 }

    vector<int> rightSideView(TreeNode* root) {
        // the first node from rigth on each level of tree will be part of right view!
    // Go from root, search right, if fail, search left part -> so postOrder!
    // we will keep track of level, note that we will onlu take item when level == ans.size()
    // Start from beginning, level = 0, ans.size() == 0, so we take the root->data and proceed further
    // Then we only add those elements that come first in level, which will be when ans.size() == level
    // if we have to go back, we will ignore other elements as we have already taken the leftmost node of this level!
    vector<int> ans;
    solve(root, 0, ans);
    return ans;
    }
};