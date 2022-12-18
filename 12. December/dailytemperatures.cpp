class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        
        vector<int> v;
        stack<pair<int,int>> s;
        
        for(int i=arr.size()-1;i>=0;i--){
            if(s.empty()){
                v.push_back(i);
            }
            else if(!s.empty() && s.top().first>arr[i]){
                v.push_back(s.top().second);
            }
            else if(!s.empty() && s.top().first<=arr[i]){
                while(!s.empty() && s.top().first<=arr[i]){
                    s.pop();
                }
                if(s.empty()){
                    v.push_back(i);
                }
                else{
                    v.push_back(s.top().second);
                }
            }
            s.push({arr[i],i});
        }
        
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            v[i]=-i+v[i];
        }

        return v;
    }
};
