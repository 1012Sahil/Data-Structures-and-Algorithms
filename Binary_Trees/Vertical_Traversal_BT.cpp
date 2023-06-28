/* QUES. Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) 
and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index 
starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the
same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.*/

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
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        // instead of using a multiset, one can use PQ, to allow multiple nodes with same values to be stored
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        // we are going to store the node's value in the vertical yth key of map at the level xth key of the internal map in a multiset!
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode *node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(node->val);
            if (node->left)
            {
                q.push({node->left, {x - 1, y + 1}}); // x is vertical no and y is row number
            }
            if (node->right)
            {
                q.push({node->right, {x + 1, y + 1}});
            }
        }

        for (auto p : nodes) // map stores key in sorted order! Hence we shouldn't use an unordered map here!
        {
            vector<int> col;
            for (auto k : p.second) // multiset also stores value in sorted order, so we fulfill this demand from ques also. <There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.>
            {
                col.insert(col.end(), k.second.begin(), k.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};