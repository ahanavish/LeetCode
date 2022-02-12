class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& words) {
        unordered_set <string> wordset;
        bool present=false;
        for(auto wo:words){
            if(end == wo)
                present=true;
            wordset.insert(wo);
        }
        if(!present)
            return 0;
        
        queue <string> q;
        q.push(begin);
        int depth=0;
        while(!q.empty()){
            depth++;
            int level=q.size();
            
            while(level--){
                string word = q.front();
                q.pop();
                for(int i=0; i<word.length(); i++){
                    string temp = word;
                    for(char t='a'; t<='z'; t++){
                        temp[i]=t;

                        if(temp == word)
                            continue;
                        
                        if(temp == end)
                            return depth+1;

                        if(wordset.find(temp)!=wordset.end()){
                            q.push(temp);
                            wordset.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};