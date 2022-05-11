class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map <int, int> m;
        
        for(auto n: nums)
            m[n]++;
        
        vector <int> result;
        for(auto it : m)
            if(it.second == 2)
                result.push_back(it.first);
        
        return result;
    }
};