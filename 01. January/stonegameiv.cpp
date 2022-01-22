class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, false);
        for(int i=0; i<n+1; i++){
            if(dp[i]) continue;
            for(int j=1; i+j*j<n+1; j++)
                dp[i+j*j]=true;
        }
        return dp[n];
    }
};
