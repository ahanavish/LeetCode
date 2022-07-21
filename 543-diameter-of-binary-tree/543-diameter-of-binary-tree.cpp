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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxx=0;
        int h = diameter(root, maxx);
        return maxx;
    }
    
    int diameter(TreeNode* root, int &maxx){
        if(!root)
            return 0;
        
        int left = diameter(root->left, maxx);
        int right = diameter(root->right, maxx);
        
        maxx = max(maxx, left+right);
        
        return 1+max(left, right);
    }
};