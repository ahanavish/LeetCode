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
    int goodNodes(TreeNode* root) {
        return count(root, root->val);
    }
    
    int count(TreeNode* root, int maxx){
        if(root==NULL)  return 0;
        
        int temp=0;
        if(root->val>=maxx){
            temp=1;
            maxx=root->val;
        }
        
        return count(root->left, maxx)+count(root->right, maxx)+temp;
    }
};