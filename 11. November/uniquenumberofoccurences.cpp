class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {



        set <int> s;
        vector <int> v;
        unordered_map<int,int>m;
        for(int i = 0 ; i<arr.size() ; i++)
        {
            m[arr[i]]++;

        }
        for(auto x:m)
        {
            s.insert(x.second);
            v.push_back(x.second);
        }

        if(s.size() != v.size())
        {
            return false;
        }

        return true;

        
    }
};
