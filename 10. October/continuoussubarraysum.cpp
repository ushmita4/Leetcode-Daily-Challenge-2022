class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long long int pre=0 ;
        unordered_map<int,int> hash ;
        hash[0]=-1 ;
        
        for(int i=0 ; i<nums.size() ; i++)
        {
            pre += nums[i] ;
            if( hash.find(pre%k) != hash.end())
            {
                if(i - hash[pre%k] > 1 )  return true ;
            }
            else   hash[pre%k] = i ;
        }
        return false ;
    }
};
