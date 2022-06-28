class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int low=0, high=0;
        
        for(int i=0; i<nums.size(); i++){
            low = max(low, nums[i]);
            high += nums[i];
        }
        
        while(low <= high){
            int mid = (low+high)/2, count = 1, temp_sum=nums[0];
            for(int i=1; i<nums.size(); i++){
                if(temp_sum + nums[i] > mid){
                    count++;
                    temp_sum = nums[i];
                }
                else
                    temp_sum += nums[i];
            }
            
            if(count> m)
                low = mid+1;
            else
                high = mid-1;
        }
        
        return low;
    }
};