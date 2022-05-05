class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1, k=1;
        while(k<nums.size()){
            if(nums[k]!=nums[k-1])
                nums[i++]=nums[k];
            
            k++;
        }
        
        return i;
    }
};