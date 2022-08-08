class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       int n=nums.size();
        int position,ans=0;
       int dp[n];
       for(int i=0;i<n;i++){
         position=lower_bound(dp,dp+ans,nums[i])-dp;
         dp[position]=nums[i];  
           
           
         if(position==ans)
             ans++;
       }
        return ans;
    }
};
