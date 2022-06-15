class Solution {
public:
	int longestStrChain(vector<string>& words) {
		for(auto& it: words){
			dp[it] = -1;
		}
		for(auto& it: words){
			ans = max(ans, recur(words, it));
		}

		return ans;
	}

	int recur(vector<string>& words, string input){
		if(dp[input] == 0) return 0;

		if(dp[input] == -1){
			string temp = input;
			int size = input.size();
			int MAX_CHAIN = -1;
			for(int i = 0; i < size; ++ i){
				MAX_CHAIN = max(MAX_CHAIN, recur(words, input.erase(i, 1)));
				input = temp;
			}
			dp[input] = MAX_CHAIN + 1;
		}

		return dp[input];
	}
private:
	// this is the container stoing <string, max_chain_start_from_this_string>
	// the min length is 1
	unordered_map<string, int> dp; // initialize as -1
	int ans = 1;
};