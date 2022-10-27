class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int maxCount=0;
       
        int n=img2.size();
        vector<vector<int>>paddedImg2 = vector<vector<int>>((3*n-2),vector<int>((3*n-2)));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                paddedImg2[i+n-1][j+n-1]= img2[i][j];
            }
        }
       
        for(int xshift=0; xshift<=2*(n-1); xshift++){
            for(int yshift=0; yshift<=2*(n-1); yshift++){
                int count=0;           
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        count += (img1[i][j] & paddedImg2[i+xshift][j+yshift]);
                    }
                }
                maxCount=max(count,maxCount);
            }
        }
        return maxCount;
    }
};
