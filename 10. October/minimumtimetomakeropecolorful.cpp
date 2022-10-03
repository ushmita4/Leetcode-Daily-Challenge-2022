class Solution {
public:
     int minCost(string colors, vector<int>& time) {
    
    int i=0,n=colors.length();
    if(n<2)
        return 0;
     int ans=0; 
    
    while(i<n-1)
    {
        if(colors[i]==colors[i+1])
        {
            int sum=0,keep=-1;
            
            while(colors[i]==colors[i+1] && i<n-1)
            {
                sum+=time[i];
                keep=max(keep,time[i]);
                i++;
            }
            sum+=time[i];
            keep=max(keep,time[i]);
            ans+=sum-keep;
        }
        else
            i++;
    }
    return ans;
    
}
};
