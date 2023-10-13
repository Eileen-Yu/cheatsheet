// https://leetcode.com/problems/min-cost-climbing-stairs/description
// climb step --> simple tabulation
class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    // dp[i] represents the minimum cost to reach the i-th floor
    // i's range: 0 ~ n
    vector<int> dp(n + 1, INT_MAX);
    // base case
    dp[0] = 0;
    dp[1] = 0;

    // loop each floor
    for (int i = 2; i <= n; i++) {
      // 1. if come from 1 step before
      int prev1 = dp[i - 1] + cost[i - 1];
      // 2. if come from 2 steps before
      int prev2 = dp[i - 2] + cost[i - 2];

      // record the minimum cost to reach this floor
      dp[i] = min({dp[i], prev1, prev2});
    }

    return dp[n];
  }
};
