class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        string intermediate = "";
        int open = 0;
        for(int i = 0; i < s.size(); i++){
            if((s[i] != '(') && (s[i] != ')'))
                intermediate.push_back(s[i]);
            else if (s[i] == '('){
                open++;
                intermediate.push_back(s[i]);
            }
            else{
                if(open == 0) continue;
                else{
                    open--;
                    intermediate.push_back(s[i]);
                }
            }
        }
        
        int close = 0;
        string ans = "";
        for(int i = intermediate.size()-1; i >= 0; i--){
            if((intermediate[i] != '(') && (intermediate[i] != ')'))
                ans.push_back(intermediate[i]);
            else if (intermediate[i] == ')'){
                close++;
                ans.push_back(intermediate[i]);
            }
            else{
                if(close == 0) continue;
                else{
                    close--;
                    ans.push_back(intermediate[i]);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};