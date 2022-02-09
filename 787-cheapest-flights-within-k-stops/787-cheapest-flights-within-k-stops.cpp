#define MAX_DIST 1e6 // greater than (n-1) edges * 1e4 (max price)
//here INT_MAX doesnt work since INT_MAX+INT_MAX would give overflow 
//but if vector is declared with long long int, then it wont give any error

//or simply use int for vector but put prev[src]=0 and a condition inside 
//for loop that ensures prev[f[0]]<INT_MAX
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if (src == dst) 
            return 0;
        
        vector<int> curr(n, MAX_DIST);      //keeps price to reach vertices, using atmost mth edges
        vector<int> prev;                   //keeps price to reach vertices, using atmost m-1th edges
        
        curr[src] = 0;                      //since price taken to reach from src to src = 0
        
        k++;                                //since atmost k stops are allowed
        while(k--){
            prev.assign(curr.begin(), curr.end());          //pass by value, and not reference
            for(auto f: flights)
                curr[f[1]] = min(curr[f[1]], prev[f[0]] + f[2]);
        }
        
        return (curr[dst] == MAX_DIST) ? -1 : curr[dst];    //if there exists no path, i.e MAX_DIST so returning -1
    }
};