class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n>0 && (n-1)%3==0 && (n&(n-1))==0)
            return true;
        
        return false;
    }
};