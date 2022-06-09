class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int carry = 0;
        string ans="";
        
        int i=0;
        while(i<a.length() && i<b.length()){
            int sum = carry + (a[i] - '0') + (b[i]-'0');
            carry = sum>=2 ? 1 : 0;
            ans += (sum%2) + '0';
            i++;
        }
        

        while(i<a.length()){
            int sum = carry + (a[i] - '0');
            carry = sum>=2 ? 1 : 0;
            ans += (sum%2) + '0';
            i++;
        }
        
        while(i<b.length()){
            int sum = carry + (b[i] - '0');
            carry = sum>=2 ? 1 : 0;
            ans += (sum%2) + '0';
            i++;
        }
        
        if(carry) ans += carry + '0';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};