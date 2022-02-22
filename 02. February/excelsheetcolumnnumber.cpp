class Solution {
public:
    int titleToNumber(string c) {
        int l = c.length();
        long long k=0;
        for(int i=0; i<l; i++)
        {
            k += (c[i]-'A'+1)*(pow(26,l-i-1));
        }
        return k;
    }
};
