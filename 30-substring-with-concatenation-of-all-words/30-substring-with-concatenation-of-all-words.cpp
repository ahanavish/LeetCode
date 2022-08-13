class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n=s.length(), len=words[0].length(), total=words.size();
        unordered_map<string, int> m1;
        for(auto w :words)
            m1[w]++;
        
        for(int i=0; i<n-total*len+1; i++){
            int j=i, tot=0;
            unordered_map<string, int> m2 = m1;
            while(tot<total && j+len-1<n){
                string w = s.substr(j, len);
                if(m2.find(w)!=m2.end() && --m2[w]>=0){
                    tot++;
                    j += len;
                }
                else
                    break;
            }
            if(tot == total)
                ans.push_back(i);
        }
        
        
        return ans;
    }
};       

       