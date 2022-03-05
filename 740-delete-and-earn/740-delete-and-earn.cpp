class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x:nums)
            mp[x]++;
        vector<int>v;
		
		//Counting frequency
        for(auto it:mp)
        {
            v.push_back(it.first);
        }
        int n=v.size();
        if(n==1)
            return nums[0] * mp[nums[0]];
        
		//Sorting because we will start deleting from last 
        sort(v.begin(),v.end());
        
        vector<int>dp(n);
        for(int i=0;i<n;i++)
        {
            dp[i]=v[i] * mp[v[i]];
        }
        //dp[i]->ans till i th index from last 
        dp[n-2] = v[n-2]+1 == v[n-1] ? max(dp[n-1],dp[n-2]) : dp[n-2]+dp[n-1];
        for(int i=n-3;i>=0;i--)
        {
            if(i+2<n)
            {
                dp[i] = v[i]+1 ==v[i+1] ? max(dp[i+1],dp[i+2]+dp[i]) : (dp[i]+dp[i+1]);
            }
        }
        return max(dp[0],dp[1]);
        
    }
};