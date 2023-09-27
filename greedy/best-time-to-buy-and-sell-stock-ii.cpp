// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
// * this problem ensures we can buy & sell at the same time
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int ans = 0;

    for (int i = 1; i < prices.size(); i++) {
      // only when we can get profit, we make the deal
      int diff = prices[i] - prices[i - 1];
      if (diff > 0)
        ans += diff;
    }

    return ans;
  }
};
