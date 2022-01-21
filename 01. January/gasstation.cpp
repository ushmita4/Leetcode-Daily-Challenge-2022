class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = 0;
        int exgas = 0;
        int regas = 0;
        int n = gas.size();
        for(int i=0;i<n;i++){
            exgas += (gas[i] - cost[i]);
            if(exgas < 0){
                res = i+1;
                regas += exgas;
                exgas = 0;
            }
        }
        
        if(regas+exgas >= 0) return res;
        return -1;
    }
};
