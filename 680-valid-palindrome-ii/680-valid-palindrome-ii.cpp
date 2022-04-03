class Solution {
public:
    bool validPalindrome(string s) {
        int low=0, high=s.size()-1;
        
        while(low<high){
            if(s[low]!=s[high])
                return pal(s, low+1, high) || pal(s, low, high-1);
            low++;
            high--;
        }
        
        return true;
    }
    
    bool pal(string s, int low, int high){
        while(low<high){
            if(s[low]!=s[high])
                return false;
            low++;
            high--;
        }
        
        return true;
    }
};