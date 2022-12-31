class Solution {
public:
    int rec(int r1 , int c1 ,vector<vector<int>> &grid , int cnt ,int &empty) // number of path to reach r1,c1 from starting point. ( till now how many cell visited )
    {
        if( r1 < 0 || r1 >= grid.size() || c1 < 0 || c1 >= grid[0].size() || grid[r1][c1]==-1)
        return 0;

        if(grid[r1][c1]==1) // reached start point . 
        {
            if(cnt == empty )
            {
                return 1;
            }
            else 
               return 0;
        }
        grid[r1][c1] = -1; // Alredy node contin in path not exproed again 

        int left = rec(r1,c1-1,grid,cnt+1,empty);
        int right = rec(r1,c1+1,grid,cnt+1,empty); 
        int up = rec(r1-1,c1,grid,cnt+1,empty) ;
        int down = rec(r1+1,c1,grid,cnt+1,empty);

        grid[r1][c1] = 0;
        return left + right + up + down ;

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
         int r2,c2, empty = 0 ;
         int n = grid.size() , m = grid[0].size();
         for( int i = 0 ; i < n ; ++i  )
         {
             for( int j = 0 ; j < m ; ++j )
             {
                 if ( grid[i][j]==0)
                 {
                     ++empty;
                 }
                 else if ( grid[i][j]==2)
                 {   ++empty;
                     r2 = i;
                     c2 = j;
                 }
             }
         }
         int ans = 0;
        
         return rec(r2,c2,grid,0,empty);;
    }
};
