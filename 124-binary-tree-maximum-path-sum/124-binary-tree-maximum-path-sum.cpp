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
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        func(root, ans);
        return ans;
    }
    
    int func(TreeNode* root, int &ans){
        if(root == NULL)
            return 0;
        
        int left_sum = max(0, func(root->left, ans));
        int right_sum = max(0, func(root->right, ans));
        
        ans = max(ans, left_sum+right_sum+root->val);
        return max(left_sum, right_sum) + root->val;
    }
};