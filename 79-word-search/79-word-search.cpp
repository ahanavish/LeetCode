class Solution {
public:
    vector<vector<char>> board;
    string word;
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        int m=board.size(), n=board[0].size();
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(board[i][j]==word[0] && dfs(i, j, 0))
                    return true;
        
        return false;   
    }
    
    bool dfs(int i, int j, int w){
        if(w==word.size())
            return true;
        
        if(i<0 || i>=board.size() || j<0 || j>=board[i].size() || word[w]!=board[i][j])
            return false;
        
        board[i][j] = '0';
        bool res = (dfs(i+1, j, w+1) || dfs(i, j+1, w+1) || dfs(i-1, j, w+1) || dfs(i, j-1, w+1));
        
        board[i][j]=word[w];
        return res;
    }
};

		