class Solution {
public:
    int trap(vector<int>& height) {
        stack <int> st;
        int i=0, ans=0;
        while(i<height.size()){
            if(st.empty() || height[i]<=height[st.top()])
                st.push(i++);
            else{
                int curr=st.top();
                st.pop();
                if(!st.empty()){
                    int pse = height[st.top()], nse = height[i];
                    int col = min(pse, nse);
                    ans += (col-height[curr])*(i-st.top()-1);
                }
            }
        }
        
        return ans;
    }
};