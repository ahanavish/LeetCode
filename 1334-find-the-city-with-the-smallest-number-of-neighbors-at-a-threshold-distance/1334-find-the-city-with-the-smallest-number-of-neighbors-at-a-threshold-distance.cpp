class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector<int> (n, int(1e6)));   
        for(int i=0; i<n; i++)
            dis[i][i]=0;
        for(auto edge : edges){
            int u=edge[0], v=edge[1], w=edge[2];
            dis[u][v]=dis[v][u]=w;
        }
        
        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    if(dis[i][j]>dis[i][k]+dis[k][j])
                        dis[i][j]=dis[i][k]+dis[k][j];
         
        int ans=0, ans_count=n;
        for(int i=0; i<n; i++){
            int count=0;
            for(int j=0; j<n; j++)
                if(dis[i][j]<=distanceThreshold)
                    count++;
    
            if(count<=ans_count){
                ans_count=count;
                ans=i;
            }
        }
        
        return ans;
    }
};



