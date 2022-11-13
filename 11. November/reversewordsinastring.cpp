class Solution {
public:
    string reverseWords(string s) {
        vector<string> ans;
    stringstream str(s);
    string word;
    
    while(str >> word){
        ans.push_back(word);
    }
    
    
    reverse(ans.begin(),ans.end());
    string final = "";
  
    for(auto it : ans){
        final += " " + it;
    }
    
    final.erase(0,1);
    
    return final;
    }
};
