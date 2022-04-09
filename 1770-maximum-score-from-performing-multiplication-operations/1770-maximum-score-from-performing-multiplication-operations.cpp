class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multi) {
        int m=multi.size(), n=nums.size();
        
        vector <vector<int>> dp (m+1, vector<int> (m+1));
        
        for(int i=m-1; i>=0; i--){
            for(int left=i; left>=0; left--){
                int mult = multi[i], right = n-1-(i-left);
                dp[i][left] = max(mult*nums[left]+dp[i+1][left+1], mult*nums[right]+dp[i+1][left]);
            }
        }
        
        return dp[0][0];
    }
};

