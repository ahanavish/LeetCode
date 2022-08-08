class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j]==1)
                    q.push({i, j});
    
        int ans=0;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            pair<int, int> dirs[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
            
            for(auto dir : dirs){
                int x = curr.first+dir.first, y=curr.second+dir.second;
                if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==0){
                    q.push({x, y});
                    grid[x][y] = grid[curr.first][curr.second]+1;
                    ans = max(ans, grid[x][y]);
                }
            }
        }
        
        return (ans>0? ans-1 : -1);
    }
};