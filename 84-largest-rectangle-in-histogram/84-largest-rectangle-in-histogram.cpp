class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <int> s;
        int maxA = 0;
        
        for(int i=0; i<=heights.size(); i++){
            while(!s.empty() && (i==heights.size() || heights[i]<heights[s.top()])){
                int nse = s.top();
                s.pop();
                int width = s.empty()? i : i-s.top()-1;
                maxA = max(maxA, width*heights[nse]);
            }
            s.push(i);
        }
        return maxA;
    }
};
