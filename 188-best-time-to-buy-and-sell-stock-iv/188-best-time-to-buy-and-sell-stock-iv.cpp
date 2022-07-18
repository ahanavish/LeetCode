class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>> (2, vector<int> (k+1, -1)));
        return func(0, 1, prices, k, dp);
    }
    
    int func(int ind, int buy, vector<int>& prices, int k, vector<vector<vector<int>>> &dp){
        if(k==0 || ind==prices.size())
            return 0;
        
        if(dp[ind][buy][k] != -1)
            return dp[ind][buy][k];
        
        int profit=0;
        if(buy)
            profit = max(-prices[ind]+func(ind+1, 0, prices, k, dp), func(ind+1, 1, prices, k, dp));
        else
            profit = max(prices[ind]+func(ind+1, 1, prices, k-1, dp), func(ind+1, 0, prices, k, dp));
        return dp[ind][buy][k] = profit;
    }
};