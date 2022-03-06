class Solution {
public:
    int countOrders(int n) {
        long long mod = 1000000007;
        long long dp[501];
        dp[1]=1;
        dp[2]=6;
        long long permutation,odd;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i]%mod;
            odd = i*2-1;
            permutation = (odd*(odd+1)/2)%mod;
            dp[i]=(dp[i-1]*permutation)%mod;
        }
        return (int)dp[n];
    }
};