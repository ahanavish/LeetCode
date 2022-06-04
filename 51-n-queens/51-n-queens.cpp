class Solution {
public:
    int num;        //size of chessboard/no. of queens
    vector<vector<char>> board;
    vector<vector<string>> ans;
    
    //function to check whether the cell with 'ith' row and 'jth' column is safe to place queen or not.
    bool isSafeToPlace(int i, int j){
        for(int k=0;k<num;k++){     //check if there is any queen exist in current column or row
            if(board[i][k] == 'Q' || board[k][j] == 'Q')
                return false;
        }
        
        int x = i,y = j;
        while(x >= 0 and y <num){   //check if there is any queen exist in right diagonal
            if(board[x--][y++] == 'Q')
               return false;
        }
        
        x = i,y = j;
        while(x >= 0 and y>= 0){  //check if there is any queen exist in left diagonal
            if(board[x--][y--] == 'Q')
               return false;
        }
        
        return true;
    }
    
    bool NQueen(int i){
        //base case
        if(i==num){   // all queens placed successfully so store in ans.
            string str; vector<string> v; 
            for(int x=0;x<num;x++){
                str = "";
                for(int y=0;y<num;y++)
                    str += board[x][y];
                v.push_back(str);
            }
            ans.push_back(v);
            return false;   //false is return to get all possible combinations
            //if true is return then only 1 combination is stored.
        }
        
        //recursive case
        for(int j = 0; j< num;j++){ //try to place queen in each cell of current row
            if(isSafeToPlace(i,j)){
                board[i][j] = 'Q';
                bool isAllQueenPlaced = NQueen(i+1); 
                //try to find out whether possible to place N queens if ith queen is placed on jth column of ith row.
                if(isAllQueenPlaced) return true;
                board[i][j] = '.'; //not possible then backtrack
            }  
        }
        return false;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        num = n;
        board.resize(n,vector<char>(n,'.'));
        NQueen(0);
        return ans;     
    }
};