class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		vector<vector<bool>> dp(n, vector<bool>(n, false));
		string ans;
		for (int g = 0; g < n; g++) {
			for (int i = 0, j = g; j < n; i++, j++) {
				if (g == 0) {
					dp[i][j] = true;
				} else if (g == 1) {
					if (s[i] == s[j]) {
						dp[i][j] = true;
					} else {
						dp[i][j] = false;
					}
				} else {
					if (s[i] == s[j]) {
						dp[i][j] = dp[i + 1][j - 1];
					} else {
						dp[i][j] = false;
					}
				}
				if (dp[i][j]) ans = s.substr(i, g + 1);
			}
		}
		return ans;
	}
};