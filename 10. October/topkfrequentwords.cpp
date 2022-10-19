class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        map<string, int>word_db;
        int words_size= words.size();
        for(int i=0; i<words_size; i++){
            word_db[words[i]]++;
        }

        priority_queue<pair<int, string>>top_k;
        for(auto &it: word_db){
            top_k.push(make_pair(-it.second, it.first));
            if(top_k.size() > k){
                top_k.pop();
            }
        }

        vector<pair<int, string>>candidate_list;
        while(!top_k.empty()){
            candidate_list.emplace_back(top_k.top());
            top_k.pop();
        }
        sort(candidate_list.begin(), candidate_list.end());

        vector<string>ans;
        for(int i=0; i<candidate_list.size(); i++){
            ans.push_back(candidate_list[i].second);
        }
        return ans;
    }
};
