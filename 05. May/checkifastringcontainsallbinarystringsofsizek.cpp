class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<=k)return 0;
        int temp=0;
        bool map[1<<k];
        memset(map,0,sizeof(map));
        
		//itrating for creating window
		
        for(int i=0;i<k-1;i++){
            temp<<=1;
            if(s[i]=='1')temp|=1;
        }
        
        int mask=(1<<k);
        mask--;
        
			//sliding window of k size
		
        for(int i=k-1;i<s.size();i++){
            temp<<=1;
            if(s[i]=='1')temp|=1;
            temp &= mask;
            map[temp]=true;
        }
        
        for(int i=0;i<=mask;i++){
            if(!map[i])
                return false;
        }
        return true;
    }
};
//fast I/O
static const int _____=[]()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
