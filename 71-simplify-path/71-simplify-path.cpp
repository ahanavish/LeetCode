class Solution {
public:
    string simplifyPath(string path)
    {
        vector<string> foo;
        string cur;
        string res;
        path += "/"; /* simplifies code as do not need to check cur at end */
        for (int i = 1; i < path.size(); i++) {
            char c = path[i];
            if (c != '/')
                cur += c;
            else {
                
                if (cur == "..") {
                if (foo.size() > 0) foo.pop_back();
                }
                else if (cur  != "" && cur != ".")
                    foo.push_back(cur);
             
            cur = "";
            }   
        }
        if (foo.size() == 0) return "/";
        for (auto &x : foo) 
            res += "/" + x;
        
        return res;
    }
};