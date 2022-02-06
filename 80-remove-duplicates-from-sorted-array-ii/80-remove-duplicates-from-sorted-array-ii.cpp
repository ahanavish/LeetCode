class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p=1, count=1, size=nums.size();
        while(p<size){
            if(nums[p]==nums[p-1])
                count++;
            else
                count=1;
            
            if(count==3){
                int q=p;
                while(q<size-1){
                    nums[q] = nums[q+1];
                    q++;
                }
                size--;
                count--;
            }
            else
                p++;
        }
        return size;
    }
};