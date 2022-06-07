class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length())
            return "";
        
        int low=0, start=0, minlength=INT_MAX, counter=0;
        unordered_map <char, int> mapt;
        for(int i=0; i<t.length(); i++)
            mapt[t[i]]++;
        
        for(int high=0; high<s.length(); high++){ 
            if(mapt[s[high]]>0)
                counter++;
            
            mapt[s[high]]--;
            
            if(counter == t.length()){
                while(mapt[s[low]]<0 && low<high)
                    mapt[s[low++]]++;
                
                if(minlength>high-low){
                    minlength = high-low+1;
                    start = low; 
                }
            }
        }
        
        return minlength == INT_MAX? "" : s.substr(start, minlength);
    }
};
        
       