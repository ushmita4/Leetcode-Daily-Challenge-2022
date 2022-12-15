class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> DP(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i{1}; i <= text1.size(); i++) { 
            for (int j{1}; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    DP[i][j] = DP[i - 1][j - 1] + 1;
                } else { 
                    DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
                }
            }
        }
        return DP.back().back(); 
    }
};
