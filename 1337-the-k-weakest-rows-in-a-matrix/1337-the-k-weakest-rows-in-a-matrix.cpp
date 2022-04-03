class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue <pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
        int m = mat.size(), n = mat[0].size();
        vector <vector<int>> track;
        
        for(int i=0; i<m; i++){
            int j=0;
            while(j<n && mat[i][j]!=0)
                j++;
          
            pq.push({j, i});
        }
        
        vector <int> res;
        for(int i=0; i<k; i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};