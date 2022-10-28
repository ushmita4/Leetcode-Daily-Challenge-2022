class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> group;

        for(auto word: strs) {
            string key = word;
            sort(key.begin(), key.end());
            group[key].push_back(word);
        }

        for(auto vec: group) {
            ans.push_back(vec.second);
        }

        return ans;
    }
};
