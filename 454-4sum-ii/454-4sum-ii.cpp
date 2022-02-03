class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();       //all arrays have equal length
        
        map <int, int> m;           //initial values are 0 by default
        for(int i:nums1)            //mapping sums of every element of nums1 with nums2 in m
            for(int j:nums2)
                m[i+j]++;           //frequence of sum is stored
        
        
        int count=0;
        for(int k:nums3)            
            for(int l:nums4)
                count += m[-(k+l)]; //incrementing count with freq of negative of sums of every element of nums3 with nums4 present in m
        
        return count;               //returning count
    }
};