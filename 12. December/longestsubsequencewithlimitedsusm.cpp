class Solution 
{
public:
   vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        int n=nums.size();
        int m=q.size();
        sort(nums.begin(),nums.end());
        
        vector<int> v;
        
        vector<int> pre(n+1,0);
        for(int i=1;i<n+1;i++)
        {
            pre[i]=pre[i-1]+nums[i-1];
        }
                                      
        for(int i=0;i<m;i++)
        {
            int sum=q[i];
            auto  z=lower_bound(pre.begin(),pre.end(),sum)-pre.begin();
            if(z<n+1)
            {
                if(pre[z]==sum)
                    v.push_back(z);
                else 
                    v.push_back(z-1);
            }
            else if(z==n+1)
                v.push_back(n);
        }
        return v;
    }
};
