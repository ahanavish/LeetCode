class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minn=INT_MAX, max_profit=INT_MIN;
        for(int i=0; i<prices.size(); i++){
            minn = min(minn, prices[i]);
            max_profit = max(max_profit, prices[i]-minn);
        }
        return max_profit;
    }
};