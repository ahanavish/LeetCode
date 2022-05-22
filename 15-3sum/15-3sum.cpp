class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)
            return {};
        vector <vector<int>> res;
        
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if ((i>0) && (nums[i]==nums[i-1]))
                continue;
            int low=i+1, high=nums.size()-1;
            
            while(low<high){
                if(-nums[i] == nums[low]+nums[high]){
                    vector <int> r = {nums[i], nums[low], nums[high]};
                    res.push_back(r);
                    while (low < high && nums[low] == r[1]) low++;
                    while (low < high && nums[high] == r[2]) high--;
                }
                else if(-nums[i] > nums[low]+nums[high])
                    low++;
                else
                    high--;
            }
        }
        return res;
    }
};


