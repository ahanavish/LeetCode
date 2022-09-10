class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        vector<vector<int>> next (2, vector<int> (K+1, 0));
        vector<vector<int>> curr (2, vector<int> (K+1, 0));

        for(int ind=prices.size()-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                for(int limit=1; limit<=K; limit++){
                    if(buy == 1)
                        curr[buy][limit] = max(-prices[ind]+next[0][limit], next[1][limit]);
                    else
                        curr[buy][limit] = max(prices[ind]+next[1][limit-1], next[0][limit]);
                }
            }
            next = curr;
        }

        return next[1][K];
    }
};