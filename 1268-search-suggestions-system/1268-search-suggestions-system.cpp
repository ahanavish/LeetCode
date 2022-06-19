class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& pdts, string sW) {
        
        sort(pdts.begin(),pdts.end());
        vector<vector<string>>ans;
        
        string t;
                
        int j=0,l=sW.length(),n=pdts.size();
        
        for(auto ch:sW){
            t+=ch;j++;
            int x=3;
            vector<string>v;
            for(int i=0;i<n;i++){
                if(pdts[i].substr(0,j)==t && x>0){
                    v.push_back(pdts[i]);
                    x--;                    
                }
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};