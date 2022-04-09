class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int len=nums.size(), maxele=0;
        for(int i=0;i<len;i++)
          maxele=max(maxele,nums[i]);   //found max element 

        vector<long long> count(maxele+1,0);
        for(int i=0;i<len;i++)
            count[nums[i]]++;           //counting frequency of each element

        //deciding which element when inserted would result in more points. 
        //Eg: for [3, 4, 2], we start with inserting 2 using count array, resulting in count[2]=2
        //Then we check for 3, inserting 3 would mean not inserting 2, resulting in count[3]=3
        //Then we check for 4, inserting 4 would mean not inserting 3, but inserting 2, resulting in count[4]=4+2=6
        for(int i=2;i<=maxele;i++)
            count[i]=max(i*count[i]+count[i-2],count[i-1]);
        
        return count[maxele];
    }
};