class Solution {
public:

    bool dfs(vector<vector<char>>&board,string word,vector<vector<bool>>&vis,int stind,int i,int j){
        if(stind>=word.size())return true;
        if(i>=board.size() || j>=board[0].size() || i<0 || j<0){
            return false;
        }
        if(word[stind]!=board[i][j] || vis[i][j]==true){
              return false;
        }
        vis[i][j]=true;

        bool val = dfs(board,word,vis,stind+1,i+1,j);
        if(val)return true;
        val = dfs(board,word,vis,stind+1,i-1,j);
        if(val)return true; 
        val = dfs(board,word,vis,stind+1,i,j+1);
        if(val)return true; 
        val = dfs(board,word,vis,stind+1,i,j-1);
        if(val)return true;

        vis[i][j] =  false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    bool val=dfs(board,word,vis,0,i,j);
                    if(val==true){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
