class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.empty())
            return 0;
        int sol = INT_MIN;
        int row= matrix.size(), column = matrix[0].size();
        for(int l=0;l<column;l++){
            vector<int> temp(row,0);
            for(int r=l; r<column;r++){
                for(int i=0;i<row;i++){
                    temp[i] += matrix[i][r];
                }
            set<int> accuSet;
            accuSet.insert(0);
            int sums = 0, max_sum = INT_MIN;
            for (int sum : temp) {
                sums += sum;
                set<int>::iterator it = accuSet.lower_bound(sums - k);
                if (it != accuSet.end()) max_sum = max(max_sum, sums - *it);
                accuSet.insert(sums);
            }
            sol = max(sol, max_sum);
            }
        }
        return sol;
    }
};