class Solution {
public:
    int minPartitions(string n) {
       sort(n.begin(),n.end());
        int s=n.size();
        return (n[s-1]-'0');
    }
};
