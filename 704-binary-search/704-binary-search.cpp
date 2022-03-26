class Solution {
public:
    int search(vector<int>& nums, int target, int  start, int end){
        if(nums[start] > target || nums[end] < target){
            return -1;
        }
        
        int mid = (start + end)/2;
        if(nums[mid] == target){
            return mid;
        }

        if(nums[mid] < target){
            return search(nums,target,mid+1,end);
        }

        if(nums[mid] > target){
           	return search(nums,target,start,mid);
        }
        return mid;
    }
    int search(vector<int>& nums, int target) {
        return search(nums,target,0,nums.size()-1);
    }
};