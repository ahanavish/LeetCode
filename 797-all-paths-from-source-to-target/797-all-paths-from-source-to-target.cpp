class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector <vector<int>> result;
        int n=graph.size(), s=0, e=n;
        vector <int> adj[n];
        for(int i=0; i<n; i++){
            for(auto g : graph[i]){
                adj[i].push_back(g);
            }
        }
        
        queue <vector<int>> q;
        vector <int> path;
        q.push({0});
        while(!q.empty()){
            path = q.front();
            q.pop();
            if(path.back() == n-1)
                result.push_back(path);
            
            for(auto ele : adj[path.back()]){
                vector <int> temp = path;
                temp.push_back(ele);
                q.push(temp);
            }
        }
        return  result;
    }
};


