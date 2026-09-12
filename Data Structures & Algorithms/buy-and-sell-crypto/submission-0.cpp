class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        for (int l = 0; l < n; ++l) {
            for (int r = l; r < n; ++r) {
                profit = max(profit, prices[r] - prices[l]);
            }
        }
        return profit;
    }
};
