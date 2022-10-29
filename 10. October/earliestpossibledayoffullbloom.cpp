class Solution {
public:
   int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) 
    {
       std::vector<std::pair<int,int>> arr;
        arr.reserve(plantTime.size());
       for(int i = 0; i < growTime.size(); ++i)
           arr.push_back({plantTime[i], growTime[i]});

    std::sort(arr.begin(), arr.end(), [](std::pair<int, int> a, std::pair<int, int>b ){return  a.second > b.second;});
       int ans = 0;
       int days = 0;
       for(int i = 0; i < arr.size(); ++i)
       {
           days += arr[i].first;
           ans = std::max(ans, arr[i].second + days);
           
       }
       
       return ans;
    }
};
