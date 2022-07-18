class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>> (2, vector<int> (K+1, 0)));
        
        for(int ind=prices.size()-1; ind>=0; ind--){
            for(int buy=1; buy>=0; buy--){
                for(int k=1; k<=K; k++){
                    int profit=0;
                    if(buy)
                        profit = max(-prices[ind]+dp[ind+1][0][k], dp[ind+1][1][k]);
                    else
                        profit = max(prices[ind]+dp[ind+1][1][k-1], dp[ind+1][0][k]);
                    dp[ind][buy][k] = profit;
                }
            }
        }
        return dp[0][1][K];
    }
};

