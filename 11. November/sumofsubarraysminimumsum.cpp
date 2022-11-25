class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(),mod = 1e9 + 7;
        vector<int> prevLess(n,-1);
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(!st.empty()){
                prevLess[i] = st.top();
            }
            st.push(i);
        }
        
        vector<long long> dp(n,0);
        for(int i=0;i<arr.size();i++){
           dp[i] = arr[i] * 1LL *(i - prevLess[i]);
           if(prevLess[i] != -1) dp[i] += dp[prevLess[i]];
        }
        
        long long ans = 0;
        for(int i : dp){
            ans = (ans + i)% mod;
        }
        return ans;
    }
};
