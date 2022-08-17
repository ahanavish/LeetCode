class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        
        for (int i=0; i<words.size(); i++) {
            string start = sortt(words[i]), startCopy = words[i];
            
            while (i+1<words.size() && start==sortt(words[i+1]))   
                i++;
            
            ans.push_back(startCopy);
        }
        
        return ans;
    }
    
    string sortt(string s){
        sort(s.begin(), s.end());
        return s;
    }
};