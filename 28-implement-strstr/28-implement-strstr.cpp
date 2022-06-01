class Solution {
public:
    int strStr(string hay, string need) {
        int m=hay.length(), n=need.length();
        if(!n)
            return 0;
        
        vector <int> kmp = kmpcompute(need);
        for(int i=0, j=0; i<m;){
            if(hay[i]==need[j])
                i++, j++;
            if(j==n)
                return i-j;
            
            if(i<m && hay[i]!=need[j])
                j? j = kmp[j-1] : i++;
        }
        return -1;
    }
    
    vector <int> kmpcompute(string need){
        int n = need.length();
        vector <int> kmp(n, 0);
        
        for(int i=1, j=0; i<n;){
            if(need[i] == need[j])
                kmp[i++] = ++j;
            else if(j)
                j = kmp[j-1];
            else
                kmp[i++] = 0;
        }
        return kmp;
    }
};