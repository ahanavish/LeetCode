class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.length();
        stack<char> st;
        string ans="";
        unordered_map<char,int> mp;  // for storing frequency of char
        unordered_map<char,bool> exist;  // for checking if char is present in output
        for(int i=0;i<n;i++){
            exist[s[i]]=false;
            if(mp.count(s[i])>0){
                mp[s[i]]++;
            }
            else{
                mp[s[i]]=1;
            }
        }
        for(int i=0;i<n;i++){
            mp[s[i]]--; 
            if(exist[s[i]]==true){               // if char is already present in output continue
                continue;
            }
            while(!st.empty() && st.top()>s[i] && mp[st.top()]>0){  
                // loop for checking whether the string is in lexicographical order
                    exist[st.top()]=false;
                    st.pop(); 
            }
            st.push(s[i]);
            exist[s[i]]=true;
        }
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};
