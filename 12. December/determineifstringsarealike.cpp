class Solution {
public:
    bool isVowel(char a)
    {
        if(a=='a'|| a=='A' || a=='e' || a=='E' ||
          a=='o'|| a=='O' || a=='i' || a=='I' ||
          a=='u'|| a=='U' )
            return true;
        
        return false;
    }
    bool halvesAreAlike(string s) {
        int n=s.size();
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(i<n/2)
            {
                if(isVowel(s[i]))
                    count++;
            }
            else
                if(isVowel(s[i]))
                    count--;
        }
        return (count==0);
    }
};
