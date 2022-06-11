class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x > 0 && x%10==0)) return false;
        int revhalf = 0, slow = x, fast = x;
        while(fast){ 
            revhalf = revhalf * 10 + slow % 10;
            slow /= 10;
            fast /= 100;
        }
        return slow == revhalf || slow == revhalf / 10;
    }
};