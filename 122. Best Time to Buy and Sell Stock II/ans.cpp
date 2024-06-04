class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int moneyWithoutStock = 0;
        int moneyWithStock = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            moneyWithStock = max(moneyWithStock, moneyWithoutStock - prices[i]);
            moneyWithoutStock = max(moneyWithoutStock, moneyWithStock + prices[i]);
        }
        return moneyWithoutStock;
    }
};
