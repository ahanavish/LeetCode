class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxx=0, min=prices[0];
        for(int i=1; i<prices.size(); i++)
            if(prices[i]>min)
                maxx=max(maxx, prices[i]-min);
            else
                min=prices[i];
        return maxx;
    }
};