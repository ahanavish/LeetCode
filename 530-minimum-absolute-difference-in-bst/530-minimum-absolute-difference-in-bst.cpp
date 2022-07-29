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
    int getMinimumDifference(TreeNode* root) {
        auto ans=INT_MAX, val=-1;
        return inorder(root, val, ans);
    }
    
    int inorder(TreeNode* root, int &val, int &ans){
        if(root->left != NULL)
            inorder(root->left, val, ans);
        
        if(val>=0)
            ans = min(ans, root->val - val);
        val = root->val;
        
        if(root->right != NULL)
            inorder(root->right, val, ans);
        
        return ans;
    }
};


