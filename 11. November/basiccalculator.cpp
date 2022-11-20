class Solution {
public:
    int calculate(string s) {
        int ans = 0  , n = 0 , sign = 1;
        stack<int>st;
        for(char i : s){
            if(isdigit(i)){
                n = 10 * n + (i - '0');
            }
            else if (i == '+'){
                ans += sign * n ;
                n = 0 , sign = 1;
            }
            else if (i == '-'){
                ans += sign * n ;
                n = 0 ;
                sign = -1;
            }
            else if (i == '('){
                st.push(ans);
                st.push(sign);
                sign = 1;
                ans = 0;
            }else if (i == ')'){
                ans += sign * n;
                n = 0;
                ans *= st.top(); st.pop();
                ans += st.top(); st.pop();
            }
        }
        if(n != 0)ans += sign *n;
        return ans;
           
    }
};
