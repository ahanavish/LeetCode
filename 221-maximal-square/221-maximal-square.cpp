class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector <vector<int>> dp (m, vector<int> (n, 0));
        
        int ans=-1;
        for(int i=0; i<m; i++){
            dp[i][n-1]=matrix[i][n-1]-'0';
            ans = max(ans, dp[i][n-1]);
        }
        for(int i=0; i<n-1; i++){
            dp[m-1][i]=matrix[m-1][i]-'0';
            ans = max(ans, dp[m-1][i]);
        }
                    
        for(int i=m-2; i>=0; i--)
            for(int j=n-2; j>=0; j--){
                if(matrix[i][j]=='0')
                    dp[i][j]=0;
                else
                    dp[i][j] = 1 + min(dp[i+1][j], min(dp[i][j+1], dp[i+1][j+1]));

                ans = max(ans, dp[i][j]);
            }
        
        return ans*ans;
    }
};