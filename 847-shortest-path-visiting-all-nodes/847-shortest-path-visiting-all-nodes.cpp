class Solution {
public:
    class tuple{
        public:
        int node;
        int mask;
        int cost;
        
        tuple(int node, int mask, int cost){
            this->node = node;
            this->mask = mask;
            this->cost = cost;
        }
    };
    
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue <tuple> q;
        set<pair<int, int>> vis;
        for(int i=0; i<n; i++){
            int mask=(1<<i);
            tuple node(i, mask, 1);
            q.push(node);
            vis.insert({i, mask});
        }
        
        int all = (1<<n)-1;
        
        while(!q.empty()){
            tuple curr = q.front();
            q.pop();
            if(curr.mask == all)
                return curr.cost-1;
            
            for(auto &adj : graph[curr.node]){
                int bothvisitedmask = curr.mask;
                bothvisitedmask = bothvisitedmask | (1<<adj);
                tuple node(adj, bothvisitedmask, curr.cost+1);
                
                if(vis.find({adj, bothvisitedmask})==vis.end()){
                    vis.insert({adj, bothvisitedmask});
                    q.push(node);
                }
            }
        } 
        return 0;
    }
};