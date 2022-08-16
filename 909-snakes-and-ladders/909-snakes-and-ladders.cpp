class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<bool> vis(n*n+1, false);
        queue<pair<int, int>> q;
        q.push({1, 0});
        vis[1]=true;
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int no=p.first, dis=p.second;
            if(no==n*n)
                return dis;
            
            int r, c;
            for(int i=1; i<=6 && no+i<=n*n; i++){
                getcord(n, no+i, r, c);
                int new_no = board[r][c]==-1? no+i:board[r][c];
                if(vis[new_no]==false){
                    vis[new_no]=true;
                    q.push({new_no, dis+1});
                }
            }
        }
        
        return -1;
    }
        
    void getcord(int n, int no, int &r, int &c){
        r = n-1-(no-1)/n;
        c = (no-1)%n;
        if((n%2==1 && r%2==1) || (n%2==0 && r%2==0))
            c = n-1-c;
    }
};


