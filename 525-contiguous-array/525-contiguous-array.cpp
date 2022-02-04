class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0;             
        unordered_map<int,int>track;
        int ans=0;
        
        track[0]=-1;                           // to imply sum=0 is obtained at index=-1
        for(int i=0 ; i<nums.size() ; ++i)
        {
            sum += nums[i]==1? 1 : -1;         //if 1->sum=1 and 0->sum=-1
            auto it = track.find(sum);         //finding if the sum obtained now is already present in map
            
            if(it != track.end())              //if present, then
                ans = max(ans ,i-it->second);  //updating ans
            else
                track[sum] = i;                // else condition used to store left most index of the sum 
        }
        return ans;
    }
};