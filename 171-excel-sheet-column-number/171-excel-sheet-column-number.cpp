class Solution {
public:
    int titleToNumber(string column) {
        long long int place=1;
        int ans=0;

        for(int i=column.length()-1; i>=0; i--){
            ans += (column[i]-64)*place;
            place *= 26;
        }
        
        return ans;
    }
};