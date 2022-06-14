class Solution {
public:
    
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        
   int L[m + 1][n + 1];
 
  
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
 
            else if (word1[i - 1] == word2[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
 
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
 
   
    return (m-L[m][n])+(n-L[m][n]);
        
        
    }
};
