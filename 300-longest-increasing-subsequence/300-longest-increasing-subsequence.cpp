class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int> (nums.size()+1, 0));
        vector<int> curr(nums.size()+1, 0), next(nums.size()+1);
        
        
        for(int ind=nums.size()-1; ind>=0; ind--){
            for(int prev=ind-1; prev>=-1; prev--){
                int take=0;
                if(prev==-1 || nums[prev]<nums[ind])
                    take = 1+next[ind+1];
                int not_take = next[prev+1];
                curr[prev+1] = max(take, not_take);
            }
            next = curr;
        }
        return curr[0];
    }
};
