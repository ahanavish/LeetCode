class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0, mid=0, high=nums.size()-1;
        
        while(mid<=high){
            if(nums[mid]==0){
                int temp = nums[low];
                nums[low++] = nums[mid];
                nums[mid++] = temp;
            }
            
            else if(nums[mid]==1)
                mid++;
            
            else{
                int temp = nums[mid];
                nums[mid] = nums[high];
                nums[high--] = temp;
            }
        }
    }
};