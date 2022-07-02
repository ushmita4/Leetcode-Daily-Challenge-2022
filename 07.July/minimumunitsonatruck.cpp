class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0;
        
        sort(begin(boxTypes), end(boxTypes), [&](const vector<int>& v1, const vector<int>& v2){return v1[1] > v2[1];});
            
        for(auto box: boxTypes)
        {
            ans += min(truckSize, box[0]) * box[1];
            truckSize -= min(truckSize, box[0]);
           
        }
        
        return ans;
    }
};
