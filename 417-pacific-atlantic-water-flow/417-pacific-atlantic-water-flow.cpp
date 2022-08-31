class Solution {
public:
    int m, n;
    vector<vector<bool>> pacific, atlantic;
    vector<vector<int>> ans;
    queue<pair<int, int>> q;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.size()==0)   return ans;
        m=heights.size(), n=heights[0].size();
        atlantic = pacific = vector<vector<bool> >(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++)
            bfs(i, 0, pacific, ans, heights), bfs(i, n-1, atlantic, ans, heights);
        for(int j=0; j<n; j++)
            bfs(0, j, pacific, ans, heights), bfs(m-1, j, atlantic, ans, heights);
        
        return ans;
    }
    
    void bfs(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &ans, vector<vector<int>> heights){
        q.push({i, j});
        
        while(!q.empty()){
            auto x=q.front().first, y=q.front().second;
            q.pop();
            
            if(visited[x][y])   continue;
            visited[x][y]=true;
            
            if(pacific[x][y] && atlantic[x][y])     ans.push_back({x, y});
            
            if(x+1<m && heights[x+1][y]>=heights[x][y])     q.push({x+1, y});
            if(x-1>=0 && heights[x-1][y]>=heights[x][y])    q.push({x-1, y});
            if(y+1<n && heights[x][y+1]>=heights[x][y])     q.push({x, y+1});
            if(y-1>=0 && heights[x][y-1]>=heights[x][y])    q.push({x, y-1});
        }
    }
};

 
   