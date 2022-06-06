class Solution {
public:
    int calculate(string& s) {
        int cur = 0, ans = 0, interimRes = 0;
        char prevOp = '+';
        s += "##";                                     
        for(auto c : s)
            if(c == ' ') continue;
            else if(isdigit(c)) 
                cur = cur * 10 + (c-'0');
            else {
                if(prevOp == '*')                      // '*':  Case-1
                    interimRes *= cur;
                else if(prevOp == '/')                 // '/':  Case-1
                    interimRes /= cur;
                else                                   // '+' and '-':  Case-2
                    ans += interimRes, interimRes = prevOp == '+' ? cur : -cur;
                prevOp = c;
                cur = 0;
                cout<<cur<<ans<<interimRes<<prevOp;
            }

        return ans;
    }
};