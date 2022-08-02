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
    vector<TreeNode*> generateTrees(int n) {
        vector <TreeNode*> ans;
        if(n==0)
            return ans;
        
        return helper(1, n);
    }
    
    vector<TreeNode*> helper(int start, int end){
        vector<TreeNode*> ans;
        if(start>end){
            ans.push_back(NULL);
            return ans;
        }
        
        for(int i=start; i<=end; i++){
            vector <TreeNode*> left = helper(start, i-1);
            vector <TreeNode*> right = helper(i+1, end);
            
            for(auto l : left)
                for(auto r :right){
                    TreeNode* newnode = new TreeNode(i, l, r);
                    ans.push_back(newnode);
                }
        }
        
        return ans;
    }
};