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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector <string> ans;
        func(to_string(root->val), root, ans);
        return ans;
    }
    
    void func(string s, TreeNode* root, vector<string> &ans){ 
        if(!root->left && !root->right){
            ans.push_back(s);
            return;
        }
            
        if(root->left)
            func(s+"->"+to_string(root->left->val), root->left, ans);
        if(root->right)
            func(s+"->"+to_string(root->right->val), root->right, ans);
    }
};