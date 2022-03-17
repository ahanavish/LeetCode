class Solution {
public:
    int scoreOfParentheses(string s) {
       stack<int> st;
       for(int i=0;i<s.size();i++)
       {
           if(s[i]=='(')
           {
               st.push(0);
           }
           else
           {
              int tmp = st.top();
              st.pop();
              if(tmp>0)
              {
                  int val = tmp;
                  while(!st.empty() and st.top()>0)
                  {
                      val += st.top();
                      st.pop();
                  }
                  st.pop();
                  st.push(2*val);
              }
              else
              {
                  st.push(1);
              }
              
           }
       }
        int ans = 0;
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};