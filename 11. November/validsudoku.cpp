class Solution {
public:
    bool f(vector<vector<char>>&board,char c,int i,int j){
        for(int k=0;k<9;k++){
            if(k==j) continue;
            if(board[i][k]==c) return false;
        }
         for(int k=0;k<9;k++){
            if(k==i) continue;
            if(board[k][j]==c) return false;
        }  
        int x=i/3*3;
        int y=j/3*3;
        for(int u=x;u<x+3;u++){
            for(int v=y;v<y+3;v++){
                if(u==i && v==j) continue;
                if(board[u][v]==c) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(!f(board,board[i][j],i,j)) return false;
            }
        }
        return true;
    }
};
