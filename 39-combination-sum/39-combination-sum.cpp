class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int t) {
        vector<vector<int>> ans;
        vector<int> row;
        solve(nums, ans, row, 0, t);
        return ans;
    }
    
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &row, int ind, int t)
    {
        if(t<=0){
            if(t==0)
                ans.push_back(row);
            return; 
        }

        for(int i=ind; i<nums.size(); i++){
            row.push_back(nums[i]);
            solve(nums, ans, row, i, t-nums[i]);
            row.pop_back();
        }
    }
};  