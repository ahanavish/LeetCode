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
    void flatten(TreeNode* root) {
        TreeNode* head = root;
        while(head){
            if(head->left){
                TreeNode* prev = head->left;
                while(prev->right)
                    prev = prev->right;
                
                prev->right = head->right;
                head->right = head->left;
                head->left = NULL;
            }
            head = head->right;
        }
    }
};
