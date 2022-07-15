class Solution {
    int get_max(vector<vector<int>>&grid, int r, int c){
        if(r<0 or c<0 or r==grid.size() or c==grid[r].size() or grid[r][c]==0) return 0;
        grid[r][c]=0;
        return 1 + get_max(grid,r-1,c) + get_max(grid,r,c+1) + get_max(grid,r+1,c) + get_max(grid,r,c-1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0; i<grid.size(); ++i)
            for(int j=0; j<grid[i].size(); ++j)
                if(grid[i][j])
                    res = max(res, get_max(grid, i, j));
        return res;
    }
};
