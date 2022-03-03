class Solution {
public:
    bool isSubsequence(string s, string t) {
        queue <char> sub;
        for(auto c:s)
            sub.push(c);
        
        int i=0;
        while(i<t.length()){
            if(t[i]==sub.front() && !sub.empty())
                sub.pop();
            i++;
        }
        
        if(sub.empty())
            return true;
        return false;
    }
};

 