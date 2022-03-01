class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size(); 
        vector <string> ans;
        if(n == 1){
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        
        for(int i=0; i<n; i++){
            string temp = to_string(nums[i]);
            bool t = false;
            while(i<n-1 && nums[i]+1 == nums[i+1]){
                i++;
                t = true;
            }
            if(t){
                temp += "->";
                temp += to_string(nums[i]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};





 