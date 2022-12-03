class Solution {
public:

    struct alpha{
        char c;
        int n;
    };
    string frequencySort(string s) {
        vector<char> ss;
        set<char> set_s;
       for(int i = 0; i <s.size(); i++){
            set_s.insert(s[i]);
        }
        alpha arr[set_s.size()];
        int i = 0;
         for(auto& str: set_s){
                int count = 0; 
                arr[i].c = str;
                for(int j = 0; j <s.size(); j++){
                    if(str == s[j]){
                        count++;
                    }
                }
            arr[i].n = count;
                i++;
            }

       for (int i = 0; i < set_s.size() - 1; i++){
            for (int j = 0; j < set_s.size() - i - 1; j++){
                if (arr[j].n < arr[j + 1].n){
                    swap(arr[j], arr[j + 1]);
                }
            }
       }
       int x = 0;
       for (int i = 0; i < set_s.size(); i++){
           for (int j = 0; j < arr[i].n; j++){
               s[x] = arr[i].c;
               x++;
           }
       }
        return s;
    }
};
