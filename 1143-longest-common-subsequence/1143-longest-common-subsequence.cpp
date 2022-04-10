class Solution {
public:
    string text1, text2;
    int longestCommonSubsequence(string text1, string text2) {
        int len1=text1.length(), len2=text2.length();
        vector <vector<int>> dp (len1, vector<int> (len2, -1));
        this->text1=text1;
        this->text2=text2;
       
        return help(len1-1, len2-1, dp);
    }
    
    int help(int i, int j, vector<vector<int>> &dp){
        if(i<0 || j<0)
            return 0;
        
        if(dp[i][j]==-1){
            if(text1[i]==text2[j])
                dp[i][j]=help(i-1, j-1, dp)+1;
            else
                dp[i][j]=max(help(i-1, j, dp), help(i, j-1, dp));
        }
        
        return dp[i][j];
    }
};