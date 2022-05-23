class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map <int, int> freq;
        
        int cum_sum=0, ans=0;
        freq[0]=1;
        for(int i=0; i<nums.size(); i++){
            cum_sum += nums[i];
    
            if(freq.find(cum_sum-k) != freq.end())
                ans += freq[cum_sum-k];
            
            freq[cum_sum]++;
        }
        
        return ans;
    }
};