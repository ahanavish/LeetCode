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
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        
        int lefth = height(root->left);
        int righth = height(root->right);
        
        if(abs(lefth-righth)>1)
            return false;
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        
        if(!left || !right)
            return false;
        
        return true;
    }
    
    int height(TreeNode* node){
        if(node == NULL)
            return 0;
        
        int left = height(node->left);
        int right = height(node->right);
        return max(left, right)+1;
    }
};