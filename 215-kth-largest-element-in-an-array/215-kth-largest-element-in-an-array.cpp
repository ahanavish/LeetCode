class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int> heap;
        for(auto num : nums)
            heap.push(num);
            
        while(k>1){
            heap.pop();
            k--;
        }
            
        return heap.top();
    }
};