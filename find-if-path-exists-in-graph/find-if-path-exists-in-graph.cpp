class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<int> adj[n];
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector <int> vis(n, 0);
        for(int i=0; i<n; i++)
            if(vis[i] == 0)
                if(dfs(adj, vis, start, end))
                    return true;
        
        return false;
    }
    
    bool dfs(vector<int> adj[], vector<int> &vis, int start, int end){
        if(end == start)
            return true;
        
        vis[start] = 1;
        for(auto it: adj[start])
            if(vis[it]==0)
                if(dfs(adj, vis, it, end))
                    return true;
        
        return false;
    }
};