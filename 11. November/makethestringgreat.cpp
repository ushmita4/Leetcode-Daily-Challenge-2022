class Solution {
public:
    string makeGood(string s) 
    {
        stack<char> stk;
        
        int n = s.size();
        
        for(int i=0; i<n; i++)
        {
            char ch = s[i];
            
            if(stk.size() == 0)
            {
                stk.push(ch);
            }
            
            else if(abs(ch - stk.top()) == 32)
            {
                stk.pop();
            }
            else
            {
                stk.push(ch);
            }
        }
        
        string str ="";
        
        while(!stk.empty())
        {
            str +=stk.top();
            stk.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
