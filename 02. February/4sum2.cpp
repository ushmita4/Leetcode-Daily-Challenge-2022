class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int,int> freq;
        for(int k : nums3)
            for(int l : nums4)
                freq[k+l]++;
        int c=0;
        for(int k : nums1)
            for(int l : nums2)
                c=c+freq[-(k+l)];
        
        return c;
    }
};
