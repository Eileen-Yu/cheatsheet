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

// 2. tabulation (loop) from the last to the begin
class Solution {
public:
  // dp[i][0/1] represents the accumulative max profit we can make on the i-th
  // day if we buy / not buy the stock
  vector<vector<int>> dp;

  int maxProfit(vector<int> &prices, int fee) {
    int n = prices.size();
    // i's range: 0 ~ n (actually would only involve 0 ~ n-1, dp[n] is the base
    // case) init the dp so that ensure dp[n][0/1] = 0;
    dp.resize(n + 1, vector<int>(2, 0));

    // for each day, try each case (buy / not buy / move on)
    // trick: start from the last day
    for (int idx = n - 1; idx >= 0; idx--) {
      // try buy / sell
      for (int canBuy = 1; canBuy >= 0; canBuy--) {
        int buy = INT_MIN, sell = INT_MIN;
        // 1. try buy
        if (canBuy)
          buy = -prices[idx] + dp[idx + 1][!canBuy];
        // 2. try sell
        else
          sell = prices[idx] - fee + dp[idx + 1][!canBuy];
        // 3. try nothing happen
        int move = dp[idx + 1][canBuy];

        // fill in the table for this day
        dp[idx][canBuy] = max({buy, sell, move});
      }
    }

    // canBuy = true on the first day
    return dp[0][1];
  }
};
