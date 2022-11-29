class RandomizedSet {
public:
   unordered_map<int,int> m;
   vector<int> v;
    RandomizedSet() {
    }
    bool insert(int val) {
        if(m[val]==0){  
            m[val]++;
            v.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(m[val]==1){  
            m.erase(val);
            for(int i=0;i<v.size();i++){
                if(v[i]==val){
                    v.erase(v.begin()+i);
                }
            }
            return true;
        }
        return false;
    }
    int getRandom() {
       return v[rand() % v.size()];  
    }
};
