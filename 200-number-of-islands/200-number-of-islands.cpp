class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size(), islands=0;
        vector <int> directions ({0, 1, 0, -1, 0});
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    queue <pair<int, int>> que;
                    que.push({i, j});
                    islands++;
                    while(!que.empty()){
                        pair<int, int> p = que.front();
                        que.pop();
                        for(int k=0; k<4; k++){
                            int r=directions[k]+p.first, c=directions[k+1]+p.second;
                            if(r>=0 && r<m && c>=0 && c<n && grid[r][c]=='1'){
                                que.push({r, c});
                                grid[r][c] = '0';
                            }
                        }
                    }
                }
            }
        }
        
        return islands;
    }
};

