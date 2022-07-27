class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int curr_color=image[sr][sc];
        dfs(image, sr, sc, curr_color, color);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int curr_color, int color) {
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || image[sr][sc]!=curr_color || image[sr][sc]==color)
            return;
        
        image[sr][sc]=color;
        dfs(image, sr+1, sc, curr_color, color);
        dfs(image, sr-1, sc, curr_color, color);
        dfs(image, sr, sc+1, curr_color, color);
        dfs(image, sr, sc-1, curr_color, color);
    }
};