class Solution {
public:
    bool divisorGame(int n) {
        if(n==1) 
            return false;       //If n=1, there exists no x such that 0< x <1, so no move is possible i.e. game lost
        vector<int> dp(n+1,0);  //We create a vector of size n+1 initialized with 0 (implying false). For each index j of dp, dp[j] tells if Alice won or not (assuming starting value j)
        
        for(int j=2; j<=n; j++)
            for(int i=1;i<=sqrt(j);i++)     //factors of j lie between 1 and sqrt(j)  
                if(j%i==0 && dp[j-i]==0)    //If i is a factor of j, then Bob gets j-i,so we choose this i only if Bob loses at j-i so that Alice wins.
                    dp[j]=1;                //Alice wins 
        
        if(dp[n]==1) return true;
        return false;
    }
};