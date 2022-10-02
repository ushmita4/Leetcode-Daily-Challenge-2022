class Solution {
public:
    //6
    // 2,6, 26
    // 2,2,6, 2,26, 22,6
    int numDecodings(string s) {
        
        int n = s.length();
        int dp[n+1];
        memset(dp, 0, sizeof dp);
        dp[n] = 1;
        dp[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            if(s[i+1] != '0')
            dp[i] += dp[i+1];
            if(s[i] != '0'){
                string number = "";
                number += s[i];
                number += s[i+1];
                int letter = stoi(number);
                if(letter <= 26){
                    if(s[i+2] != '0')
                    dp[i] += dp[i+2];
                }   
            }
        }
        if(s[0] == '0')return 0;
        
        return dp[0];
    }
};

