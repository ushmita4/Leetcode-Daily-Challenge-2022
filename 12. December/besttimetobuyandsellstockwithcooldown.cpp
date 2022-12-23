class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        int buy = -prices[0], sell = 0, rest = 0, preBuy, preSell;
        for(int i = 1; i < n; i++){
            preBuy = buy;
            preSell = sell;
            buy = max(buy, rest - prices[i]);
            sell = max(sell, preBuy + prices[i]);
            rest = max(rest, preSell);
        }
        return max(rest, sell);
    }
};
