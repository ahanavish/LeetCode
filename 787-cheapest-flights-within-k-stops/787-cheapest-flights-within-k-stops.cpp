class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if (src == dst) 
            return 0;
        
        vector<int> curr(n, INT_MAX);      //keeps price to reach vertices, using atmost mth edges
        vector<int> prev(n, INT_MAX);                   //keeps price to reach vertices, using atmost m-1th edges
        
        curr[src] = 0;                      //since price taken to reach from src to src = 0
        
        k++;                                //since atmost k stops are allowed
        while(k--){
            prev[src] = 0;
            prev.assign(curr.begin(), curr.end());          //pass by value, and not reference
            for(auto f: flights)
                if(prev[f[0]]<INT_MAX)
                curr[f[1]] = min(curr[f[1]], prev[f[0]] + f[2]);
        }
        
        return (curr[dst] == INT_MAX) ? -1 : curr[dst];    //if there exists no path, i.e MAX_DIST so returning -1
    }
};