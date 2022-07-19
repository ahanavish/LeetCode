class Solution {
public:
    int numDecodings(string s) {
        if(s.empty())
            return 0;
        
        vector<int> dp(s.length()+1, 0);
        dp[s.length()] = 1; 
            
        for(int ind=s.length()-1; ind>=0; ind--){
            if(s[ind] == '0')
                dp[ind] = 0;
            else{
                int one_char = dp[ind+1];
                int two_char = 0;
                if(ind<s.length()-1 && (s[ind]=='1'|| (s[ind]=='2' && s[ind+1]<'7'))) 
                    two_char = dp[ind+2];

                dp[ind] = one_char+two_char;
            }
        }
        
        return dp[0];    
    }
};
