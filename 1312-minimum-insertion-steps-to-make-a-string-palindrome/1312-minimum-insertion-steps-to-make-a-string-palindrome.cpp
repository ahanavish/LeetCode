class Solution {
public:
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        vector <int> prev(s.length()+1, 0);
        
        for(int i=1; i<=s.length(); i++){
            vector <int> curr(s.length()+1, 0);
            for(int j=1; j<=s.length(); j++){
                if(s[i-1] == t[j-1])
                    curr[j] = 1+prev[j-1];
                else
                    curr[j] = max(curr[j-1], prev[j]);
            }
            prev = curr;
        }
                                   
        int lcs = prev[s.length()];
        return s.length() - lcs;
    }
};