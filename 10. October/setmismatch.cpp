class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int res1=0;
        map<int,int> mp;
        int sum=0;
        int sum2=n*(n+1)/2;
       for(int i=0;i<n;i++)
       {
           mp[nums[i]]++;
           sum=sum+nums[i];
           if(mp[nums[i]]==2)
           {               
               sum=sum-nums[i];
               res1=nums[i];
           }
       } 
        vector<int> result(2);
        result[0]=res1;
        result[1]=sum2-sum;
        
        return result;
    }
};
