class Solution {
public:
    int strStr(string hay, string need) {
        int m=hay.size(), n=need.size();
        
        for(int i=0; i<=m-n; i++){
            int j=0;
            for(; j<n; j++)
                if(hay[i+j] != need[j])
                    break;
            if(j==n)
                return i;
        }
        return -1;
    }
};