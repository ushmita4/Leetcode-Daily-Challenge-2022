class Solution {
public:
    int maximum69Number (int num) {
        vector<int> digits;
        while (num){
            digits.push_back(num % 10);
            num /= 10;
        }
        for (int i = digits.size() - 1; i >= 0; --i){
            if (digits[i] != 9){
                digits[i] = 9;
                break;
            }
        }
        int result = 0;
        for (int i = digits.size() - 1; i >= 0; --i){
            result = result * 10 + digits[i];
        }
        return result;
    }
};
