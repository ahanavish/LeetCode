class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0, i=0, n=nums.size(), count=0;
        
        while(i<n-2){
            if((nums[i+2]-nums[i+1])==(nums[i+1]-nums[i]))
                count++;
            else{
                ans+=((count*(count+1))/2);
                count=0;
            }
            i++;
        }
        ans+=((count*(count+1))/2);
        return ans;
    }
};