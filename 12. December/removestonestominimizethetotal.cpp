class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
      priority_queue<int> pq(piles.begin(),piles.end());
      int sum=accumulate(piles.begin(),piles.end(),0);
      int curr,remove;
       for(int i=0;i<k;i++){
           curr=pq.top();
           pq.pop();
           remove=curr/2;
           sum-=remove;
           pq.push(curr-remove);
       }
       return sum;
    }
};
