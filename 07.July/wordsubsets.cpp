class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> v(26, 0);
        for(string w: words2) {
            vector<int> temp(26, 0);
            for(char c: w) temp[c-'a']++;
            for(int k=0; k<26; ++k) v[k] = max(v[k], temp[k]);
        }
        for(string w: words1) {
            vector<int> temp(26, 0);
            for(char c: w) temp[c-'a']++;
            int k = 0;
            for(; k<26; ++k) if(temp[k]<v[k]) break;
            if(k==26) ans.push_back(w);
        }
     return ans;
    }
};
