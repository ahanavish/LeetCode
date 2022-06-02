class Solution {
public:
    vector <string> res;
    vector<string> generateParenthesis(int n) {
        rec("", n, n);
        return res;
    }
    
    void rec(string c, int left, int right){
        if(left == 0 && right == 0){
            res.push_back(c);
            return;
        }
        
        if(left>0)
            rec(c+ "(", left-1, right);
        if(right>left)
            rec(c+ ")", left, right-1);
    }
};