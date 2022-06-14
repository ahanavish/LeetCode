class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,0));
        for(int i=0;i<word1.size();i++)
        {
            for(int j=0;j<word2.size();j++)
            {
                if(word1[i]==word2[j])
                {
                    dp[i+1][j+1]=1+dp[i][j];
                }
                else
                {
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        int k= dp[word1.size()][word2.size()]; // k is maximum matching substring
        return (word1.size()+word2.size())-2*k;
    }
};