class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string>st1(words.begin(),words.end());
        set<string>st2(words.begin(),words.end());
        
        for(auto x:st1){
            for(int i=1;i<x.size();i++){
                st2.erase(x.substr(i));
            }
        }
        int c = 0;
        for(auto x:st2){
            c+=(x.size()+1);
        }
        return c;
    }
};