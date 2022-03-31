class Solution {
public:
	bool ispossible(vector<int> &nums,int curr,int m){
		int total=1;
		int sum=0;
		for(int i=0;i<nums.size();i++){
		   sum+=nums[i];
		   if(sum>curr){
			   sum=nums[i];
			   total++;
		   }
			if(nums[i]>curr) return false;
		}
		return total<=m;
	}
	int splitArray(vector<int>& nums, int m) {
		 int low=*min_element(nums.begin(),nums.end());
		 int high=accumulate(nums.begin(),nums.end(),0);
		 int ans=low;
		 while(low<=high){
			 int curr=(low+high)/2;
			 if(ispossible(nums,curr,m)){
				 ans=curr;
				 high=curr-1;
			 }
			 else
				 low=curr+1;
		 }
		return ans;
	}
};
