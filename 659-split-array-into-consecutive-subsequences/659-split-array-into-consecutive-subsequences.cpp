class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map <int, int> freq;
        for(auto n: nums)
            freq[n]++;
        
        unordered_map <int, int> needed;
        for(auto n: nums){
            if(freq[n]==0)  continue;
            
            if(needed[n]>0){
                needed[n]--;
                freq[n]--;
                
                needed[n+1]++;
            }
            else if(freq[n]>0 && freq[n+1]>0 && freq[n+2]>0){
                freq[n]--;
                freq[n+1]--;
                freq[n+2]--;
                
                needed[n+3]++;
            }
            else
                return false;
        }
        
        return true;
    }
};

