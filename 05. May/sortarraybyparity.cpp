class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)
                even.push_back(nums[i]);
            else
                odd.push_back(nums[i]);
        }
        for(int i=0;i<even.size();i++){
            result.push_back(even[i]);
        }
        for(int i=0;i<odd.size();i++){
            result.push_back(odd[i]);
        }
        return result;
    }
};
