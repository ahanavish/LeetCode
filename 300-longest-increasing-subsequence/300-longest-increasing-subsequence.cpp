class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        sub.push_back(nums[0]);
        
        int ans=1;
        for(int i=1; i<nums.size(); i++){
            if(sub.back()<nums[i]){
                sub.push_back(nums[i]);
                ans++;
            }
            else{
                int ind = lower_bound(sub.begin(), sub.end(), nums[i])-sub.begin();
                sub[ind] = nums[i];
            }
        }
        
        return ans;
    }
};