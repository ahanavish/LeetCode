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
        if(!root)
            return;
        
        if(!root->left && !root->right){
            if(take==1)
                sum += root->val;
            return;
        }
        
        func(root->left, 1, sum);
        func(root->right, 0, sum);
    }
};