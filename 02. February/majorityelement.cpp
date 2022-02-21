class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int n = nums.size();
        int  maj = nums[0], cnt = 1;
        
        for(int i=1;i<n;++i)
        {
		    // If next element is same then increments the count, otherwise decrement
            if(nums[i] == maj)
                cnt++;
            else
                cnt--;
            
            if(cnt == 0)
            {
                maj = nums[i];
                cnt = 1;
            }
        }
        return maj;
    }
};
