class Solution {
public:
    string reverseWords(string s) {
        stack <string> st;
        for(int i=0; i<s.length(); i++){
            if(s[i] == ' ')
                continue;
            
            string temp = "";
            while(i<s.length() && s[i] != ' ')
                temp += s[i++];
            
            st.push(temp);
        }
        
        string ans="";
        while(!st.empty()){
            ans += st.top();
            st.pop();
            if(st.size() != 0)
                ans += " ";
        }
        
        return ans;
    }
};


