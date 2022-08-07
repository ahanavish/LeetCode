class Solution {
public:
    int mod = 1e9+7;
    int countVowelPermutation(int n) {
        if(n==1)
            return 5;
        
        vector<vector<int>> dp(5, vector<int> (n+1, -1));
        for(int i=0; i<5; i++)
            dp[i][n]=1;
        
        vector<int> vowels({'a', 'e', 'i', 'o', 'u'});
        int c=0;
        for(int i=0; i<5; i++)
            c = (c+count(i, 1, n, vowels, dp))%mod;
            
        return c;
    }
    
    long long int count(int prev, int len, int n, vector<int> vowels, vector<vector<int>> &dp){
        if(dp[prev][len] != -1)
            return dp[prev][len]%mod;
        
        long long int c=0;
        if(prev == 0)
            c = count(1, len+1, n, vowels, dp)%mod;
        else if(prev == 1)
            c = (count(0, len+1, n, vowels, dp)+count(2, len+1, n, vowels, dp))%mod;
        else if(prev == 2)
            c = (count(0, len+1, n, vowels, dp)+count(1, len+1, n, vowels, dp)+
                    count(3, len+1, n, vowels, dp)+count(4, len+1, n, vowels, dp))%mod;
        else if(prev == 3)
            c = (count(2, len+1, n, vowels, dp)+count(4, len+1, n, vowels, dp))%mod;
        else if(prev == 4)
            c = (count(0, len+1, n, vowels, dp))%mod;
        
        return dp[prev][len] = c;
    }
};