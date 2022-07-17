class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<int> dp(k+1, 0);
        int modu = 1e9+7;
        for(int i=1; i<=n; i++){
            vector<int> temp(k+1, 0);
            temp[0] = 1;
            for(int j =1; j<=k; j++){
                long long value = (dp[j] + modu - ((j-i) >=0 ? dp[j-i] : 0))%modu;
                temp[j] = (temp[j-1] + value)%modu;
            }
            dp = temp;
        }
        return (dp[k] + modu - (k>0 ? dp[k-1] : 0))%modu;
    }
};