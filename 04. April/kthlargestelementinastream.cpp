class KthLargest {
public:
    // we will use priority queue because we kth largest element
    // so for that we will remove the startting element till there is k element remains
    // and when we have only k element it means queue top is our answer
    
    priority_queue<int,vector<int>,greater<int>> pq;      // it will take the bigger values at the top
    int size;                                   // it will store the kth value globally
    
    KthLargest(int k, vector<int>& nums) 
    {
        size = k;          // assigning k to size so we can use it in other functions also
        
        // pushing all values in our queue
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
            
            // if it exceed our k value then pop the bigger value
            // because we need to return only the kth value not the all bigger values till k
            if(pq.size()>k)
                pq.pop();
        }
    }
    
    int add(int val) 
    {
        // push val into the queue
        pq.push(val);
        
        // pop queue adding one element 
        // because it will exceed our k size
        if(pq.size()>size)
            pq.pop();
        
        return pq.top();          // our kth largest value after inserting val
    }
};
