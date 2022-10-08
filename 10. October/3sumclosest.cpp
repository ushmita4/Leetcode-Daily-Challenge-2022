class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int closest_dif = INT_MAX;
        int closest_sum = 0;
        for(int k=0;k<n-2;k++) {
            int i = k+1,j = n-1;
            while(i<j) {
                int cur_sum = nums[i]+nums[j] + nums[k];
                int dif = abs(cur_sum - target);
                if( dif < closest_dif ) {
                    closest_dif = dif;
                    closest_sum = cur_sum;
                }
                if(cur_sum > target) j--;
                else i++;
            }
            
        }
        
        return closest_sum;
    }
};
