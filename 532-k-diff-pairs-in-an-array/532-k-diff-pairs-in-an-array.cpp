class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
	int n = nums.size();
	sort(nums.begin(),nums.end());
	set<pair<int,int>> st;
	for(int i=0;i<n;++i)
	  for(int j=i+1;j<n;++j)
		if(nums[j]-nums[i]==k) st.insert({nums[i],nums[j]}); 
	return st.size();        
    }
};