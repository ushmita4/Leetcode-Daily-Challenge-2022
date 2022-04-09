class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
   
    vector<int> v;
    unordered_map<int, int> m;
    
    for(auto num: nums){
        m[num]++;
    }
    
    priority_queue<pair<int,int>> q;
    for(auto val: m){
        q.push({val.second, val.first});
    }
    
    while(k--){
        v.push_back(q.top().second);
        q.pop();
    }
    
    return v;
}
};
