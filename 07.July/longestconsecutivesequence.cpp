class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int maxi=0,temp=0,n1;
        
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        for(int i=0;i<n;i++){
            temp=nums[i]-1;
            if(s.find(temp)==s.end()){
                n1=nums[i];
                while(s.find(n1)!=s.end()){
                    n1++;
            }
                maxi=max(maxi,n1-nums[i]);
            }
            
        }
        return maxi;
    }
};
