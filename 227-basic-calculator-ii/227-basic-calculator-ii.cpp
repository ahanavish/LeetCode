class Solution {
public:
    int calculate(string s) {
        int i = 0, ans = 0, num = 0;
        int interim = 0;
        char op = '+';
        while(i < s.size()){
            if(isdigit(s[i])){
                num = 0;
                while(i < s.size() && isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                if(op == '+' || op == '-'){
                    ans += interim;
                    interim = num * (op == '-' ? -1 : 1);
                }else if(op == '*'){
                    interim *= num;
                }else if(op == '/'){
                    interim /= num;
                }
                continue;
            }
            else if(s[i] != ' ') op = s[i];
           
            i++;
        }    

        ans += interim;            
        return ans;
    }
};