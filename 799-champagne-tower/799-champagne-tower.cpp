class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[101][101] = {0.0};
        dp[0][0] = (double)poured;
        for(int i=1;i<=query_row;i++)
            for(int j=0;j<=i;j++){
                if(j > 0)
                    dp[i][j] = max(0.0,(dp[i-1][j-1] - 1)/2);
                if(j < i)
                    dp[i][j] += max(0.0,(dp[i-1][j] - 1)/2);
            }
        
        return min(1.0,dp[query_row][query_glass]);
    }
};
