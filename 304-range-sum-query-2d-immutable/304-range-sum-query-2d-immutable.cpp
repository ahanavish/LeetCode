class NumMatrix {
public:
    vector<vector<int>> mat;
    
    NumMatrix(vector<vector<int>>& matrix) {
        mat = matrix;
        for(int i=0; i<matrix.size(); i++) {
            int s = 0;
            for(int j=0; j<matrix[i].size(); j++) {
                s += matrix[i][j];
                mat[i][j] = i - 1 >= 0 ? s + mat[i - 1][j] : s;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int a = mat[row2][col2];
        int b = col1 - 1 >= 0 ? mat[row2][col1 - 1] : 0;
        int c = row1 - 1 >= 0 ? mat[row1 - 1][col2] : 0;
        int d = (row1 - 1 >= 0) && (col1 - 1 >= 0) ? mat[row1 - 1][col1 - 1] : 0;
        
        return a - b - c + d;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */