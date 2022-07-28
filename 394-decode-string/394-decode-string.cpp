class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        
        for(int i=0; i<s.length(); i++){
            if(s[i]!=']')
                st.push(s[i]);
            else{
                string str = "";
        
                while(st.top() != '['){
                    str =st.top()+str;
                    st.pop();
                }
                st.pop();
                
                string number = "";
                while(!st.empty() && isdigit(st.top())){
                    number = st.top() + number;
                    st.pop();
                }
                int freq=stoi(number);
                
                while(freq--)
                    for(int j=0; j<str.length() ; j++)
                        st.push(str[j]);
            }
        }
        
        string ans="";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
                
        return ans;
    }
};


        
     