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
        long ans = 0; 
        queue<pair<TreeNode*, long>> q; q.emplace(root, 0); 
        while (q.size()) {
            ans = max(ans, q.back().second - q.front().second + 1); 
            int offset = q.front().second; 
            for (int sz = q.size(); sz; --sz) {
                auto [node, x] = q.front(); q.pop(); 
                x -= offset; 
                if (node->left) q.emplace(node->left, 2*x); 
                if (node->right) q.emplace(node->right, 2*x+1); 
            }
        }
        return ans; 
    }
};