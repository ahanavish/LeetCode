class Solution {
public:
    int numOfMinutes(int n, int head, vector<int>& manager, vector<int>& inform) {
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++)
            if(i!=head)
                adj[manager[i]].push_back(i);
        
        return dfs(head, adj, manager, inform);
    }
    
    int dfs(int i, vector<vector<int>> &adj, vector<int>& manager, vector<int>& inform){
        int count=0;
        for(auto j :adj[i])
                count = max(count, dfs(j, adj, manager, inform));
        
        return count+inform[i];
    }
};