// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
// greedy: use state machine to record the max profit we can get when holding /
// not holding a stock
class Solution {
public:
  int maxProfit(vector<int> &prices, int fee) {
    // record the max if we're not holding a stock
    int buy = 0;
    // record the max if we're holding a stock
    // init it to -1000000 cuz we want to update it on the first buy
    int sell = -1000000;

    for (auto i : prices) {
      // if we don't take action OR we sell the stock
      buy = max(buy, sell + i - fee);
      // if we don't take action OR we buy the stock
      sell = max(sell, buy - i);
    }

    return max(buy, sell);
  }
};
