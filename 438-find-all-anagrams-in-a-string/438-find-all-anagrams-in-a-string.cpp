class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> count (26, 0), ret;
        int diff = p.size();
        for (auto ch : p) count[ch - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            diff += count[s[i] - 'a']-- > 0 ? -1 : 1;
            if (i >= p.size())
                diff += count[s[i - p.size()] - 'a']++ >= 0 ? 1 : -1;
            if (diff == 0) ret.push_back(i - p.size() + 1);
        }
        return ret;
    }
};