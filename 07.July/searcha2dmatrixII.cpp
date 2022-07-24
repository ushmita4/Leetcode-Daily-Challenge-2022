class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int R = matrix.size();        
        int C = matrix[0].size();  
        int i = 0 , j = C - 1;           
        while(i < R && j >= 0)
        {
            if(matrix[i][j] == target)  
                return true;
            else if(matrix[i][j] < target)     
                i ++;
            else                   
                j --;
        }
        return false;       
    }
};
