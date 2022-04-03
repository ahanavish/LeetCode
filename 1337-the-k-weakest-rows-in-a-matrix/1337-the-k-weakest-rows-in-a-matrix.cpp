class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector <vector<int>> track;
        
        for(int i=0; i<m; i++){
            int j=0;
            while(j<n && mat[i][j]!=0)
                j++;
          
            vector <int> t{j, i};
            track.push_back(t);
        }
        
        sort(track.begin(), track.end());
        vector <int> res;
        for(int i=0; i<k; i++)
            res.push_back(track[i][1]);
        
        return res;
    }
};