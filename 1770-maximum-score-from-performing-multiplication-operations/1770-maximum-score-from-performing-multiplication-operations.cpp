class Solution {
public:
    vector <int> nums, multi;
    int m, n;
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        this->nums = nums;
        multi = multipliers;
        m = multipliers.size(), n = nums.size();     //exactly m operations
        vector <vector<int>> mapp (m, vector<int>(m, 0));
        
        return dp(0, 0, mapp);
    }
    
    int dp(int i, int left, vector<vector<int>>& mapp){
        if(i==m)
            return 0;
        
        int mult = multi[i], right = n-1-i+left;
        
        if(mapp[i][left]==0)
            mapp[i][left] = max(mult*nums[left]+dp(i+1, left+1, mapp), mult*nums[right]+dp(i+1, left, mapp));
        
        return mapp[i][left];
    }
}; 

