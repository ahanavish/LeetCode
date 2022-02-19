class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue <int> maxheap;
        
        int minn=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==1)        //odd
                nums[i]*=2;
            
            minn=min(nums[i], minn);
            maxheap.push(nums[i]);
        }
        
        int dev=INT_MAX;
        while(maxheap.top()%2==0 && !maxheap.empty()){
            int maxx=maxheap.top();
            maxheap.pop();
            
            dev = min(maxx-minn, dev);
            minn = min(minn, maxx/2);
            maxheap.push(maxx/2);
        }
        
        return min(dev, maxheap.top()-minn);
    }
};