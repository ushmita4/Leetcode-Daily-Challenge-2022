class Solution {
public:
    unordered_map<string, bool> dp;
    bool solve(string s1, string s2, string s3, int i, int j, int k){
        if(i < 0 && j < 0 && k < 0)  return true; 
        string s = to_string(i)+ "_" + to_string(j) + "_" + to_string(k);
        if(dp.find(s) != dp.end()) return dp[s];
        bool res = false;
        if(i >= 0 && k >= 0 && s1[i] == s3[k]) res |= solve(s1, s2, s3, i-1, j, k-1);
        if(j >= 0 && k >= 0 && s2[j] == s3[k]) res |= solve(s1, s2, s3, i, j-1, k-1);
        return dp[s] = res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        return solve(s1, s2, s3, s1.length()-1, s2.length()-1, s3.length()-1);
    }
};
