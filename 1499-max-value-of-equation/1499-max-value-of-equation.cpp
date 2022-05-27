class Solution {
public:
	int findMaxValueOfEquation(vector<vector<int>>& p, int k) {
		int n = p.size(), ans = INT_MIN;
		deque <int> d;
        
		for (int i = 0; i < n; i++) {
			while(d.size() and p[i][0] - p[d.front()][0] > k)  
				d.pop_front();

			if(d.size())
				ans = max(ans, p[i][0] + p[i][1] - (p[d.front()][0] - p[d.front()][1]));
			
			while(d.size() and p[i][0] - p[i][1] <= p[d.back()][0] - p[d.back()][1]) 
				d.pop_back();
		
			d.push_back(i);
		}
		return ans;
	}
};