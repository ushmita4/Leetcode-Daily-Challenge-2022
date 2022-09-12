class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
       
        sort(tokens.begin(), tokens.end());
       
        int l = 0, r = tokens.size() - 1;
        int cur_score = 0, mx_score = 0;
        while (l <= r) {
            
            if (tokens[l] <= power) {
                
                power -= tokens[l];
              
                cur_score += 1;
               
                mx_score = max(mx_score, cur_score);
               
                l += 1;
            } else if (cur_score >= 1) {
               
                power += tokens[r];
               
                cur_score -= 1;
                
                r -= 1;
            } else {
               
                break;
            }
        }
        return mx_score;
    }
};
