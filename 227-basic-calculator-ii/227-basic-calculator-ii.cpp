class Solution {
public:
    int calculate(string s) {
        int ans=0, interim=0;
        char op = '+';
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' ')
                continue;
            else if(!isdigit(s[i]))
                op = s[i];
            else{
                int num=0;
                while(i<s.size() && isdigit(s[i]))
                    num = num*10 + (s[i++]-'0');
                
                if(op == '*')
                    interim *= num;
                else if(op == '/')
                    interim /= num;
                else{
                    ans += interim;
                    interim = num*(op == '+'?1:-1);
                }
                i--;
            }
        }
        
        ans += interim;
        return ans;
    }
};