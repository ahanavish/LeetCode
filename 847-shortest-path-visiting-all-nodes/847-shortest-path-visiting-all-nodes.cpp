class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int nodes = graph.size();
        if(nodes == 1) return 0;
        
        //Store the visited sequence for each state using bit manipulation (ex. 1010 -> like 1st and 4th is visited) 
        //each time check that position is visited for that sequence other wise add in queue and once you will get all 11111 return the shortest path
        
        
        int finalState =((1<<nodes) - 1);
        queue<pair<int , int>> que;
        
        for(int i = 0 ; i < nodes ; i++){
            que.push({i , 1<<i});
        }
        
        vector<vector<int>> vis(nodes , vector<int>(finalState, -1));
        
        int shortestPath = 0;
        while(!que.empty()){
            int sz = que.size();
            shortestPath++;
            while(sz--){    
                auto cur = que.front();
                que.pop();
                for(auto x : graph[cur.first]){
                    int state = 1<<x | cur.second;
                    if(state == finalState) return shortestPath;
                    if(vis[x][state] != -1) continue;
                    vis[x][state] = 1;
                    
                    pair<int , int> nxt = {x , state};
                    que.push(nxt);                    
                 }
            }
        }
        return -1;
        
    }
};