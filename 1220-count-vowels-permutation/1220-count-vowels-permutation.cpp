class Solution {
public:
    int mod = 1e9+7;
    int countVowelPermutation(int n) {
        vector<int> vowels({'a', 'e', 'i', 'o', 'u'});
        vector<long> prev(5, 1);
      
        vector<long> curr(5, 0);
        for(int len=n-1; len>0; len--){
            curr[0] = prev[1]%mod;
            curr[1] = (prev[0]+prev[2])%mod;
            curr[2] = (prev[0]+prev[1]+prev[3]+prev[4])%mod;
            curr[3] = (prev[2]+prev[4])%mod;
            curr[4] = (prev[0])%mod;
            
            prev = curr;
        }
        
        int ans=0;
        for(int i=0; i<5; i++)
            ans = (ans+prev[i])%mod;
        
        return ans;
    }
};