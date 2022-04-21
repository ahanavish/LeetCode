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
    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode* newroot=NULL, *newcurr;
        stack<TreeNode*> stck;
        TreeNode* curr=root;
        while (curr || !stck.empty()) {
            while (curr) {
                stck.push(curr);
                curr=curr->left;
            }
            
            curr=stck.top();
            stck.pop();
            if (newroot == NULL) {
                newroot = new TreeNode(curr->val);
                newcurr = newroot;
            }
            else {
                newcurr->right = new TreeNode(curr->val);
                newcurr = newcurr->right;
            }
            
            curr=curr->right;
        }
        
        return newroot;
    }
};