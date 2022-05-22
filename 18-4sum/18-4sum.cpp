class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4)
            return {};
        vector <vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            int target1 = target - nums[i];
            for(int j=i+1; j<nums.size(); j++){
                int low = j+1, high = nums.size()-1, target2 = target1-nums[j];
                while(low<high){
                    if(nums[low]+nums[high] == target2){
                        vector <int> r = {nums[i], nums[j], nums[low], nums[high]};
                        result.push_back(r);
                        while(nums[low]==r[2] && low<high)
                            low++;
                        
                        while(nums[high]==r[3] && low<high)
                            high--;
                    }
                    else if(nums[low]+nums[high] < target2)
                        low++;
                    else
                        high--;
                }
                while(j+1< nums.size() && nums[j+1] == nums[j]) ++j;
            }
            while (i+1< nums.size() && nums[i+1] == nums[i]) ++i;
        }
        return result;
    }
};