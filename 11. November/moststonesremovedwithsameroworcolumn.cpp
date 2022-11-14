class Solution {
public:

    int dfs(int node,vector<vector<int>> &a,int ans,vector<bool> &vis){
        vis[node] = true;
        int l=0;
        for(auto &i : a[node]){
            if(!vis[i])l+=dfs(i,a,ans,vis);
        }
        ans+=l;
        ans++;
        return ans;
    }

    int removeStones(vector<vector<int>>& stones) {
        int N = stones.size();
        vector<vector<int>> a(N);
        for(int i=0; i<stones.size(); ++i){
            for(int j=0; j<stones.size();++j){
                if(i==j) continue;
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    a[i].push_back(j);
                    a[j].push_back(i);
                }
            }
        }
        int flag = 0;
        vector<bool> vis(N,false);
        for(int i=0; i<N; ++i){
            flag +=(dfs(i,a,0,vis))-1;
        }
        return flag;
    }
};
