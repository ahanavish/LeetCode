class Solution {
public:
    vector<int> partitionLabels(string s) {
        // stores evry char start and last index 
        vector<pair<int,int>> temp(26, make_pair(-1,-1));
        // stores result
        vector<int> res;
        
        // setting the start and end of each charcter
        for(int i = 0; i < s.length(); i++) {
            int x = s[i]-'a';
            if(temp[x].first == -1) temp[x].first = i;
            temp[x].second = i;
        }
        
        // sorting such that all the starting indices are sorted
        sort(temp.begin(),temp.end());
        
        int st = 0, e = 0;
        // by iterating on temp, get the longest consecutive pairs which have continuous series 
        for(int i = 0; i < 26; i++) {
            auto x = temp[i];
            if(x.first != -1) {
                if(x.first<=e) {
                    e = max(e,x.second);
                }
                else {
                    res.push_back(e-st+1);
                    st = x.first;
                    e = x.second;
                }
            }
        }
        
        // handling last part of string
        res.push_back(e-st+1);
        return res;
    }
};