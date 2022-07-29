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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        func(root, 0, sum);
        return sum;
    }
    
    void func(TreeNode* root, int take, int &sum){
        if(take==1 && !root->left && !root->right){
            sum += root->val;
            return;
        }
        
        if(root->left)
            func(root->left, 1, sum);
        
        if(root->right)
            func(root->right, 0, sum);
    }
};