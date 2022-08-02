class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return count(n, dp);
    }
    
    int count(int i, vector<int> &dp){
        if(i==1 || i==0)
            return 1;
        
        if(dp[i] != -1)
            return dp[i];
        
        return dp[i] = count(i-1, dp)+count(i-2, dp);
    }
};