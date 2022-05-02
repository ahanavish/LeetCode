class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        while(s<=e){
            if(nums[s]%2){
                if(!(nums[e]%2))
                    swap(nums[e],nums[s]);
                else{
                   e--; 
                }
            }
            else{
                s++;
            }
        }
        return nums;
    }
};