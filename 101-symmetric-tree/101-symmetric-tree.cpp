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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return false;
        
        return find(root->left, root->right);
    }
    
    bool find(TreeNode* leftt, TreeNode* rightt){
        if(!leftt && !rightt)
            return true;
        if(!leftt || !rightt)
            return false;
        
        if(leftt->val != rightt->val)
            return false;
        
        return (find(leftt->left, rightt->right) && find(leftt->right, rightt->left));
    }
};