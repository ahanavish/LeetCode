class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x) {
            int dig = x%10;
            if ((ans > 0 && ans > (INT_MAX - dig)/10) || (ans < 0 && ans < (INT_MIN - dig)/10))                           return 0;
            
            ans = ans * 10 + dig;
            x /= 10;
        }
        return ans;
    }
};