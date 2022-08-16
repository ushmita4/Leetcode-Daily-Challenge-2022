class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> ch(26);
        for(int i=0;i<s.size();i++){
            ch[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(ch[s[i]]==1)
                return i;
        }
        return -1;
    }
};
