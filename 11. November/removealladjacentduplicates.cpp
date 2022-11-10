class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack <char> st;
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top() == s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
