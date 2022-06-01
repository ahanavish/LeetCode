class Solution {
public:
    int strStr(string hay, string need) {
        if(need.length()==0)
            return 0;
        
        int i=0, j=0, ch=0;
        while(i<=hay.length()){
            cout<<hay[i]<<need[j]<<" ";
            if(ch==need.size())
                return i-ch;
            
            if(ch!=0 && hay[i]!=need[j]){
                i-=ch-1;
                ch=0;
                j=0;
            }
            
            if(hay[i] == need[j]){
                j++;
                ch++;
            }
            
            i++;
        }
        
        return -1;
    }
};