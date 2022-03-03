class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n<3)
            return 0;
        
        int ans = 0;
        int i = 0, j;
        while(i<n-1)
        {
            int diff = nums[i+1]-nums[i];
            j = i+1;
            while(j<n-1 && diff==nums[j+1]-nums[j])
                j++;
            
            int range = j-i+1;
            if(range>=3)
                ans += (range-1)*(range-2)/2;
       
            i = j;
        }

        return ans;
    }
};