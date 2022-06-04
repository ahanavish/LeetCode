class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string str="";
        int i =0;
        while(s[i]){
            if(s[i] != ' '){
                str+=s[i];
            }else{
                if(str != "") v.push_back(str);
                str="";
            }
            i++;
        }
        if(str != "") v.push_back(str);
        
        string ans = "";
        i = v.size()-1;
        while(i>0){
            ans += v[i--] + " ";
        }
        ans+=v[0];
        return ans;
    }
};


