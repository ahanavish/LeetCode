class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.length(), n = s.length();
        vector<vector<double>> dp(m + 1, vector<double> (n + 1, 0));
        for (int j = 0; j <= n; j++) 
            dp[0][j] = 1;
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= m; i++)
                if(t[i - 1] == s[j - 1])
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i][j - 1];
        
        return (int)dp[m][n];
    }
};  
