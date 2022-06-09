class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length()-1, j=b.length()-1, c=0;
        string ans="";
        
        while(i>=0 || j>=0 || c==1){
            c += i>=0? a[i--] - '0' : 0;
            c += j>=0? b[j--] - '0' : 0;
            ans = char(c%2 + '0') + ans;
            c /= 2;
        }
        
        return ans;
    }
};