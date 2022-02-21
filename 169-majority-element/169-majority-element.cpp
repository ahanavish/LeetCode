class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map <int, int> maxx;
        for(auto n :nums)
            maxx[n]++;
        
        int ans=0,ele=0;
        for(auto n : maxx){
            cout<<n.first<<n.second;
            if(ans<n.second){
                ans=n.second;
                ele=n.first;
            }
        }
        
        return ele;
    }
};