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
    bool isSameTree(TreeNode* pr, TreeNode* qr) {
        stack <pair<TreeNode*, TreeNode*>> s;
        s.push({pr, qr});
        
        while(!s.empty()){
            TreeNode *p= s.top().first, *q= s.top().second;
            s.pop();
            
            if(!p && !q)
                continue;
            if(!p || !q || p->val != q->val)
                return false;
            
            s.push({p->left, q->left});
            s.push({p->right, q->right});
        }
        return true;
    }
};