class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum=0, min=0;
        for(int n : nums){
            sum += n;
            if(min>sum) min=sum;
        }
        
        return -min+1;
    }
};

