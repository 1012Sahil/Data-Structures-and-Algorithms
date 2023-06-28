/*QUES. Given the root of a binary tree, the value of a target node target, and an integer k, return an 
array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.*/

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
   void markParents(TreeNode *root, unordered_map<TreeNode *,TreeNode *> &parent_track)
   {
       // as to calculate k nodes form target, we will need to visit parent nodes also, we create a map that holds that mapping!
       queue<TreeNode *> q;
       q.push(root);
       while (!q.empty())
       {
           TreeNode *cur = q.front();
           q.pop();
           if (cur->left)
           {
               parent_track[cur->left] = cur;
               q.push(cur->left);
           }
           if (cur->right)
           {
               parent_track[cur->right] = cur;
               q.push(cur->right);
           }
       }
   }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *,TreeNode *> parent_track;
        markParents(root, parent_track);

        unordered_map<TreeNode *, bool> vis;
        queue<TreeNode *> q;
        q.push(target); // start bfs from target and go in k depth
        vis[target] = true;
        int curLevel = 0; 
        
        while(!q.empty())
        {
            int size = q.size();
            if (curLevel++ == k) // if curLevel exceeds k, don't go any deeper!
            break;
            while (size--) // at a time, queue will hold all nodes at distance d
            {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->left && !vis[cur->left])
                {
                    vis[cur->left] = true;
                    q.push(cur->left);
                }
                if (cur->right && !vis[cur->right])
                {
                    vis[cur->right] = true;
                    q.push(cur->right);
                }
                if (parent_track[cur] && !vis[parent_track[cur]]) // can visit parent from the mapping!
                {
                    vis[parent_track[cur]] = true;
                    q.push(parent_track[cur]);
                }
            }
        }
        vector<int> result;
        while (!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            result.push_back(cur->val);
        }
        return result;
    }
};