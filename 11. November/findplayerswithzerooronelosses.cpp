class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        int p=100001;
        vector<int>lost(p,0);
        vector<int>win(p,0);
        vector<vector<int>>res(2);
        for(int i=0;i<n;i++)
        {
             lost[matches[i][1]-1]++;
             win[matches[i][0]-1]++;
        }
        for(int i=0;i<p;i++)
        {
            if(lost[i]+win[i]>0&&lost[i]==0)
            res[0].push_back(i+1);
            if(lost[i]+win[i]>0&&lost[i]==1)
            res[1].push_back(i+1);
        }
        return res;
    }
};v
