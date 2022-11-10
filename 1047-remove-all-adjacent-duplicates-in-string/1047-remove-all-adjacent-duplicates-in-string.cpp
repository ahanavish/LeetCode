class Solution 
{
public:
    string removeDuplicates(string s) 
    {
        string ss;
        
        for(char c : s)
            if (!ss.empty() && ss.back() == c) ss.pop_back(); 
            else                     ss.push_back(c); 
        
        return ss;
    }
};