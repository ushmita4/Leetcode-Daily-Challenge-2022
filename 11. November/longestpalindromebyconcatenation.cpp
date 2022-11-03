class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        bool flag=false;
        int ans=0;
        
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        
        for(auto it:words)
        {
            string temp=it;
            reverse(temp.begin(),temp.end());
            if(temp!=it && mp[temp]>0 && mp[it]>0)
            {
                mp[temp]--;
                mp[it]--;
                ans+=4;
            }
              else if(temp==it && mp[it]>1)
            {
                mp[it]-=2;
                ans+=4;
            }
            else if(temp==it && !flag && mp[it]>0)
            {
                mp[it]--;
                flag=true;
                ans+=2;
            }
        }
       return ans; 
    }
};
