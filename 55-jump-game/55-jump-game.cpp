class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size()-1;
        
        while(goal != 0){
            int i;
            for(i= goal-1; i>=0; i--)
                if(goal <= i+nums[i]){
                    goal = i;
                    break;
                }    
            if(i == -1)
                return false;
        }
        
        return true;
    }
};