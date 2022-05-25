class Solution {
public:
    vector <int> nums;
    int reversePairs(vector<int>& nums) {
        this->nums = nums;
        return mergesort(0, nums.size()-1);
    }
    
    int mergesort(int low, int high){
        if(low>=high)
            return 0;
        int mid = (low+high)/2, count=0;
        count += mergesort(low, mid);
        count += mergesort(mid+1, high);
        count += merge(low, mid, high);
        return count;
    }
    
    int  merge(int low, int mid, int high){
        int j = mid+1, count=0;
        for(int i=low; i<=mid; i++){
            while(j<=high && nums[i]>2ll*nums[j])
                j++;
            count += (j-(mid+1));
        }
        
        vector <int> temp;
        int i=low;
        j=mid+1;
        while(i<=mid && j<=high){
            if(nums[i]<=nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }
        
        while(i<=mid)
            temp.push_back(nums[i++]);
            
        while(j<=high)
            temp.push_back(nums[j++]);
        
        for(int k=low; k<=high; k++)
            nums[k] = temp[k-low];
        
        return count;
    }
};