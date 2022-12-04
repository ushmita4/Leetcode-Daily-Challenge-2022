class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();

        vector<long> right(n);

        for(int i = n-1;i>0;i--){
            right[i-1] = right[i] + nums[i];
        }

        long val = 0;
        int minVal = INT_MAX;
        int idx = -1;
        for(int i = 0;i<n;i++){
            val+=nums[i];
            float diff;
            if(i != n-1)
                diff = abs(val/(i+1) - right[i]/(n-i-1));
            else
                diff = abs(val/(i+1));
            if(diff < minVal){
                idx = i;
                minVal = diff;
            }
        }

        return idx;
    }
};
