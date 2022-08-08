class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> curr(n+1, 0), next(n+1, 0);
        
        for(int ind=nums.size()-1; ind>=0; ind--){
            for(int prev=ind-1; prev>=-1; prev--){
                int take=INT_MIN;
                if(prev==-1 || nums[ind]>nums[prev])
                    take = next[ind+1]+1;
                int not_take = next[prev+1];
                curr[prev+1] = max(take, not_take);
            }
            next = curr;
        }
        return curr[0];
    }
};
