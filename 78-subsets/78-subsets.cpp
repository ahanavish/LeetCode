class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector<int>> result;
        vector <int> res;
        find(nums, result, res, 0);
        return result;
    }
    
    void find(vector<int>& nums, vector <vector<int>> &result, vector<int> res, int i){
        result.push_back(res);
        for(; i<nums.size(); i++){
            res.push_back(nums[i]);
            find(nums, result, res, i+1);
            res.pop_back();
        }
    }
};