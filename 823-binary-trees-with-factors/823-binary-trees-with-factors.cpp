class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map <int, long> m;
        sort(arr.begin(), arr.end());
        int ans=0, mod=1e9+7;
        
        for(int i=0; i<arr.size(); i++){
            long ways=1;
            for(int j=0; arr[j]<=sqrt(arr[i]); j++){
                if(arr[i]%arr[j]==0){
                    int f1=arr[j];
                    int f2=arr[i]/arr[j];
                    if(m.find(f2) != m.end())
                        ways += m[f1]*m[f2]*(f1==f2?1:2);
                }
            }
            m[arr[i]]=ways;
            ans = (ans+ways)%mod;
        }
        
        return ans;
    }
};