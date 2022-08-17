class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set <string> s;
        unordered_map <char, string> m {{'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."}, 
                                        {'f', "..-."}, {'g', "--."},{'h', "...."}, {'i', ".."}, {'j', ".---"}, 
                                        {'k', "-.-"}, {'l', ".-.."}, {'m', "--"}, {'n', "-."}, {'o', "---"}, 
                                        {'p', ".--."}, {'q', "--.-"}, {'r', ".-."} ,{'s', "..."}, {'t', "-"} ,
                                        {'u', "..-"}, {'v', "...-"}, {'w', ".--"}, {'x', "-..-"}, {'y', "-.--"}, 
                                        {'z', "--.."}};
        
        for(auto w : words){
            string st;
            for(int i=0; i<w.length(); i++)
                st = st+m[w[i]];
            s.insert(st);
        }
        
        return s.size();
    }
};