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
    void solve(int r,int c,TreeNode *root,map<int,multiset<pair<int,int>>> &verti){
        if(!root)return ;
        verti[r].insert({root->val,c});
        solve(r+1,c-1,root->left,verti);
        solve(r+1,c+1,root->right,verti);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)return {};
		//Using pair storing root val and column index
        map<int,multiset<pair<int,int>>>verti;
		//Storing the value of node according to row
        solve(0,0,root,verti);
        vector<vector<int>> ans;
        map<int,vector<int>> ret;
        
        for(auto ms:verti){
            for(auto pr:ms.second){
                ret[pr.second].push_back(pr.first);
            }
        }
        
        for(auto vec:ret){
            vector<int> tmp;
            for(auto x:vec.second){
                tmp.push_back(x);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};