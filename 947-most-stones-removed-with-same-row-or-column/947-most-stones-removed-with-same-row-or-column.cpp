class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        if(n==1)
            return 0;
        
        vector<bool> vis(n, false);
        int count=0;
        for(int i=0; i<n; i++)
            if(!vis[i])
                count += dfs(i, stones, vis);
        
        return count;
    }
    
    int dfs(int i, vector<vector<int>>& stones, vector<bool> &vis){
        int n=stones.size();
        vis[i]=true;
        
        int count=0;
        for(int j=0; j<n; j++)
            if(!vis[j] && ((stones[i][0]==stones[j][0])||(stones[i][1]==stones[j][1])))
                count += (dfs(j, stones, vis)+1);
        
        return count;
    }
};