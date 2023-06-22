// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// 1. dp
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int minVal = INT_MAX;
    int ans = 0;

    for (auto i : prices) {
      // find the min value untill now
      minVal = min(minVal, i);
      // find the max profit until now
      ans = max(ans, i - minVal);
    }

    return ans;
  }
};
// 2. palin one, would TLE
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int ans = 0;

    for (int i = 0; i < prices.size() - 1; i++) {
      for (int j = i + 1; j < prices.size(); j++) {
        if (prices[j] > prices[i])
          ans = max(ans, prices[j] - prices[i]);
      }
    }

    return ans;
  }
};
