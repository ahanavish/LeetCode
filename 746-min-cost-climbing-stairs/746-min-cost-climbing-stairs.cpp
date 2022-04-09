class Solution {
public:
    vector <int> cost;
    map <int, int> m;
    int minCostClimbingStairs(vector<int>& cost) {
        this->cost = cost;
        return min(dp(cost.size()-1), dp(cost.size()-2));
    }
    
    int dp(int i){
        if(i<2)
            return m[i]=cost[i];
        
        if(m.find(i)==m.end())
            m[i]= min(dp(i-1), dp(i-2))+cost[i];
        
        return m[i];
    }
};