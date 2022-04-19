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
    void check(TreeNode* root,vector<TreeNode*> &v1,vector<int> &v2)
    {
        if(root)
        {
            check(root->left,v1,v2);
            v1.push_back(root);
            v2.push_back(root->val);
            check(root->right,v1,v2);
        }
    }
    void recoverTree(TreeNode* root) {
       vector<TreeNode*> v1;
        vector<int> v2;
        check(root,v1,v2);
        
        sort(v2.begin(),v2.end());
        for(int i=0;i<v1.size();i++)
        {
            v1[i]->val=v2[i];
        }
        
    }
};