const int mod = 1e9 + 7;
class Solution {
    int solve(int n, int k, int target, vector<vector<int>> &memo){
        
        if(n == 0){
            if(target == 0)
                return 1;
            return 0;
        }
        
        if(memo[n][target] != -1)
            return memo[n][target];
        
        int ways = 0;
        for(int i = 1; i <= min(k, target); i++){
            ways = (ways + solve(n-1, k, target-i, memo)) % mod;
        }
        return memo[n][target] = ways;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> memo(n+1 , vector<int>(target+1, -1));
        return solve(n, k, target, memo);
    }
};
