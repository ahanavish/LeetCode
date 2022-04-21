class Solution {
public:
    vector <int> dp;
    vector <int> coins;
    int coinChange(vector<int>& coins, int amount) {
        this->coins = coins;
        dp = vector <int> (amount+1, INT_MAX);
        
        return func(amount);
    }
    
    int func(int amount){
        if(amount == 0)
            return 0;
        if(amount<0)
            return -1;
        
        if(dp[amount]==INT_MAX){
            int minchange=INT_MAX;
            for(int i=0; i<coins.size(); i++){
                int change=-1;
                if(coins[i]<=amount)
                    change = func(amount-coins[i]);
                
                if(change>=0 && change<minchange)
                    minchange = 1+change;
            }
            dp[amount] = minchange == INT_MAX ? -1 : minchange;
        }
        
        return dp[amount];
    }
};