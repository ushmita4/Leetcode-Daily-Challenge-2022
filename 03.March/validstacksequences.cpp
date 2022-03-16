class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0;
        for(int x :  pushed)
        {
            pushed[i++] = x;
            // check that current pushed element matches with popped sequence
            while(i> 0 && pushed[i-1] == popped[j])
            {
                --i;
                ++j;
            }
        }
        // as pushed is a permutation of stack so at end it should be empty
        return i == 0;
    }
};
