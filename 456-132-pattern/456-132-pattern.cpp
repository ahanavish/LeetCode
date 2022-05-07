class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int n=nums.size();
        if( n < 3 ) return false;
        
        int mins[n];
        mins[0] = nums[0];
        for(int i=1;i<n;i++){
            mins[i] = min(mins[i-1], nums[i]);
        }
        
        stack<int> st;
        
        for(int i=n-1;i>=0;i--){
            
            while( st.empty()==false && st.top() <= mins[i] ) st.pop();

            if( st.empty()==false && st.top() < nums[i] ) return true;

            st.push(nums[i]);
        }
        
        return false;
    }
};