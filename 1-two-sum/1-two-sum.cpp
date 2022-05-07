class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> m;
        vector <int> result;
        for(int i=0; i<nums.size(); i++){
            if(m.find(target-nums[i])!= m.end()){
                result.push_back(i);
                result.push_back(m[target-nums[i]]);
            }
            else
                m[nums[i]]=i;
        }
        
        return result;
    }
};