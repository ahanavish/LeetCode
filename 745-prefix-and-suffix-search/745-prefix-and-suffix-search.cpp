class WordFilter {
public:
    
    unordered_map<string,int> mp;
    
    WordFilter(vector<string>& words) {
        for(int i=0;i<words.size();i++)
        {
            string s = words[i];

            for(int j=0;j<s.length();j++)
            {
                string p = s.substr(0,j+1);
                for(int k=s.length()-1;k>=0;k--)
                {
                    string s1 = p + "|" + s.substr(k);
                    mp[s1] = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string s = prefix + "|" + suffix;
        
        if(mp.find(s)!=mp.end())
            return mp[s];
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */