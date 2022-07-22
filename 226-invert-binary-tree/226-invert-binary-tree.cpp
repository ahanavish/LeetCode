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
    TreeNode* invertTree(TreeNode* root) {      
        func(root);
        return root;
    }
    
    void func(TreeNode* root){
        if(!root)
            return;
        
        func(root->left);
        TreeNode* left = root->left;
        func(root->right);
        TreeNode* right = root->right;
        root->left = right;
        root->right = left;
    }
};