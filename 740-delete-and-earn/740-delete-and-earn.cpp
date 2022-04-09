class Solution {
public:
    map <int, int> gainsforeach;
    map <int, int> uptil;
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int max = nums[nums.size()-1];
        for(int i=0; i<nums.size(); i++)
            gainsforeach[nums[i]] += nums[i];
        
        return dp(max);
    }
    
    int dp(int n){
        if(n==0)
            return 0;
        if(n==1)
            return gainsforeach[n];
        
        if(uptil.find(n)==uptil.end())
            uptil[n] = max(dp(n-1), dp(n-2)+gainsforeach[n]);
        
        return uptil[n];
    }
};