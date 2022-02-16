class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        // find unique y's so the adjacent y_diff are heights
        // sweep all rectangles along x for each height
        
        set<int> ys;
        for (auto const & r: rectangles)
        {
            ys.insert(r[1]);
            ys.insert(r[3]);
        }
        
        // sort rectangle with x_start
        sort(rectangles.begin(), rectangles.end(), [](
                            auto const & r1, auto const & r2
                            ){return r1[0] < r2[0];});
        
        // sweep from bottom to top
        int prev_y= *ys.begin();
        long long res = 0;
        int mod = pow(10, 9)+7;
        for (auto y: ys)
        {
            long long height = y-prev_y;
            long long x_start = rectangles.front()[0];
            long long x_end = x_start;
            for (auto const & r: rectangles)
            {
                // check if r fully occupy in between y and prev_y
                if (r[1] <= prev_y && r[3] >=y)
                {
                    if (r[0] > x_end)
                    {
                        res+= height * (x_end-x_start) % mod;
                        x_start = r[0];
                    }
                    if (r[2] > x_end)
                    {
                        x_end = r[2];
                    }
                }
            }
            res+= height * (x_end-x_start) % mod;
            prev_y = y;
        }
        
        return res % mod;
    }
};