class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map <int, int> maxx;
        for(auto n :nums)
            maxx[n]++;
        
        int ans=INT_MIN,ele=0;
        for(auto n : maxx){
            if(nums.size()/2<n.second){
                ans = max(ans, n.first);
            }
        }
        
        return ans;
    }
};