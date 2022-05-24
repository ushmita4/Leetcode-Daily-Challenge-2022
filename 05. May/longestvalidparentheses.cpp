class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0;
        int ans = 0;
        
        for(const char &ch : s) {
            open += ch == '(' ? 1 : 0;
            close += ch == ')' ? 1 : 0;
            
            if(open == close) {
                ans = max(ans, open * 2);
            } 
            else if(close > open) {
                close = 0;
                open = 0;
            }
        }

        open = close = 0;
        for(int i = s.length() - 1; i >= 0; --i) {
            char ch = s[i];
            open += ch == '(' ? 1 : 0;
            close += ch == ')' ? 1 : 0;
            
            if(open == close) {
                ans = max(ans, open * 2);
            } 
            else if(close < open) {
                close = 0;
                open = 0;
            }
        }
        
        return ans;
    }
};
