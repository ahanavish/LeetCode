class Solution {
public:
    int climbStairs(int n) {
        int prev2=1, prev1=1;
        for(int i=2; i<=n ; i++){
            int curr=prev1+prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};