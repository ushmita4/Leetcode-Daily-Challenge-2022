class Solution {
public:
    char findTheDifference(string s, string t) {
        char c=0;
       for(int i=0;i<s.size();i++) 
           c=c^s[i];
       for(int i=0;i<t.size();i++) 
           c=c^t[i]; 
        
        return c;
    }
};
