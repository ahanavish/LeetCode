class Solution {
public:
    bool possibleSum(int mid, vector<int> &nums, int limit){
        int total = 0;
        int subArrays = 1;
        
        for(int i=0; i<nums.size(); i++){
             if(nums[i] > mid)
            return false;
        
            else if(nums[i] + total > mid){
                subArrays++;
                total = nums[i];
            }
            else
                total += nums[i];
        }
        
        return subArrays <= limit;
    }
    
    
    int splitArray(vector<int>& nums, int m) {
        int ans = 0;
        
        int low = 0;
        int high = 1e9;
        
        while(low <= high){
            int mid = (low+high)/2;
            if(possibleSum(mid, nums, m)){
                high = mid-1;
                ans = mid;
            }
            else
                low = mid+1;
        }
        
        return ans;
    }
};