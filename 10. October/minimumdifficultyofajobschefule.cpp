class Solution {
public:
    int solve(int index, vector<int>& a,int d,vector<vector<int>>& dp){
        int n = a.size();
        if(d==1){
            int mx = a[index];
            for(int i=index;i<n;i++){
                mx = max(mx,a[i]);
            }
            return mx;
        }
        if(dp[index][d]!=-1) return dp[index][d];
        int mx = INT_MIN;
        int ans = INT_MAX;
        for(int i=index;i<=n-d;i++){
            mx= max(mx,a[i]);
            ans = min(ans,mx + solve(i+1,a,d-1,dp));
        }
        return dp[index][d] = ans;

    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n<d) return -1;
        vector<vector<int>> dp(n+1,vector<int>(d+1,-1));
        return solve(0,jobDifficulty,d,dp);
    }
};
