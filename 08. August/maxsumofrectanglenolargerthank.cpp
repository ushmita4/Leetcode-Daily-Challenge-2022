class Solution {
public:
    int subarray_sum(vector<int> &nums , int k)
    {
        set<int> st;
        
        st.insert(0);
       
        int sum=0;
        
        int res=INT_MIN;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            auto it=st.lower_bound(sum-k);
            
            if(it!=st.end())
            {
                int v=*it;
                int d=sum-v;
                res = max(res , d);
            }
            
            st.insert(sum);
        }
        
        return res;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        
        int m=mat.size();
        int n=mat[0].size();
        
        vector<int> nums(n , 0);
        
        int ans=INT_MIN;
        
        for(int i=0;i<m;i++)
        {
            fill(nums.begin() , nums.end() , 0);
            for(int j=i;j>=0;j--)
            {
                for(int k=0;k<n;k++)
                {
                    nums[k]+=mat[j][k];
                }
                
                int res=subarray_sum(nums , k );
                
                if(res==k)
                {
                    return res;
                }
                
                ans=max(res , ans);
            }
        }
        
        return ans;
    }
};
