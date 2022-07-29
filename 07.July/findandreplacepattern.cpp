class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
         int n=words.size();
        vector<map<char,char>> m(n);
        
        for(int i =0 ; i<n; ++i){
          set<int>s ;
            for(int j=0;j<words[i].size();++j){
              if(s.find(pattern[j])==s.end()){
                  s.insert(pattern[j]);
                m[i][words[i][j]]=pattern[j];
            }
        }
        }
        vector<string> ans;
        for(int i=0;i<n;++i){
            string k=words[i];
            for(int j=0; j<words[i].size();++j){
                  words[i][j]=m[i][words[i][j]];
            }
            if(words[i]==pattern){
                ans.push_back(k);
            }
        }
        return ans;
         
    }
};
