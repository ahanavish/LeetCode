class Solution {
public:
    int titleToNumber(string column) {
        int place=1, ans=0;

        for(int i=column.length()-1; i>=0; i--){
            ans += (column[i]-64)*place;
            if(i)
                place *= 26;
        }
        
        return ans;
    }
};