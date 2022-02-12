class Solution {
public:
    struct Cell {
        int x;
        int y;
        int effort;
        
        bool operator<(const Cell& other) const {
            return this->effort > other.effort;
        }
    };

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> min_effort(m, vector<int>(n, INT_MAX));         //constructed 2D array of mxn
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        min_effort[0][0] = 0;
        priority_queue<Cell> pq;
        pq.push({0, 0, 0});
        
        while (!pq.empty()) {
            Cell curr = pq.top();
            pq.pop();

            for (auto [dx, dy] : directions) {
                int neighbor_x = curr.x + dx;
                int neighbor_y = curr.y + dy;
                if (!isValid(neighbor_x, neighbor_y, m, n)) {
                    continue;
                }
                int effort_from_curr = max(curr.effort, abs(heights[curr.x][curr.y] - heights[neighbor_x][neighbor_y]));
                if (effort_from_curr < min_effort[neighbor_x][neighbor_y]) {
                    min_effort[neighbor_x][neighbor_y] = effort_from_curr;
                    pq.push({neighbor_x, neighbor_y, effort_from_curr});
                }
            }
        }
        return min_effort[m-1][n-1];
    }
    
    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};