class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums){

    vector<vector<int>> ans;
    vector<int> tmp;
    helper(nums, 0, tmp, ans);
                  
    return ans;
}

void helper(vector<int> &nums, int i, vector<int> &tmp, vector<vector<int>> &ans)
{
    if(i == nums.size())
    {
        ans.push_back(tmp);
        return;
    }
    
    helper(nums, i + 1, tmp, ans);
    tmp.push_back(nums[i]);
    helper(nums, i + 1, tmp, ans);
    tmp.pop_back();
}
};