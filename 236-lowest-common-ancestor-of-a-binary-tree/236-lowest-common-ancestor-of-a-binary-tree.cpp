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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return postorder(root, p, q);
    }
    
    TreeNode* postorder(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL || root==p || root==q)
            return root;
        
        TreeNode* left_node=postorder(root->left, p, q);
        TreeNode* right_node=postorder(root->right, p, q);
        
        if(left_node == NULL) 
            return right_node;
        else if(right_node == NULL) 
            return left_node;
        else 
            return root;
    }
};