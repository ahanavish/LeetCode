class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size=nums.size()-1;
        return max(nums[size]*nums[size-1]*nums[size-2], nums[size]*nums[0]*nums[1]);
    }
};