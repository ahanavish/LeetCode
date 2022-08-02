class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        
        vector <vector<int>> adj(n);
        for(auto c : connections){
            int a=c[0], b=c[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        //0->1, 2, 3;
        //1->0,2
        //2->0,1
        //3->0
        int components=0;
        vector<int> visited(n, 0);
        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                components++;
                queue <int> q;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    visited[node]=1;
                    q.pop();
                    
                    for(auto a : adj[node]){
                        if(visited[a] == 0){
                            q.push(a);
                            visited[a]=1;
                        }
                    }
                }
            }
        }
        
        return components-1;
    }
};