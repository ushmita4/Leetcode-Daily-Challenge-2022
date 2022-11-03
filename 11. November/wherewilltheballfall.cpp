class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int mark[m][n][2];
        const int LEFT = 0;
        const int RIGHT = 1;
        memset(mark, -1, sizeof(mark));

        for(int j=0; j<n; j++){
            int leftOrRightSegment = (grid[0][j] == 1)? RIGHT : LEFT;
            mark[0][j][leftOrRightSegment] = j;
        }
        
        for(int i=0; i<m; i++) {
          
            for(int j=0; j<n; j++) {
                if(i>0) {
                    if(grid[i][j] == grid[i-1][j]) {
                        if(grid[i][j] == 1)
                            mark[i][j][RIGHT] = mark[i-1][j][LEFT];
                        else
                            mark[i][j][LEFT] = mark[i-1][j][RIGHT];
                    } else {
                        if(grid[i][j] == 1)
                            mark[i][j][RIGHT] = mark[i-1][j][RIGHT];
                        else
                            mark[i][j][LEFT] = mark[i-1][j][LEFT];
                    }
                }
            }
          
            for(int j=0; j<n; j++) {
                if(j>0) {
                  
                    if(grid[i][j] == grid[i][j-1] && grid[i][j] == 1)
                        mark[i][j][LEFT] = mark[i][j-1][RIGHT];
                }
                if(j<n-1) {
                 
                    if(grid[i][j] == grid[i][j+1] && grid[i][j] == -1)
                        mark[i][j][RIGHT] = mark[i][j+1][LEFT];
                }
            }
        }

        vector<int> ans(n, -1);
        for(int j=0; j<n; j++){
            int ball = -1;
            if(mark[m-1][j][RIGHT] != -1 && grid[m-1][j] == -1) 
                ball = mark[m-1][j][RIGHT];
            else if(mark[m-1][j][LEFT] != -1 && grid[m-1][j] == 1) 
                ball = mark[m-1][j][LEFT];

            if(ball != -1) ans[ball] = j;
        }

        return ans;
    }
};
