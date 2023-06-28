/*QUES. Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost 
non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

 */

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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,int> > q;
        q.push({root,0});
        int ans = 0;

        while(!q.empty()){
            int size = q.size();
            int minn = q.front().second;
            int first = 0;
            int last = 0;
            for(int i=0;i<size;i++){
            long currIndex = q.front().second - minn;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = currIndex;
                if(i==size- 1) last = currIndex;

                if(node->left){
                    q.push({node->left,2*currIndex+1});
                }
                if(node->right){
                    q.push({node->right,2*currIndex+2});
                }
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};