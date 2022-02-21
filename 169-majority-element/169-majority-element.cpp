class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map <int, int> maxx;
        for(auto n :nums)
            maxx[n]++;
        
        int ans=INT_MIN;
        for(auto n : maxx){
            if(nums.size()/2<n.second){
                ans = n.first;
            }
        }
        
        return ans;
    }
};