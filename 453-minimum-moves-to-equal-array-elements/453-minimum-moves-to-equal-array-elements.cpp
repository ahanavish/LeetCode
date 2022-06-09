class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min=INT_MAX, sum=0;
        
        for(auto n: nums){
            if(min>n)
                min = n;
            
            sum += n;
        }
        
        return sum - nums.size()*min;
    }
};