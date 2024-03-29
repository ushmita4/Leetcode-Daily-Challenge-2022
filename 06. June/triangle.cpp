class Solution {
public:
    int find_path(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    {
        if(i==n-1) return triangle[i][j]; 
        
        if(dp[i][j] != -1) return dp[i][j]; 
        int bottom = triangle[i][j] + find_path(i+1, j, n, triangle, dp); 
        int bottom_right = triangle[i][j] + find_path(i+1, j+1, n, triangle, dp);
        
        
        return dp[i][j] = min(bottom, bottom_right);
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {   
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n,-1)); 
        return find_path(0, 0, n, triangle, dp); 
    }
};
