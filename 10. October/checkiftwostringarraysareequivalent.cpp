class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
     auto nw1=reduce(word1.begin(),word1.end());
     auto nw2=reduce(word2.begin(),word2.end());
        
    return nw1==nw2;
    }
};
