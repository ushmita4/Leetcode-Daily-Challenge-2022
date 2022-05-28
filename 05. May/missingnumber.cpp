class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l=nums.size();
        int sum=(l*(l+1))/2;
        int sum2=0;
        for(int i=0;i<l;i++){
            sum2=sum2+nums[i];
        }
        return (sum-sum2);
    }
};
