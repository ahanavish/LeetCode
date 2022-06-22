class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0, min=INT_MAX;
        for(auto n : nums){
            sum += n;
            min = min>n? n : min;
        }
          
        return sum - (min*nums.size());
    }
};