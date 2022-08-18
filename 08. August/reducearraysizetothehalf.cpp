class Solution {
public:
    int minSetSize(vector<int>& arr) {
       map<int,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        int n=arr.size(),n2=arr.size(),ans=0;
        vector<int> v;
        for(auto i:m){
            v.push_back(i.second);
        }
        sort(v.begin(),v.end());
        for(int i=v.size()-1;i>=0;i--){
            n2-=v[i];
            if(n2<=(n/2)){
                ans=ans+1;
                break;
            }
            else
                ans++;
        }
        return ans;
    }
};
