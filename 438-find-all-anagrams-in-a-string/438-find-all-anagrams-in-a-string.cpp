class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ss=s.size(), ps=p.size();
        if(ss<ps)           //since not possible
            return {};
        
        vector<int> freq(26,0), window(26,0), ans;
        
        for(int i=0; i<ps; i++){    //first window
            freq[p[i]-'a']++;       //using it to create our freq which will be used to compare with window later
            window[s[i]-'a']++;
        }
        if(freq == window) 
            ans.push_back(0);       //if first window itself is 

        for(int i=ps; i<ss; i++){
            window[s[i-ps]-'a']--;
            window[s[i]-'a']++;

            if(freq == window) 
                ans.push_back(i-ps+1);
        }
        
        return ans;
    }
};