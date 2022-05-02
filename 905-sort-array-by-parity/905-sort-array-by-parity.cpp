class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0, j=nums.size()-1;
        while(i<j){
            if(nums[j]%2==0){
                if(nums[i]%2==1){
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j--] = temp;
                }
                i++;
            }
            else
                j--;
        }
        return nums;
    }
};