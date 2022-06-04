class Solution {
public:
    string reverseWords(string s) {
          string res;
        int n=s.size();
        int i=0,j=n-1;
        
        while(i<n && s[i]==' ') i++;
        
        while(i<n){
            int j=i;
            string w;
            while(i<n && s[i]!=' ') w+=s[i++];
            reverse(w.begin(),w.end());
            res+=w;
    
            while(i<n && s[i]==' ') i++;
            if(i!=n) res+=' ';
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};


