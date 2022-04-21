class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector <int> dp (amount+1, amount+1);
        dp[0]=0;
        
        for(int i=1; i<dp.size(); i++)
            for(auto coin : coins)
                if(coin<=i)
                    dp[i]=min(dp[i], 1+dp[i-coin]);
            
        return dp[amount] == amount+1? -1 : dp[amount];
    }
};

