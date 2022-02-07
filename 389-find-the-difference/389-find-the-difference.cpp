class Solution {
public:
    char findTheDifference(string s, string t) {
        map <char, int> m;
        for(auto st:t)
            m[st]++;
        
        for(auto st:s){
            m[st]--;
            if(m[st]==0)
                m.erase(st);
        }
        
        map <char, int> :: iterator it;
        it = m.begin();
        return (*it).first;
    }
};