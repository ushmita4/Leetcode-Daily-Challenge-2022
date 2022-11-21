class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(),m = maze[0].size(),ans = 0;

        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';


        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size;i++){
                auto cur = q.front();
                q.pop();


                if(cur.first == 0 || cur.first == n-1 || cur.second == 0 || cur.second  == m-1){
                   if(ans != 0){
                       
                        return ans;
                   }
                   
                }

                int dxdy[][2] = {{0,-1},{-1,0},{0,1},{1,0}};

                for(int j = 0;j<4;j++){
                    int x = cur.first + dxdy[j][0];
                    int y = cur.second  + dxdy[j][1];

                    if(x>=0 && y>=0 && x<n && y<m && maze[x][y]!='+'){
                        q.push({x,y});
                        maze[x][y] = '+';
                    }

                }
            }
            ans ++;
        }

      
        return -1;

    }

};
