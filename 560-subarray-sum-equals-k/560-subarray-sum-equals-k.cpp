class Solution {
public:

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int ps = 0;
    int cnt  = 0;
    m[0] = 1;
    for(int i = 0; i<nums.size(); i++){
        ps += nums[i];
        if(m.find(ps - k) != m.end()){
            cnt += m[ps-k];
        }
        m[ps]++;
    }
    return cnt;
}
};