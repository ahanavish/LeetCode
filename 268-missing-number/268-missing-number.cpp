class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size(), i=0;
        
        for(auto num : nums){
            ans = ans ^ num;
            ans = ans ^ i;
            i++;
        }
        
        return ans;
    }
};

