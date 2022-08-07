class Solution {
public:
    int mod = 1e9+7;
    int countVowelPermutation(int n) {
        vector<int> vowels({'a', 'e', 'i', 'o', 'u'});
        vector<vector<long>> dp(5, vector<long> (n+1, 0));
        for(int i=0; i<5; i++)
            dp[i][n]=1;
        
      
        for(int len=n-1; len>0; len--){
            dp[0][len]=  (dp[1][len+1])%mod;
            dp[1][len] = (dp[0][len+1]+dp[2][len+1])%mod;
            dp[2][len] = (dp[0][len+1]+dp[1][len+1]+dp[3][len+1]+dp[4][len+1])%mod;
            dp[3][len] = (dp[2][len+1]+dp[4][len+1])%mod;
            dp[4][len] = (dp[0][len+1])%mod;
        }
        
        int ans=0;
        for(int i=0; i<5; i++)
            ans = (ans+dp[i][1])%mod;
        
        return ans;
    }
};