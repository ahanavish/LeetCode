class Solution {
public:
    map <int, int> mapp;
    vector <int> nums;
    int rob(vector<int>& nums) {
        this->nums = nums;
        return dp(nums.size()-1);
    }
    
    int dp(int i){
        if(i==0)
            return nums[0];
        if(i==1)
            return max(nums[0], nums[1]);
        
        if(mapp.find(i)==mapp.end())
            mapp[i]=max(dp(i-1), dp(i-2)+nums[i]);
        return mapp[i];
    }
};