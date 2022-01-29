class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int ans = 0;
        int n = heights.size();
        
        stack<int> S;
        
        for(int i=0; i<n; i++)
        {
            while(!S.empty())
            {
                int j = S.top();
                
                if(heights[j] > heights[i])
                {
                    S.pop();
                    
                    int ls = 0, rs = i-1;
                    
                    if(!S.empty())
                        ls = S.top()+1;
                    
                    int area = (rs - ls + 1)*heights[j];
                    
                    ans = max(ans, area);
                } 
                else
                    break;
            }
            
            S.push(i);
        }
        
        while(!S.empty())
        {
            int j = S.top();
            S.pop();
            
            int ls = 0, rs = n-1;
            
            if(!S.empty())
                ls = S.top()+1;
            
            int area = (rs - ls + 1)*heights[j];
            
            ans = max(ans, area);
        }
        
        return ans;
    }
};
