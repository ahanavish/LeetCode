class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max_ele = nums[nums.size()-1];
        
        vector <int> count(max_ele+1, 0);
        for(int i=0; i<nums.size(); i++)
            count[nums[i]]++;
        
        for(int i=2; i<=max_ele; i++)
            count[i]=max(i*count[i]+count[i-2], count[i-1]);
        
        return count[max_ele];
    }
};