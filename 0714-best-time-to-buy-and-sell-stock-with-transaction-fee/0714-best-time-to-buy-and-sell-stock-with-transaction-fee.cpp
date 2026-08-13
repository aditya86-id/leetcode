class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0;
        int hold = -prices[0];

        for (int i = 1; i < prices.size(); i++) {
            int oldCash = cash;
            int oldHold = hold;

            cash = max(oldCash, oldHold + prices[i] - fee);
            hold = max(oldHold, oldCash - prices[i]);
        }

        return cash;
    }
};