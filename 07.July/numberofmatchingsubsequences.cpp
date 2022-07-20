class Solution {
public:
    bool help(string s,string word)
    {
        int k=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==word[k])k++;
            if(k==word.size())
                return true;
        }
        return false;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string,int>m;
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            m[words[i]]++;
        }
        for(auto it:m)
        {
            if(help(s,it.first))
                ans+=it.second;
        }
        return ans;
    }
};
