class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set <pair<int, int>> s;
        for(int i=0; i<nums.size(); i++)
            for(int j=i+1; j<nums.size(); j++){
                if(abs(nums[i]-nums[j])==k){
                    int minn=min(nums[i], nums[j]), maxx=max(nums[i], nums[j]);
                    s.insert({minn, maxx});
                }
            }
        
        return s.size();
    }
};