class Solution {
public:

    
    int dr[4]={1,0,0,-1};
    int dc[4]={0,1,-1,0};
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
     
        queue<vector<int>> q;
        q.push({0,0,0,k});
        vector<vector<int>> vis(n,vector<int>(m,-1));
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int r = t[0], c = t[1], step = t[2], rem_k = t[3];
           
            if(r==n-1 && c==m-1) return step;
            
            if(vis[r][c]!=-1 && vis[r][c]>=rem_k) continue;
            
            if(grid[r][c]==1){
                if(rem_k>0) rem_k--;
                else continue;
            }
            
            vis[r][c]=rem_k;
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr<0 || nc<0 || nr>=n || nc>=m) continue;
                q.push({nr,nc,step+1,rem_k});
            }
        }
        return -1;
    }
};
