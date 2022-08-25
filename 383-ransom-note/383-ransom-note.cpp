class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map <char, int> m;
        for(auto c : magazine)
            m[c]++;
        
        for(auto c : ransomNote)
            if(m[c]==0)
                return false;
            else
                m[c]--;
        
        return true;
    }
};