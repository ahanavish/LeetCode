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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue <pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        int ans=1;
        while(!q.empty()){
            int size= q.size();
            ans=max(ans,q.back().second-q.front().second+1);
            
            for(int i=0; i<size; i++){
                auto temp = q.front();
                long long int index = temp.second;
                q.pop();
                
                if(temp.first->left)
                    q.push({temp.first->left, index*2+1});
                if(temp.first->right)
                    q.push({temp.first->right, index*2+2});
            }
        }
        
        return ans;
    }
};
