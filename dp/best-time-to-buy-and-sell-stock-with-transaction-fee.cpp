// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
// dp
// 1. memoization (recursion)
class Solution {
public:
  // dp[i][0(false)/1(true)] represents the max profit we can get
  // if we choose to buy/not buy the stock on the i-th day
  vector<vector<int>> dp;

  int recursion(vector<int> &prices, bool canBuy, int idx, int fee) {
    int n = prices.size();
    // already to the end
    if (idx == n)
      return 0;
    // if already filled up the dp
    if (dp[idx][canBuy] != INT_MIN)
      return dp[idx][canBuy];

    // for each day, we have 3 choices:
    // buy / sell / no action
    // we recursion for each one and pick the most optimized one

    // ensure that the buy / sell won't affect the result when we aren't allowed
    // to buy/sell
    int buy = INT_MIN, sell = INT_MIN;
    // 1. choose buy
    if (canBuy) {
      buy = -prices[idx] + recursion(prices, false, idx + 1, fee);
    } else { // 2. choose sell
      sell = prices[idx] - fee + recursion(prices, true, idx + 1, fee);
    }
    // 3. choose not to do anything on this day
    int move = recursion(prices, canBuy, idx + 1, fee);

    // we pick the most optimized choice for this day
    return dp[idx][canBuy] = max({buy, sell, move});
  }

  int maxProfit(vector<int> &prices, int fee) {
    int n = prices.size();
    // i's range: 0~n-1
    // [[INT_MIN(cannotBuy = 0), INT_MIN(canBuy = 1)], [....]]
    dp.resize(n, vector<int>(2, INT_MIN));
    return recursion(prices, true, 0, fee);
  }
};
