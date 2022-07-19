class Solution {
public:
    int numDecodings(string s) {
        if(s.empty())
            return 0;
        
        int next2=0, next1=1, curr=0;
            
        for(int ind=s.length()-1; ind>=0; ind--){
            if(s[ind] == '0')
                curr = 0;
            else{
                int one_char = next1;
                int two_char = 0;
                if(ind<s.length()-1 && (s[ind]=='1'|| (s[ind]=='2' && s[ind+1]<'7'))) 
                    two_char = next2;

                curr = one_char+two_char;
            } 
            next2 = next1;
            next1 = curr;
        }
        
        return curr;    
    }
};
