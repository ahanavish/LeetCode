class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rts = 0;
        
        for(int i = 0; i < matrix.size() - 1; i++) {
            if(matrix[i][0] == target) {
                return true;
            } else if (i < matrix.size() && matrix[i][0] < target && matrix[i+1][0] > target) {
                rts = i;
                break;
            } else {
                rts = matrix.size() - 1;
            }
        }
        
        auto mat = matrix[rts];
        
        int l = 0;
        int r = mat.size() - 1;
        
        
        while(l <= r) {
            int mid = (l+r) / 2;
            
            if(mat[mid] == target) {
                return true;
            } else if (mat[mid] < target) {
                l = mid + 1;
            } else {
                r = mid-1;
            }
        }
        
        return false;
    }
};