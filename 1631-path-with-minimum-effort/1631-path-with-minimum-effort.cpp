class Solution {
public:
    
    vector<pair<int,int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};    
    
    bool is_safe(vector<vector<int>>& heights, int row, int col){
        return row >= 0 && row < heights.size() && 
               col >= 0 && col < heights[0].size() &&
               heights[row][col] != -1;
    }
    
    vector<vector<int>> find_min_efforts(vector<vector<int>>& heights){
        
        vector<vector<int>> min_efforts(heights.size(), 
                                         vector<int>(heights[0].size(), INT_MAX));
        
        priority_queue<pair<int,pair<int,int>>, 
                       vector<pair<int,pair<int,int>>>, 
                       greater<pair<int,pair<int,int>>>> min_pq;
        
        min_efforts[0][0] = 0;
        
        min_pq.push({0,{0,0}});
        
        int row, col, next_row, next_col, 
            current_effort, next_effort, max_effort = 0;            
        
        while(!min_pq.empty()){
            row = min_pq.top().second.first;
            col = min_pq.top().second.second;
            current_effort = min_pq.top().first;
            
            min_pq.pop();
            
            for(pair<int,int> direction : directions){
                next_row = row + direction.first;
                next_col = col + direction.second;
                
                if(!is_safe(heights, next_row, next_col))
                    continue;
                
                next_effort = abs(heights[next_row][next_col] - heights[row][col]);
                max_effort = max(current_effort, next_effort);
                
                if(max_effort < min_efforts[next_row][next_col]){
                    min_efforts[next_row][next_col] = max_effort;
                    min_pq.push({max_effort, {next_row, next_col}});
                }                
            }                
        }
        
        return min_efforts;        
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {        
        
        vector<vector<int>> min_efforts = find_min_efforts(heights);        
        return min_efforts.back().back();
    }
};