class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(st.top()!=-1 && s[i]==')' && s[st.top()]=='('){
                st.pop();
                ans=max(ans,i-st.top() );
              }else{
                st.push(i);
            }
        }
        return ans;
    }
};