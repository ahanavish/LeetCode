class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> ans(n+1, 0);
        ans[0]=0;
        
        for(int  i=1; i<=n; i++){
            if(i%2 == 0)        //even
                ans[i] = ans[i/2];
            else                //odd
                ans[i] = ans[i/2]+1;
        }
        
        return ans;
    }
};