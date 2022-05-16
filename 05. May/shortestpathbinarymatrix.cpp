class Solution {
public:
    //Use BFS 
    
    bool isValid(int r, int c, int n, vector<vector<int>> &grid, vector<vector<bool>> &visited)
    {
        //check boundary condition and assure cell is not visited
        return (r>=0 && c>=0 && r<n && c<n && grid[r][c]==0 && !visited[r][c]);
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        queue<pair<int, int>> q; //it stores visited cells 
        int ans=0;
        vector<vector<bool>> visited(n, vector<bool> (n, false)); //it stores status of  the cell
        int size;
        
        if(!grid[0][0]) //if starting cell value is 0, put it into the queue
        {
            q.push({0,0});
            visited[0][0] = true;
        }
        
        while(!q.empty())
        {
            size = q.size();
            ans++;
            
            //iterate until we cover all stored cells in the queue 
            for(int cnt=0; cnt<size; cnt++) 
            {
                auto node = q.front(); q.pop();
                int i = node.first, j=node.second; //get row and column of the cell
                
                if(i==n-1 && j==n-1) return ans; //if we reach end cell return ans
                
                //cover all 8-direction adjacent cell
                for(int r=i-1; r<=i+1; r++)
                {
                    for(int c=j-1; c<=j+1; c++)
                    {
                        //if cell is valid means not visited 
                        //put it into the queue and mark visited
                        if(isValid(r, c, n, grid, visited))
                        {
                            q.push({r,c});
                            visited[r][c] = true;
                        }
                    }
                }
            }
        }
        //if there is no path exists return -1
        return -1;
            
    }
};
