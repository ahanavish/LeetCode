class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1; i<10; i++)
            func(i, n-1, k, ans);
        
        return ans;
    }
    
    void func(int i, int n, int k, vector<int> &ans){
        if(n==0){
            ans.push_back(i);
            return;
        }
        
        int last=i%10;
        if(last+k<10){
            int new1=i*10+(last+k);
            func(new1, n-1, k, ans);
        }
        if(last-k>=0 && k!=0){
            int new2=i*10+(last-k);
            func(new2, n-1, k, ans);
        }
    }
};