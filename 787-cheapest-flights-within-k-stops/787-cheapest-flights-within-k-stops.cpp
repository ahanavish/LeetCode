#define MAX_DIST 1e6 // greater than (n-1) edges * 1e4 (max price)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> curr(n, MAX_DIST);
        vector<int> prev;
        
        curr[src] = 0;
        
        k++;        //since there are atmost k stops allowed
        while(k--){
            prev.assign(curr.begin(), curr.end());
            for(auto f: flights)
                curr[f[1]] = min(curr[f[1]], prev[f[0]] + f[2]);
        }
        
        return (curr[dst] == MAX_DIST) ? -1 : curr[dst];
    }
};