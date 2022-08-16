class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        
        for(int i=0; i<s.length(); i++){
            if(m.find(s[i])==m.end())
                m[s[i]]=i;
            else
                m[s[i]]=INT_MAX;
        }
        
        int ans=INT_MAX;
        for(auto e : m)
            ans = min(ans, e.second);
        
        return ans==INT_MAX?-1:ans;
    }
};

