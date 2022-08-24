class Solution {
public:
    bool isPowerOfThree(int n) {
        double no = n;
        while(no>1)
            no = no/3;
        
        return no==1;
    }
};