class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        int len = words.size(), plen = pattern.length();
        
        // a->m
        // b->e
        for(int i=0; i<len; i++){
            int wrong=0;
            map <char, char> m;
            vector<int> visited(26, 0);
            
            for(int j=0; j<plen; j++){
                if(visited[words[i][j]-'a']!=0){
                    if(visited[words[i][j]-'a']!=pattern[j]-'a'+1){
                        wrong++;
                        break;
                    }   
                }
                else
                    visited[words[i][j]-'a']=pattern[j]-'a'+1;
                
                if(m.find(pattern[j]) != m.end()){    //present
                    if(m[pattern[j]] != words[i][j]){
                        wrong++;
                        break;
                    }
                }
                else{
                    m[pattern[j]]=words[i][j];
                }
            } 
            
            if(wrong==0)
                ans.push_back(words[i]);
        }
        
        return ans;
    }
};