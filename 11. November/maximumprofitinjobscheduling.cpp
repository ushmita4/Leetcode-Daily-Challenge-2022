class Solution {
public:
    map<int, int> dp;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<tuple<int, int, int>> jobs;
        for(int i=0; i<n; i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        
        sort(jobs.begin(), jobs.end());
        return calc(0, jobs, n);
    }

    int calc(int i, vector<tuple<int, int, int>>& jobs, int n){
        if(i >= n)
            return 0;

        if(dp.count(i) == 1) 
            return dp[i];

        auto [start, end, profit] = jobs[i];
       
        int next = i+1;
        while(next<n && get<0>(jobs[next]) < end)
            next++;

        
        return dp[i] = max(calc(i+1, jobs, n), profit + calc(next, jobs, n));
    }
};
