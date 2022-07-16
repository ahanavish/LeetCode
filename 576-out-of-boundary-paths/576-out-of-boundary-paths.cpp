class Solution {
public:
    int dp[50][50][51];
    long long mod = 1e9 + 7;
    int helper(int &m, int &n, int steps, int positionRow, int positionColumn) {
        if(positionRow < 0 || positionColumn < 0 || positionRow >= m || positionColumn >= n) {
            return 1;
        }
        if (steps <= 0) {
            return 0;
        }
        if(dp[positionRow][positionColumn][steps] != -1) {
            return dp[positionRow][positionColumn][steps];
        }
        int left = helper(m, n, steps - 1, positionRow, positionColumn - 1);
        int right = helper(m, n, steps - 1, positionRow, positionColumn + 1);
        int up = helper(m, n, steps - 1, positionRow - 1, positionColumn);
        int down = helper(m, n, steps - 1, positionRow + 1, positionColumn);
        return dp[positionRow][positionColumn][steps] = ((up % mod) + (down % mod) + (left % mod) + (right % mod)) % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return helper(m, n, maxMove, startRow, startColumn);
    }
};