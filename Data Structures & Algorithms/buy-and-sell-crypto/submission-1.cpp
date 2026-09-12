class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        int l = 0;
        for (int r = 1; r < n; ++r) {
            if (prices[l] < prices[r]) {
                profit = max(profit, prices[r] - prices[l]);
            }
            else l = r;
        }
        return profit;
    }
};
