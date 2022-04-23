class Solution {
public:
    unordered_map<int,string>mp;
    string encode(string s) {
        int i=0;
        int n=s.length();
        int count=1;
        string en="";
        while(count>0)
        {
            int x=i+5;
            if(x>n) {
                string p=s.substr(i);
                mp[count]=p;
                break;
            } else{
                string p=s.substr(i,5);
                mp[count]=p;
                i=i+5;
                ++count;
            }
        }
        en=to_string(count);
       return en;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string sh) {
        int count=stoi(sh);
        string res="";
        for(int i=1;i<=count;++i)
        {
            res=res+mp[i];
        }
        return res;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));