class Solution{
public:

	int subarraySum(vector<int>& nums, int k) { 
	unordered_map<int,int>mp;
    int ps=0;
    mp[ps]++;
    int cnt=0;
    int n=nums.size();
    int key=0;     
    for(int i=0; i<n; i++){
        ps+=nums[i];
        key=ps-k;
        if(mp.find(key)!=mp.end()){
            cnt=cnt+mp[key];
        }
        mp[ps]++;
    }
    return cnt;
}
};