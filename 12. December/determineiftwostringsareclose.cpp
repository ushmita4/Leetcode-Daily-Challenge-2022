class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_set<char> s1;
        for(auto it:word1) s1.insert(it);
        for(auto it:word2)
            if(s1.count(it)==0) return 0;
        vector<int> m1(26),m2(26);
        for(auto i:word1) m1[i-'a']++;
        for(auto j:word2) m2[j-'a']++;
        sort(m1.begin(),m1.end(),greater<>());
        sort(m2.begin(),m2.end(),greater<>());
        for(int i=0;i<26;i++)
            if(m1[i]!=m2[i]) return 0;
        return 1;
       
    }
};
