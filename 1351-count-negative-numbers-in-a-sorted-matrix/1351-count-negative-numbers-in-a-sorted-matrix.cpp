class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size()-1, n=grid[0].size()-1;
        int count=0;
        return binary(grid, m, n); 
    }
    
    int binary(vector <vector<int>> grid, int m, int n){
        int start=0, end=n, count=0;
        while(start>=0 && start<=m && end>=0 && end<=n){
            if(grid[start][end]<0){
                count+= ((m-start)+1);
                end--;
            }
            else if(grid[start][end]>=0)
                start++;
        }
        return count;
    }
};