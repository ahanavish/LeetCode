class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int const len1=text1.length(), len2=text2.length();
        
        int dp[len1+1][len2+1];
        for(int i=0; i<=len1; i++)
            dp[i][0]=0;
        for(int j=0; j<=len2; j++)
            dp[0][j]=0;
        
        for(int i=0; i<len1; i++)
            for(int j=0; j<len2; j++)
                if(text1[i]==text2[j])
                    dp[i+1][j+1]=dp[i][j]+1;
                else
                    dp[i+1][j+1]=max(dp[i][j+1], dp[i+1][j]);
        
        return dp[len1][len2];
    }
};