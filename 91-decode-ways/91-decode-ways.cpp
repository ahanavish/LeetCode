class Solution {
public:
    int numDecodings(string s) {
        if(s.empty())
            return 0;
        
        vector<int> dp(s.length(), -1);
        return numDecodings(0, s, dp);    
    }
    
    int numDecodings(int ind, string& s, vector<int> &dp) {
        if(ind == s.length()) 
            return 1;
        if(s[ind] == '0') 
            return 0;   // sub string starting with 0 is not a valid encoding
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int one_char = numDecodings(ind+1, s, dp);
        int two_char = 0;
        if(ind<s.length()-1 && (s[ind]=='1'|| (s[ind]=='2' && s[ind+1]<'7'))) 
            two_char = numDecodings(ind+2, s, dp);
        
        return dp[ind] = one_char + two_char;
    }
};