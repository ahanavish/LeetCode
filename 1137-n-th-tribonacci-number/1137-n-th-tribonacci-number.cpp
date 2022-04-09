class Solution {
public:
    map <int, int> mapp;
    int tribonacci(int n) {
        if(n==0)
            return mapp[n] = 0;
        if(n<3)
            return mapp[n] = 1;
        
        if(mapp.find(n)==mapp.end())
            mapp[n] = tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
        
        return mapp[n];
    }
};